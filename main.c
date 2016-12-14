//*****************************************************************************
// Copyright (C) 2014 Texas Instruments Incorporated
//
// All rights reserved. Property of Texas Instruments Incorporated.
// Restricted rights to use, duplicate or disclose this code are
// granted through contract.
// The program may not be used without the written permission of
// Texas Instruments Incorporated or against the terms and conditions
// stipulated in the agreement under which this program has been supplied,
// and under no circumstances can it be used with non-TI connectivity device.
//
//*****************************************************************************

//*****************************************************************************
//
// Application Name     -   MQTT Client
// Application Overview -   This application acts as a MQTT client and connects
//                          to the IBM MQTT broker, simultaneously we can
//                          connect a web client from a web browser. Both
//                          clients can inter-communicate using appropriate
//                          topic names.
//
// Application Details  -
// http://processors.wiki.ti.com/index.php/CC32xx_MQTT_Client
// or
// docs\examples\CC32xx_MQTT_Client.pdf
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup mqtt_client
//! @{
//
//*****************************************************************************

// Standard includes
#include <stdlib.h>

// simplelink includes
#include "simplelink.h"

// driverlib includes
#include "hw_types.h"
#include "hw_ints.h"
#include "hw_memmap.h"
#include "interrupt.h"
#include "rom_map.h"
#include "prcm.h"
//#include "uart.h"
#include "timer.h"
#include "pin.h"

// common interface includes
#include "network_if.h"
//#ifndef NOTERM
#include "uart_if.h"
//#endif

#include "button_if.h"
#include "gpio_if.h"
#include "timer_if.h"
#include "definitions.h"
//#include "common.h"
#include "utils.h"


#include "sl_mqtt_client.h"

// application specific includes
#include "pinmux.h"

#include "spawner.h"

#define UART_PRINT              Report

#define OSI_STACK_SIZE			2048

#define SH_GPIO_3                       (3)  /* P58 - Device Mode */

//*****************************************************************************
//                      LOCAL FUNCTION PROTOTYPES
//*****************************************************************************
void TimerPeriodicIntHandler(void);
void LedTimerConfigNStart();
void LedTimerDeinitStop();
void BoardInit(void);

//*****************************************************************************
//                 GLOBAL VARIABLES -- Start
//*****************************************************************************
#ifdef USE_FREERTOS
#if defined(ewarm)
extern uVectorEntry __vector_table;
#endif
#if defined(ccs)
extern void (* const g_pfnVectors[])(void);
#endif
#endif

unsigned short g_usTimerInts;

extern volatile unsigned long  g_ulStatus;

/* AP Security Parameters */
SlSecParams_t SecurityParams = {0};

//*****************************************************************************
//
//! Periodic Timer Interrupt Handler
//!
//! \param None
//!
//! \return None
//
//*****************************************************************************
void
TimerPeriodicIntHandler(void)
{
    unsigned long ulInts;

    //
    // Clear all pending interrupts from the timer we are
    // currently using.
    //
    ulInts = MAP_TimerIntStatus(TIMERA0_BASE, true);
    MAP_TimerIntClear(TIMERA0_BASE, ulInts);

    //
    // Increment our interrupt counter.
    //
    g_usTimerInts++;
    if(!(g_usTimerInts & 0x1))
    {
        //
        // Off Led
        //
        GPIO_IF_LedOff(MCU_RED_LED_GPIO);
    }
    else
    {
        //
        // On Led
        //
        GPIO_IF_LedOn(MCU_RED_LED_GPIO);
    }
}

//****************************************************************************
//
//! Function to configure and start timer to blink the LED while device is
//! trying to connect to an AP
//!
//! \param none
//!
//! return none
//
//****************************************************************************
void LedTimerConfigNStart()
{
    //
    // Configure Timer for blinking the LED for IP acquisition
    //
    Timer_IF_Init(PRCM_TIMERA0,TIMERA0_BASE,TIMER_CFG_PERIODIC,TIMER_A,0);
    Timer_IF_IntSetup(TIMERA0_BASE,TIMER_A,TimerPeriodicIntHandler);
    Timer_IF_Start(TIMERA0_BASE,TIMER_A,100);
}

//****************************************************************************
//
//! Disable the LED blinking Timer as Device is connected to AP
//!
//! \param none
//!
//! return none
//
//****************************************************************************
void LedTimerDeinitStop()
{
    //
    // Disable the LED blinking Timer as Device is connected to AP
    //
    Timer_IF_Stop(TIMERA0_BASE,TIMER_A);
    Timer_IF_DeInit(TIMERA0_BASE,TIMER_A);

}

//*****************************************************************************
//
//! Board Initialization & Configuration
//!
//! \param  None
//!
//! \return None
//
//*****************************************************************************
void BoardInit(void)
{
    /* In case of TI-RTOS vector table is initialize by OS itself */
    #ifndef USE_TIRTOS
    //
    // Set vector table base
    //
    #if defined(ccs)
        IntVTableBaseSet((unsigned long)&g_pfnVectors[0]);
    #endif
    #if defined(ewarm)
        IntVTableBaseSet((unsigned long)&__vector_table);
    #endif
    #endif
    //
    // Enable Processor
    //
    MAP_IntMasterEnable();
    MAP_IntEnable(FAULT_SYSTICK);

    PRCMCC3200MCUInit();
}

//****************************************************************************
//
//!    \brief Read Force AP GPIO and Configure Mode - 1(Access Point Mode)
//!                                                  - 0 (Station Mode)
//!
//! \return                        None
//
//****************************************************************************
unsigned int ReadDeviceConfiguration()
{
    unsigned int uiGPIOPort;
    unsigned char pucGPIOPin;
    unsigned char ucPinValue;

    //Read GPIO
    GPIO_IF_GetPortNPin(SH_GPIO_3,&uiGPIOPort,&pucGPIOPin);
    ucPinValue = GPIO_IF_Get(SH_GPIO_3,uiGPIOPort,pucGPIOPin);

    //If Connected to VCC, Mode is AP
    if(ucPinValue == 1)
    {
		//AP Mode
		return ROLE_AP;
    }
    else
    {
		//STA Mode
		return ROLE_STA;
    }

}

//*****************************************************************************
//
//!
//!
//!
//! \param  none
//!
//! This function
//!    1. Initializes network driver and connects to the default AP
//!    2. Initializes the threads
//! \return None
//!
//*****************************************************************************

void SpawnThread(void *pvParameters)
{
    
    long lRetVal = -1;

    unsigned int uMode = ReadDeviceConfiguration();

    //Parse data read
    initDefinitionsThread();




init:
    //
    // Configure LED
    //
    GPIO_IF_LedConfigure(LED1); //GPIO_IF_LedConfigure(LED1|LED2|LED3);
    GPIO_IF_LedOff(MCU_RED_LED_GPIO);
    //GPIO_IF_LedOff(MCU_GREEN_LED_GPIO);

    //
    // Reset The state of the machine
    //
    Network_IF_ResetMCUStateMachine();

    //
    // Start the driver
    //
    lRetVal = Network_IF_InitDriver(uMode);
    if(lRetVal < 0)
    {
       LOOP_FOREVER();
    }

    // switch on Green LED to indicate Simplelink is properly up
    //GPIO_IF_LedOn(MCU_ON_IND);

    // Start Timer to blink Red LED till AP connection
    LedTimerConfigNStart();


    if (ROLE_AP==uMode)
    	goto role_as_accessPoint;


    // Initialize AP security params
    SecurityParams.Key = GetSecurityKey();
    SecurityParams.KeyLen = GetSecurityKeyLen();
    SecurityParams.Type = GetSecurityType();

    //
    // Connect to the Access Point
    //
    lRetVal = Network_IF_ConnectAP(GetSSIDName(), SecurityParams);
    if(lRetVal < 0)
    {
       LOOP_FOREVER();
    }

role_as_accessPoint:

    //
    // Disable the LED blinking Timer as Device is connected to AP
    //
    LedTimerDeinitStop();

    //
    // Switch ON RED LED to indicate that Device acquired an IP
    //
    GPIO_IF_LedOn(MCU_IP_ALLOC_IND);

    UtilsDelay(20000000);

    GPIO_IF_LedOff(MCU_RED_LED_GPIO);
    //GPIO_IF_LedOff(MCU_ORANGE_LED_GPIO);
    //GPIO_IF_LedOff(MCU_GREEN_LED_GPIO);

    if (ROLE_AP!=uMode)
    {

        //SPAWNING IO Thread.... Create the message queue
        initIOThread();


        //SPAWNING UDP Thread
        initUdpThread();


        //SPAWNING Server Thread
        initServerThread();

        //SPAWNING MQTT Client

    	initMqttClient();

    }
    else
    {
    	//start the HTTP SERVER
    	initHTTPServerThread();


    }

    for(;;)
    {
    	//if AP disconnect
    	if (ROLE_AP!=uMode)
    	{
    	if (0==GET_STATUS_BIT(g_ulStatus, STATUS_BIT_CONNECTION))

    		{
    		terminateThreads();
    		osi_Sleep(5000);
    		goto init;

    		}
    	}
    	osi_Sleep(5000);
    }

}

//*****************************************************************************
//
//! Main 
//!
//! \param  none
//!
//! This function
//!    1. Invokes the SLHost task
//!    2. Invokes the MqttClient
//!
//! \return None
//!
//*****************************************************************************
void main()
{ 
    long lRetVal = -1;
    //
    // Initialize the board configurations
    //
    BoardInit();

    //
    //
    //
    PinMuxConfig();


    //Change Pin 58 Configuration from Default to Pull Down
    MAP_PinConfigSet(PIN_58,PIN_STRENGTH_2MA|PIN_STRENGTH_4MA,PIN_TYPE_STD_PD);



    //UART Initialization
    InitTerm();

    //
    // Start the SimpleLink Host
    //
    lRetVal = VStartSimpleLinkSpawnTask(SPAWN_TASK_PRIORITY);
    if(lRetVal < 0)
    {
        LOOP_FOREVER();
    }

    //
    //Starts the threads
    //
    lRetVal = osi_TaskCreate(SpawnThread,
                            (const signed char *)"Mqtt Client App",
                            OSI_STACK_SIZE, NULL, 2, NULL );

    if(lRetVal < 0)
    {
        LOOP_FOREVER();
    }
    //
    // Start the task scheduler
    //
    osi_start();
}

