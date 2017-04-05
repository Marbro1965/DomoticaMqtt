/*
 * CThreadMain.cpp
 *
 *  Created on: 15 mar 2017
 *      Author: Fortunato
 */

#include "CThreadMain.h"

#include "CThreadMqttClient.h"
// common interface includes
#include "network_if.h"
#include "gpio_if.h"
#include "button_if.h"
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

    //Creazione della coda dei messaggi
    CThread::CreateMessageQueue();

    //Impostazione struttura broker
    CThreadMqttClient::InitUserConnectConfig();


    // Configure LED
reconnection:

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
       //LOOP_FOREVER();
    	CThread::LedTimerDeinitStop();
    	GPIO_IF_LedOff(MCU_RED_LED_GPIO);
    	osi_Sleep(4000);
    	goto reconnection;
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


    //Libreria Mqtt (Thread????) se c'e' stata una disconnessione meglio
    //riinizializzare la libreria
    CThreadMqttClient::InitMqttClientLibrary();

    //creazione dei task MQTT
    initMqttClient();

    //creazione task I2C

    //creazione task I/O


    for(;;)
    {
    	if (ROLE_AP!=uMode)
    	{
			if (IS_CONNECTED(g_ulStatus))
			{
				//
				//Read messages from MQTT client
				//
				my_message var;

				var.ulmessage = NO_MESSAGE;

				osi_MsgQRead( &g_MqttSendQueue, &var, OSI_NO_WAIT);

				switch (var.ulmessage)
				{
				case MQTT_CLIENT_STARTED_THREAD_HANDLE_MESSAGE:
					//c'e' almeno un task MQTT in grado di gestire il messaggio
				    g_sendMessageStatus = true;

					break;
				case MQTT_CLIENT_END:
					//segnala il thread disconnesso
					g_sendMessageStatus = false;
					break;

				case BROKER_DISCONNECTION:

					//reindirizza il messaggio

					//flagga il thread come non in grado di ricevere messaggi
					osi_MsgQWrite(&g_MqttReceiveQueue,&var,OSI_NO_WAIT);

					break;


				}
				//
				//Read other messages from queue (key pressed, broker disconnection etc
				//
				if (g_sendMessageStatus)
				{
					var.ulmessage = NO_MESSAGE;

					osi_MsgQRead( &g_PBQueue, &var, OSI_NO_WAIT);

					switch (var.ulmessage)
					{
						case PUSH_BUTTON_SW2_PRESSED:
							Button_IF_EnableInterrupt(SW2);
							//
							// send publish message to mqtt clients threads
							//
							break;

						case PUSH_BUTTON_SW3_PRESSED:

							// send publish message to mqtt clients threads

							Button_IF_EnableInterrupt(SW3);

							break;
						case TEMPERATURE_READ:

							// send publish message to mqtt clients threads

							break;

					}
				}
			}
			else
			{
				//
				//deve interrompere l'invio dei messaggi da parte dei threads
				//
				g_sendMessageStatus = false;

				//terminateThreads();
				osi_Sleep(2000);

				goto reconnection;
			}

		}

    	//osi_Sleep(5000);
    }


}


/*
 *
 *
 */
void CThreadMain::EmptyQueueMessage(void)
{

	//verificare alla partenza cosa succede quando la coda e' vuota

	my_message RecvQue;

	OsiReturnVal_e e = osi_MsgQRead( &g_PBQueue, &RecvQue, OSI_NO_WAIT);


}
