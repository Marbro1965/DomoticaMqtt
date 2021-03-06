/*
 * CThread.h
 *
 *  Created on: 17/mar/2016
 *      Author: Marrelli
 */

#ifndef DOMOTICAMQTT_CTHREAD_H_
#define DOMOTICAMQTT_CTHREAD_H_

#include "sl_mqtt_client.h"


typedef enum events
{
	NO_MESSAGE,
    PUSH_BUTTON_SW2_PRESSED,
    PUSH_BUTTON_SW3_PRESSED,
    BROKER_DISCONNECTION,
	SAVE_POST_DATA,
	TEMPERATURE_READ,
	MOVEMENT_DETECTED
}osi_messages;

typedef struct
{
    //AP
    char 					SSID[32];
    char 					SecurityKey[32];
    int 					SecurityType;
    //brokers
    int 					brokerNumber;
    char 					address1[64];
    char 					address2[64];
    //userId
    char 					userId1[32];
    //password
    char 					password1[32];
    //port
    unsigned short 			port1;
    //userId
    char 					userId2[32];
    //password
    char 					password2[32];
    //port
    unsigned short 			port2;
    //entry of topic
    char 					entryPublish[32];
    char 					entrySubscribe[32];
    //Lan
    char 					useDHCP;
    unsigned long 			ipAddress;
    unsigned long 			mask;
    unsigned long 			gateway;
    unsigned long 			dns1;
    unsigned long 			dns2;

} configuration;

typedef struct
{
    const char* ptr;
    int bytes_left;
} buffer_ctx;

class CThread {

protected:

	bool isAlive;

	bool terminate;

	unsigned char g_ucDryerRunning;

	static float fCurrentTemp;

	static float fAmbientTemp;

	static configuration config;

public:

	/*Message Queue for IO*/
	static OsiMsgQ_t 	g_PBQueue;
	/*Message Queue for File Read*/
	static OsiMsgQ_t    g_FileReadQueue;
	/*Message Queue for File Write*/
	static OsiMsgQ_t    g_FileWriteQueue;
	/*Message Queue for I2C Read*/
	static OsiMsgQ_t    g_I2CQueue;


	CThread();

	virtual ~CThread();

	static void Create(void* param){

		(static_cast<CThread*>(param))->Run();
	}

	static void EntryExit(void* param){

		(static_cast<CThread*>(param))->Exit();
	}

	virtual void Run();

	virtual void Exit();

	virtual void Terminate();

	OsiMsgQ_t GetMessageQueue(void){

		return g_PBQueue;
	}

	static configuration* GetConfiguration(){

		return &config;
	}
};

#endif /* DOMOTICAMQTT_CTHREAD_H_ */
