/*
 * CThread.cpp
 *
 *  Created on: 17/mar/2016
 *      Author: Marrelli
 */

#include "CThread.h"

#ifndef NOTERM
#include "uart_if.h"
#endif

#include "hw_types.h"
#include "hw_ints.h"
#include "hw_memmap.h"
#include "prcm.h"

#include "interrupt.h"
#include "timer.h"
#include "timer_if.h"

#include "gpio_if.h"

#define UART_PRINT              Report

/*Background receive task priority*/
#define TASK_PRIORITY           3


/*Publishing topics and messages*/
const char *CThread::pub_topic_sw2 = NULL;

const char *CThread::pub_topic_sw3 = NULL;

const char *CThread::pub_topic_sw4 = NULL;

const char *CThread::pub_topic_sw5 = NULL;

unsigned char *CThread::data_sw2=(unsigned char*)"Push button sw2 is pressed on CC32XX device";

unsigned char *CThread::data_sw3=(unsigned char*)"Push button sw3 is pressed on CC32XX device";

unsigned char *CThread::data_sw4= NULL;

unsigned char *CThread::data_sw5= NULL;

unsigned short CThread::g_usTimerInts = 0;

volatile bool CThread::g_sendMessageStatus = 0;

connect_config CThread::usr_connect_config[2];

/* library configuration */
SlMqttClientLibCfg_t CThread::Mqtt_Client={
    1882,
    TASK_PRIORITY,
    30,
    true,
    (long(*)(const char *, ...))UART_PRINT
};


OsiMsgQ_t CThread::g_PBQueue = 0;

OsiMsgQ_t CThread::g_FileWriteQueue = 0;

OsiMsgQ_t CThread::g_FileReadQueue = 0;

OsiMsgQ_t CThread::g_I2CQueue = 0;

OsiMsgQ_t CThread::g_MqttSendQueue = 0;

OsiMsgQ_t CThread::g_MqttReceiveQueue = 0;


configuration CThread::config;

SlSecParams_t CThread::SecurityParams = {0};

float CThread::fCurrentTemp;

float CThread::fAmbientTemp;


CThread::CThread() {
	// TODO Auto-generated constructor stub

	terminate = false;

}

CThread::~CThread() {
	// TODO Auto-generated destructor stub
}

void CThread::Run()
{

	for(;;)
	{

	if (terminate)
		break;

	}

	//when thread finishes spawn callback to free resourses

}

void CThread::Exit(){



}

void CThread::Terminate(){

	terminate = true;

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
void CThread::LedTimerConfigNStart()
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
void CThread::LedTimerDeinitStop()
{
    //
    // Disable the LED blinking Timer as Device is connected to AP
    //
    Timer_IF_Stop(TIMERA0_BASE,TIMER_A);
    Timer_IF_DeInit(TIMERA0_BASE,TIMER_A);

}

//*****************************************************************************
//
//! Periodic Timer Interrupt Handler
//!
//! \param None
//!
//! \return None
//
//*****************************************************************************
void CThread::TimerPeriodicIntHandler(void)
{
    unsigned long ulInts;

    //
    // Clear all pending interrupts from the timer we are
    // currently using.
    //
    //ulInts = MAP_TimerIntStatus(TIMERA0_BASE, true);
    ulInts = TimerIntStatus(TIMERA0_BASE, true);
    //MAP_TimerIntClear(TIMERA0_BASE, ulInts);
    TimerIntClear(TIMERA0_BASE, ulInts);
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

void CThread::CreateMessageQueue()
{

	osi_MsgQCreate(&g_PBQueue,"PBQueue",sizeof(my_message),10);

	osi_MsgQCreate(&g_MqttSendQueue,"MQTTSendQueue",sizeof(my_message),10);

	osi_MsgQCreate(&g_MqttReceiveQueue,"MQTTReceiveQueue",sizeof(my_message),10);

	osi_MsgQCreate(&g_FileWriteQueue,"FileWriteQueue",sizeof(my_message),10);



}
