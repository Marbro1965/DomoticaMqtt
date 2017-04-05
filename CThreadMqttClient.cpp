/*
 * CThreadMqttClient.cpp
 *
 *  Created on: 17/mar/2016
 *      Author: marrelli
 */

#include "CThreadMqttClient.h"

#ifndef NOTERM
#include "uart_if.h"
#endif

#include "button_if.h"

#include "common.h"

#include "spawner.h"


/*Operate Lib in MQTT 3.1 mode.*/
#define MQTT_3_1_1              false /*MQTT 3.1.1 */
#define MQTT_3_1                true /*MQTT 3.1*/

#define WILL_TOPIC              "Client"
#define WILL_MSG                "Client Stopped"
#define WILL_QOS                QOS2
#define WILL_RETAIN             false

#define MAX_BROKER_CONN         2

#define SERVER_MODE             MQTT_3_1
/*Specifying Receive time out for the Receive task*/
#define RCV_TIMEOUT             30


/* Keep Alive Timer value*/
#define KEEP_ALIVE_TIMER        25

/*Clean session flag*/
#define CLEAN_SESSION           true

/*Retain Flag. Used in publish message. */
#define RETAIN                  1

/*Defining QOS levels*/
#define QOS0                    0
#define QOS1                    1
#define QOS2                    2

/*Defining Publish Topic*/

#define PUB_TOPIC_FOR_SW3X       		"ButtonPressEvtSw3"
#define PUB_TOPIC_FOR_SW2X       		"ButtonPressEvtSw2"
#define PUB_TOPIC_FOR_TEMPERATURE       "Temperature"
#define PUB_TOPIC_FOR_MOVEMENT     		"Movement"


/*Defining Subscription Topic Values*/

#define SUB_TOPIC1X                  "ToggleLEDCmdL1"
#define SUB_TOPIC2X                  "ToggleLEDCmdL2"
#define SUB_TOPIC3X                  "ToggleLEDCmdL3"

void CThreadMqttClient::InitUserConnectConfig()
{

	char data[60];

	int i = 0;

	////////////////////////////////////////////////////////////////////////////////////
	//BROKER #1
	////////////////////////////////////////////////////////////////////////////////////
	usr_connect_config[0].broker_config.server_info.netconn_flags = SL_MQTT_NETCONN_URL;

	usr_connect_config[0].broker_config.server_info.server_addr = GetBrokerAddress(0);

	usr_connect_config[0].broker_config.server_info.port_number = GetBrokerPort(0);

	usr_connect_config[0].broker_config.server_info.method = 0;

	usr_connect_config[0].broker_config.server_info.cipher = 0;

	usr_connect_config[0].broker_config.server_info.n_files = 0;

	usr_connect_config[0].broker_config.server_info.secure_files = NULL;

	usr_connect_config[0].broker_config.blocking_send = SERVER_MODE;

	usr_connect_config[0].broker_config.mqtt_mode31 = true;

	usr_connect_config[0].clt_ctx = NULL;
	usr_connect_config[0].client_id = (unsigned char*)"user1";

	usr_connect_config[0].usr_name = (unsigned char*)GetBrokerUserId(0);
	usr_connect_config[0].usr_pwd = (unsigned char*)GetBrokerPassword(0);
	usr_connect_config[0].is_clean = true;
	usr_connect_config[0].keep_alive_time = KEEP_ALIVE_TIMER;

	usr_connect_config[0].CallBacks.sl_ExtLib_MqttRecv = CThreadMqttClient::Mqtt_Recv;
	usr_connect_config[0].CallBacks.sl_ExtLib_MqttEvent = CThreadMqttClient::sl_MqttEvt;
	usr_connect_config[0].CallBacks.sl_ExtLib_MqttDisconn = CThreadMqttClient::sl_MqttDisconnect;

	usr_connect_config[0].num_topics = TOPIC_COUNT;
	////////TOPIC 1
	i = sprintf(data,"%s%s",GetBrokerSubscribeEntry(),SUB_TOPIC1X);
	usr_connect_config[0].topic[0] = new char[i];
	sprintf(usr_connect_config[0].topic[0],"%s",data);
	////////TOPIC 2
	i = sprintf(data,"%s%s",GetBrokerSubscribeEntry(),SUB_TOPIC2X);
	usr_connect_config[0].topic[1] = new char[i];
	sprintf(usr_connect_config[0].topic[1],"%s",data);
	////////TOPIC 3
	i = sprintf(data,"%s%s",GetBrokerSubscribeEntry(),SUB_TOPIC3X);
	usr_connect_config[0].topic[2] = new char[i];
	sprintf(usr_connect_config[0].topic[2],"%s",data);

	usr_connect_config[0].qos[0] = QOS2;
	usr_connect_config[0].qos[1] = QOS2;
	usr_connect_config[0].qos[2] = QOS2;
	usr_connect_config[0].will_params.will_topic = WILL_TOPIC;
	usr_connect_config[0].will_params.will_msg = WILL_MSG;
	usr_connect_config[0].will_params.will_qos = WILL_QOS;
	usr_connect_config[0].will_params.retain = WILL_RETAIN;

	usr_connect_config[0].is_connected = false;

	////////////////////////////////////////////////////////////////////////////////////
	//BROKER #2
	////////////////////////////////////////////////////////////////////////////////////
	usr_connect_config[1].broker_config.server_info.netconn_flags = SL_MQTT_NETCONN_URL;

	usr_connect_config[1].broker_config.server_info.server_addr = GetBrokerAddress(1);

	usr_connect_config[1].broker_config.server_info.port_number = GetBrokerPort(1);

	usr_connect_config[1].broker_config.server_info.method = 0;

	usr_connect_config[1].broker_config.server_info.cipher = 0;

	usr_connect_config[1].broker_config.server_info.n_files = 0;

	usr_connect_config[1].broker_config.server_info.secure_files = NULL;

	usr_connect_config[1].broker_config.blocking_send = SERVER_MODE;

	usr_connect_config[1].broker_config.mqtt_mode31 = true;

	usr_connect_config[1].clt_ctx = NULL;
	usr_connect_config[1].client_id = (unsigned char*)"user1";
	usr_connect_config[1].usr_name = (unsigned char*)GetBrokerUserId(1);
	usr_connect_config[1].usr_pwd = (unsigned char*)GetBrokerPassword(1);
	usr_connect_config[1].is_clean = true;
	usr_connect_config[1].keep_alive_time = KEEP_ALIVE_TIMER;

	usr_connect_config[1].CallBacks.sl_ExtLib_MqttRecv = CThreadMqttClient::Mqtt_Recv;
	usr_connect_config[1].CallBacks.sl_ExtLib_MqttEvent = CThreadMqttClient::sl_MqttEvt;
	usr_connect_config[1].CallBacks.sl_ExtLib_MqttDisconn = CThreadMqttClient::sl_MqttDisconnect;

	usr_connect_config[1].num_topics = TOPIC_COUNT;
	////////TOPIC 1
	i = sprintf(data,"%s%s",GetBrokerSubscribeEntry(),SUB_TOPIC1X);
	usr_connect_config[1].topic[0] = new char[i];
	sprintf(usr_connect_config[1].topic[0],"%s",data);
	////////TOPIC 2
	i = sprintf(data,"%s%s",GetBrokerSubscribeEntry(),SUB_TOPIC2X);
	usr_connect_config[1].topic[1] = new char[i];
	sprintf(usr_connect_config[1].topic[1],"%s",data);
	////////TOPIC 3
	i = sprintf(data,"%s%s",GetBrokerSubscribeEntry(),SUB_TOPIC3X);
	usr_connect_config[1].topic[2] = new char[i];
	sprintf(usr_connect_config[1].topic[2],"%s",data);

	usr_connect_config[1].qos[0] = QOS2;
	usr_connect_config[1].qos[1] = QOS2;
	usr_connect_config[1].qos[2] = QOS2;
	usr_connect_config[1].will_params.will_topic = WILL_TOPIC;
	usr_connect_config[1].will_params.will_msg = WILL_MSG;
	usr_connect_config[1].will_params.will_qos = WILL_QOS;
	usr_connect_config[1].will_params.retain = WILL_RETAIN;

	usr_connect_config[1].is_connected = false;

	//////////////////////////////// P U B L I S H ///////////////////////////////
	i = sprintf(data,"%s%s",GetBrokerPublishEntry(),PUB_TOPIC_FOR_SW2X);
	pub_topic_sw2 = new char[i];
	sprintf((char*)pub_topic_sw2,"%s",data);

	i = sprintf(data,"%s%s",GetBrokerPublishEntry(),PUB_TOPIC_FOR_SW3X);
	pub_topic_sw3 = new char[i];
	sprintf((char*)pub_topic_sw3,"%s",data);

	i = sprintf(data,"%s%s",GetBrokerPublishEntry(),PUB_TOPIC_FOR_TEMPERATURE);
	pub_topic_sw4 = new char[i];
	sprintf((char*)pub_topic_sw4,"%s",data);


}

long CThreadMqttClient::InitMqttClientLibrary(void)
{
	long lRetVal = -1;

	lRetVal = sl_ExtLib_MqttClientInit(&Mqtt_Client);
	if(lRetVal != 0)
		{
	    // lib initialization failed
	    UART_PRINT("MQTT Client lib initialization failed\n\r");
	    LOOP_FOREVER();
	    }
	return lRetVal;
}

CThreadMqttClient::CThreadMqttClient(int broker) {
	// TODO Auto-generated constructor stub

	app_hndl = (void*)usr_connect_config;

	bToggle = false;

	_brokerCount = broker;
}

CThreadMqttClient::~CThreadMqttClient() {
	// TODO Auto-generated destructor stub
}


void CThreadMqttClient::Run(){

    int iConnBroker = 0;

	connect_config *local_con_conf = (connect_config *)app_hndl;


	//memorize the pointer to thread so to discriminate who is sending message and
	//to whom send message from main thread.

	local_con_conf[_brokerCount].callThread = this;

	//
	//create client context unico
	//
	local_con_conf[_brokerCount].clt_ctx =  sl_ExtLib_MqttClientCtxCreate(&local_con_conf[_brokerCount].broker_config,
									  &local_con_conf[_brokerCount].CallBacks,
									  &(local_con_conf[_brokerCount]));

	//
	// Set Client ID
	//
	sl_ExtLib_MqttClientSet((void*)local_con_conf[_brokerCount].clt_ctx,
							SL_MQTT_PARAM_CLIENT_ID,
							local_con_conf[_brokerCount].client_id,
							strlen((char*)(local_con_conf[_brokerCount].client_id)));

	//
	// Set will Params
	//
	if(local_con_conf[_brokerCount].will_params.will_topic != NULL)
		{
		sl_ExtLib_MqttClientSet((void*)local_con_conf[_brokerCount].clt_ctx,
									SL_MQTT_PARAM_WILL_PARAM,
									&(local_con_conf[_brokerCount].will_params),
									sizeof(SlMqttWill_t));
		}

	//
	// setting username
	//
	if(local_con_conf[_brokerCount].usr_name != NULL)
	   {
	   sl_ExtLib_MqttClientSet((void*)local_con_conf[_brokerCount].clt_ctx,
								SL_MQTT_PARAM_USER_NAME,
								local_con_conf[_brokerCount].usr_name,
								strlen((char*)local_con_conf[_brokerCount].usr_name));
	   }
	//
	// setting password
	//
   if(local_con_conf[_brokerCount].usr_pwd != NULL)
		{
		sl_ExtLib_MqttClientSet((void*)local_con_conf[_brokerCount].clt_ctx,
							SL_MQTT_PARAM_PASS_WORD,
							local_con_conf[_brokerCount].usr_pwd,
							strlen((char*)local_con_conf[_brokerCount].usr_pwd));
		}

	//
	// connecting to the broker
	//

	int iReconnect = 0;

	unsigned long ret;

	ret = sl_ExtLib_MqttClientConnect((void*)local_con_conf[_brokerCount].clt_ctx,
			local_con_conf[_brokerCount].is_clean,
			local_con_conf[_brokerCount].keep_alive_time) & 0xFF;

	while(ret!=0)
			{

			//UART_PRINT("\n\rBroker connect fail for conn no. %d \n\r",iCount+1);

			UART_PRINT("\n\rReconnect. %d \n\r",iReconnect+1);

			osi_Sleep(1000);

			iReconnect++;

			if (iReconnect>3)
				break;

			ret = sl_ExtLib_MqttClientConnect((void*)local_con_conf[_brokerCount].clt_ctx,
					local_con_conf[_brokerCount].is_clean,
					local_con_conf[_brokerCount].keep_alive_time) & 0xFF;


			}



	if (ret!=0)
		{
		UART_PRINT("\n\rBroker connect fail for conn no. %d \n\r",_brokerCount+1);
		//delete the context for this connection
		sl_ExtLib_MqttClientCtxDelete(local_con_conf[_brokerCount].clt_ctx);

		goto end;
		}
	else
		{
		//the relevant thread is connected
		UART_PRINT("\n\rSuccess: conn to Broker no. %d\n\r ", _brokerCount+1);
		local_con_conf[_brokerCount].is_connected = true;

		}

	//
	// Subscribe to topics
	//
	if(sl_ExtLib_MqttClientSub((void*)local_con_conf[_brokerCount].clt_ctx,
								   local_con_conf[_brokerCount].topic,
								   local_con_conf[_brokerCount].qos, TOPIC_COUNT) < 0)
		{
			UART_PRINT("\n\r Subscription Error for conn no. %d\n\r", _brokerCount+1);
			UART_PRINT("Disconnecting from the broker\r\n");
			sl_ExtLib_MqttClientDisconnect(local_con_conf[_brokerCount].clt_ctx);
					local_con_conf[_brokerCount].is_connected = false;

			//delete the context for this connection
			sl_ExtLib_MqttClientCtxDelete(local_con_conf[_brokerCount].clt_ctx);

			goto end;
		}
	else
	    {

	      	UART_PRINT("Client subscribed on following topics:\n\r");
	       	for(int iSub = 0; iSub < local_con_conf[_brokerCount].num_topics; iSub++)
	        	{
	        		UART_PRINT("%s\n\r", local_con_conf[_brokerCount].topic[iSub]);
	            }
	    }


	//
	//when everything ok send message that it starts handling messages
	//
    my_message var;
    var.ulmessage = MQTT_CLIENT_STARTED_THREAD_HANDLE_MESSAGE;
    var.ultaskId = this;
    osi_MsgQWrite(&g_MqttSendQueue,&var,OSI_NO_WAIT);

    //Ciclo dei messaggi ricevuti da CThreadMain e da inviare su rete

	HandleMessages();
	//
	//
	// Deinitializating the client library
	//


end:

	var.ulmessage = MQTT_CLIENT_END;
	var.ultaskId = this;
	osi_MsgQWrite(&g_MqttSendQueue,&var,OSI_NO_WAIT);


	sl_ExtLib_MqttClientExit();
	UART_PRINT("\n\r Exiting the Application\n\r");

    OsiTaskHandle tHandle = NULL;
    osi_TaskDelete(&tHandle);

}

/*
 *
 *
 *
 *
 */
//****************************************************************************
//! Defines Mqtt_Pub_Message_Receive event handler.
//! Client App needs to register this event handler with sl_ExtLib_mqtt_Init
//! API. Background receive task invokes this handler whenever MQTT Client
//! receives a Publish Message from the broker.
//!
//!\param[out]     topstr => pointer to topic of the message
//!\param[out]     top_len => topic length
//!\param[out]     payload => pointer to payload
//!\param[out]     pay_len => payload length
//!\param[out]     retain => Tells whether its a Retained message or not
//!\param[out]     dup => Tells whether its a duplicate message or not
//!\param[out]     qos => Tells the Qos level
//!
//!\return none
//****************************************************************************
void CThreadMqttClient::Mqtt_Recv(void *app_hndl, const char  *topstr, long top_len, const void *payload,
                       long pay_len, bool dup,unsigned char qos, bool retain)
{
	char data[60];
    char *output_str= new char[top_len+1];
    memset(output_str,'\0',top_len+1);
    strncpy(output_str, (char*)topstr, top_len);
    output_str[top_len]='\0';

    sprintf(data,"%s%s",GetBrokerPublishEntry(),SUB_TOPIC1X);

    if(strncmp(output_str,data, top_len) == 0)
    {
        ToggleLedState(LED1);
    }
    sprintf(data,"%s%s",GetBrokerPublishEntry(),SUB_TOPIC2X);
    if(strncmp(output_str,data, top_len) == 0)
    {
        //ToggleLedState(LED2);
    }
    sprintf(data,"%s%s",GetBrokerPublishEntry(),SUB_TOPIC3X);
    if(strncmp(output_str,data, top_len) == 0)
    {
        //ToggleLedState(LED3);
    }

    UART_PRINT("\n\rPublish Message Received");
    UART_PRINT("\n\rTopic: ");
    UART_PRINT("%s",output_str);
    delete output_str;
    UART_PRINT(" [Qos: %d] ",qos);
    if(retain)
      UART_PRINT(" [Retained]");
    if(dup)
      UART_PRINT(" [Duplicate]");

    output_str= new char[pay_len+1];

    memset(output_str,'\0',pay_len+1);
    strncpy(output_str, (char*)payload, pay_len);
    output_str[pay_len]='\0';
    UART_PRINT("\n\rData is: ");
    UART_PRINT("%s",(char*)output_str);
    UART_PRINT("\n\r");
    delete output_str;

    return;
}

//****************************************************************************
//! Defines sl_MqttEvt event handler.
//! Client App needs to register this event handler with sl_ExtLib_mqtt_Init
//! API. Background receive task invokes this handler whenever MQTT Client
//! receives an ack(whenever user is in non-blocking mode) or encounters an error.
//!
//! param[out]      evt => Event that invokes the handler. Event can be of the
//!                        following types:
//!                        MQTT_ACK - Ack Received
//!                        MQTT_ERROR - unknown error
//!
//!
//! \param[out]     buf => points to buffer
//! \param[out]     len => buffer length
//!
//! \return none
//****************************************************************************
void CThreadMqttClient::sl_MqttEvt(void *app_hndl, long evt, const void *buf,unsigned long len)
{
    int i;
    switch(evt)
    {
      case SL_MQTT_CL_EVT_PUBACK:
        UART_PRINT("PubAck:\n\r");
        UART_PRINT("%s\n\r",buf);
        break;

      case SL_MQTT_CL_EVT_SUBACK:
        UART_PRINT("\n\rGranted QoS Levels are:\n\r");

        for(i=0;i<len;i++)
        {
          UART_PRINT("QoS %d\n\r",((unsigned char*)buf)[i]);
        }
        break;

      case SL_MQTT_CL_EVT_UNSUBACK:
        UART_PRINT("UnSub Ack \n\r");
        UART_PRINT("%s\n\r",buf);
        break;

      default:
        break;

    }
}

//****************************************************************************
//
//! callback event in case of MQTT disconnection
//!
//! \param app_hndl is the handle for the disconnected connection
//!
//! return none
//
//****************************************************************************
void CThreadMqttClient::sl_MqttDisconnect(void *app_hndl)
{
    connect_config *local_con_conf;

    local_con_conf = (connect_config*)app_hndl;

    my_message var;

    var.ulmessage = BROKER_DISCONNECTION;

    var.ultaskId = local_con_conf->callThread;


    sl_ExtLib_MqttClientUnsub(local_con_conf->clt_ctx, local_con_conf->topic,TOPIC_COUNT);

    UART_PRINT("disconnect from broker %s\r\n",(local_con_conf->broker_config).server_info.server_addr);

    local_con_conf->is_connected = false;

    sl_ExtLib_MqttClientCtxDelete(local_con_conf->clt_ctx);

    //
    // write message indicating publish message
    //
    osi_MsgQWrite(&g_MqttSendQueue,&var,OSI_NO_WAIT);

}

//****************************************************************************
//
//!    Toggles the state of GPIOs(LEDs)
//!
//! \param LedNum is the enumeration for the GPIO to be toggled
//!
//!    \return none
//
//****************************************************************************
void CThreadMqttClient::ToggleLedState(ledEnum LedNum)
{
    unsigned char ledstate = 0;
    switch(LedNum)
    {
    case LED1:
        ledstate = GPIO_IF_LedStatus(MCU_RED_LED_GPIO);
        if(!ledstate)
        {
            GPIO_IF_LedOn(MCU_RED_LED_GPIO);
        }
        else
        {
            GPIO_IF_LedOff(MCU_RED_LED_GPIO);
        }
        break;
    case LED2:
        ledstate = GPIO_IF_LedStatus(MCU_ORANGE_LED_GPIO);
        if(!ledstate)
        {
            GPIO_IF_LedOn(MCU_ORANGE_LED_GPIO);
        }
        else
        {
            GPIO_IF_LedOff(MCU_ORANGE_LED_GPIO);
        }
        break;
    case LED3:
        ledstate = GPIO_IF_LedStatus(MCU_GREEN_LED_GPIO);
        if(!ledstate)
        {
            GPIO_IF_LedOn(MCU_GREEN_LED_GPIO);
        }
        else
        {
            GPIO_IF_LedOff(MCU_GREEN_LED_GPIO);
        }
        break;
    default:
        break;
    }
}

//****************************************************************************
//Operations to do when disconnect from AP
//****************************************************************************
void CThreadMqttClient::Terminate()
{

	connect_config *local_con_conf = (connect_config *)app_hndl;

	int iNumBroker = CThread::config.brokerNumber;

	int iCount = 0;

	if(iNumBroker > MAX_BROKER_CONN)
		{
	    UART_PRINT("Num of brokers are more then max num of brokers\n\r");
	    LOOP_FOREVER();
	    }

	while(iCount < iNumBroker)
	    {
	    //simula una disconnessione da server
		sl_MqttDisconnect(&local_con_conf[iCount]);

	    }

}
void CThreadMqttClient::HandleMessages(void)
{
	connect_config *local_con_conf = (connect_config *)app_hndl;

	my_message RecvQue;

    char data[64];

    data_sw4 = new unsigned char[64];

    int iNumBroker = CThread::config.brokerNumber;

	for(;;)
	    {
	    osi_MsgQRead( &g_MqttReceiveQueue, &RecvQue, OSI_WAIT_FOREVER);

	    for (int iCount = 0; iCount<iNumBroker; iCount++)
	    	{

			if(PUSH_BUTTON_SW2_PRESSED == RecvQue.ulmessage)
			   {
			   Button_IF_EnableInterrupt(SW2);
			   //
			   // send publish message
			   //
			   if (local_con_conf[iCount].is_connected)
			   	   {
				   sl_ExtLib_MqttClientSend((void*)local_con_conf[iCount].clt_ctx,
						   pub_topic_sw2,data_sw2,strlen((char*)data_sw2),QOS2,RETAIN);
					UART_PRINT("\n\r CC3200 Publishes the following message \n\r");
					UART_PRINT("Topic: %s\n\r",pub_topic_sw2);
					UART_PRINT("Data: %s\n\r",data_sw2);
			   	   }
			   }
			else if(PUSH_BUTTON_SW3_PRESSED == RecvQue.ulmessage)
				{
				Button_IF_EnableInterrupt(SW3);
				//
				// send publish message
				//
				if (local_con_conf[iCount].is_connected)
					{
					sl_ExtLib_MqttClientSend((void*)local_con_conf[iCount].clt_ctx,
							   pub_topic_sw3,data_sw3,strlen((char*)data_sw3),QOS2,RETAIN);
						UART_PRINT("\n\r CC3200 Publishes the following message \n\r");
						UART_PRINT("Topic: %s\n\r",pub_topic_sw3);
						UART_PRINT("Data: %s\n\r",data_sw3);
					}
				}
			else if (TEMPERATURE_READ == RecvQue.ulmessage)
				{
//				if (bToggle)
//				{
//					GPIO_IF_LedOn(MCU_RED_LED_GPIO);
//					bToggle=false;
//
//				}
//				else
//				{
//					GPIO_IF_LedOff(MCU_RED_LED_GPIO);
//					bToggle = true;
//
//				}
				if (local_con_conf[iCount].is_connected)
					{
					int i = sprintf(data,"%s%.1f%s%.1f","sensore IR: ",fCurrentTemp,"; sensore chip: ",fAmbientTemp);
					sprintf((char*)data_sw4,"%s",data);

					sl_ExtLib_MqttClientSend((void*)local_con_conf[iCount].clt_ctx,
						   pub_topic_sw4,data_sw4,strlen((char*)data_sw4),QOS2,RETAIN);
					UART_PRINT("Data: %s\n\r",data_sw4);
					}
				}
			else if(BROKER_DISCONNECTION == RecvQue.ulmessage)
				{

				UART_PRINT("Disconnected: %s\n\r","");

				//deve marcare la configurazione sconnessa

				//se non ci sono configurazioni esce

				break;
				}
			else if (FORCE_BROKER_DISCONNECTION==RecvQue.ulmessage)
				{

				break;
				}

	    	}
	    }


}
