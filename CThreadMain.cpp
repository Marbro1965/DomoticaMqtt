/*
 * CThreadMain.cpp
 *
 *  Created on: 15 mar 2017
 *      Author: Fortunato
 */

#include "CThreadMain.h"

// common interface includes
#include "network_if.h"
#include "gpio_if.h"

#include "spawner.h"

#include "definitions.h"

#define SH_GPIO_3                       (3)  /* P58 - Device Mode */

extern volatile unsigned long  g_ulStatus;

CThreadMain::CThreadMain() {
	// TODO Auto-generated constructor stub

}

CThreadMain::~CThreadMain() {
	// TODO Auto-generated destructor stub
}
//****************************************************************************
//
//!    \brief Read Force AP GPIO and Configure Mode - 1(Access Point Mode)
//!                                                  - 0 (Station Mode)
//!
//! \return                        None
//
//****************************************************************************
unsigned int CThreadMain::ReadDeviceConfiguration()
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

void CThreadMain::Run(){


    long lRetVal = -1;

    unsigned int uMode = ReadDeviceConfiguration();

    //Parse data read
    initDefinitionsThread();

    //
    // Configure LED
    //
    GPIO_IF_LedConfigure(LED1);//|LED2|LED3); //GPIO_IF_LedConfigure(LED1|LED2|LED3);
    GPIO_IF_LedOff(MCU_RED_LED_GPIO);
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
    // Start Timer to blink Red LED till AP connection
    CThread::LedTimerConfigNStart();

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
	CThread::LedTimerDeinitStop();
    //
    // Switch ON RED LED to indicate that Device acquired an IP
    //
    GPIO_IF_LedOn(MCU_IP_ALLOC_IND);

    osi_Sleep(2000);

    GPIO_IF_LedOff(MCU_RED_LED_GPIO);

    if (ROLE_AP!=uMode)
    {


    }
    else
    {

    }

    for(;;)
    {
    	if (ROLE_AP!=uMode)
    	{
			if (IS_CONNECTED(g_ulStatus))
				;
			else
			{
				terminateThreads();
				osi_Sleep(5000);
				//goto init;
			}

		}

    	osi_Sleep(5000);
    }


}
