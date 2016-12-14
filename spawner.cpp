/*
 * spawner.cpp
 *
 *  Created on: 17/mar/2016
 *      Author: marrelli
 */

#include "spawner.h"

#include "CThreadUDp.h"

#include "CThreadTCPServer.h"

#include "CThreadTCPClient.h"

#include "CThreadHTTPServer.h"

#include "CThreadIO.h"

#include "CThreadMqttClient.h"

#include "CThreadDefinitions.h"

#include "simplelink.h"

#include "osi.h"

#define OSI_STACK_SIZE	2048

#define UDP_PORT		1000

#define TCP_PORT		2000

void initThreadsPointer(){

	udpThread = 0;

	tcpServerThread = 0;

	ioThread = 0;

	mqttThread = 0;

	httpServerThread = 0;
}

void initUdpThread(){

	if (0==udpThread)

		udpThread = new CThreadUDP(UDP_PORT);

	osi_TaskCreate(&CThreadUDP::Create,(const signed char *)"Udp thread",OSI_STACK_SIZE, udpThread, 2, NULL );

}


void initServerThread(){

	if (0==tcpServerThread)
	{
		tcpServerThread = new CThreadTCPServer(TCP_PORT);
	}

	osi_TaskCreate(&CThreadTCPServer::Create,(const signed char *)"TCP server",OSI_STACK_SIZE, tcpServerThread, 2, NULL);

}



void initClientThread(void* thread){


	osi_TaskCreate(&CThreadTCPClient::Create,(const signed char *)"TCP client",OSI_STACK_SIZE, thread, 2,NULL);

}

void initIOThread(){

	if (0==ioThread)
	{

		ioThread = new CThreadIO();
	}

	osi_TaskCreate(&CThreadIO::Create,(const signed char *)"IO thread",OSI_STACK_SIZE, ioThread, 2,NULL);

}

void initMqttClient(){

	if (0==mqttThread)

		mqttThread = new CThreadMqttClient();

	osi_TaskCreate(&CThreadMqttClient::Create,(const signed char *)"MQTT thread",OSI_STACK_SIZE, mqttThread, 2,NULL);

}

void initHTTPServerThread(){


	if (0==httpServerThread)

		httpServerThread = new CThreadHTTPServer();

	osi_TaskCreate(&CThreadHTTPServer::Create,(const signed char *)"HTTP SERVER thread",OSI_STACK_SIZE, httpServerThread, 2,NULL);

}

void terminateThreads(){

	((CThread*)udpThread)->Terminate();

	((CThread*)tcpServerThread)->Terminate();

	((CThread*)mqttThread)->Terminate();

}


void initDefinitionsThread()
{

    long lFileHandle = 0;
    unsigned long ulToken = 0;
    long lRetVal=-1;

    //
    // Initializing the CC3200 networking layers
    //
    lRetVal = sl_Start(NULL, NULL, NULL);
    if(lRetVal < 0)
    {
        GPIO_IF_LedOn(MCU_RED_LED_GPIO);
        //LOOP_FOREVER();
    }

    //
    // reset all network policies
    //


    //Read parameters from file
    if(CThreadDefinitions::ReadFromFile(ulToken, lFileHandle) < 0)
    {
        //GPIO_IF_LedOn(MCU_RED_LED_GPIO);
         //LOOP_FOREVER();
    }
    CThreadDefinitions::parseFile();


}

signed char* GetSecurityKey(){

	return (signed char*)CThread::GetConfiguration()->SecurityKey;
}

void SetSecurityKey(signed char* p, unsigned char len){

	memset((void*)CThread::GetConfiguration()->SecurityKey,0,sizeof(CThread::GetConfiguration()->SecurityKey));
	memcpy((void*)CThread::GetConfiguration()->SecurityKey,(void*)p,len);

}


int GetSecurityKeyLen(){

	return strlen(CThread::GetConfiguration()->SecurityKey);
}

int GetSecurityType(){

	return CThread::GetConfiguration()->SecurityType;
}

void SetSecurityType(int i){

	CThread::GetConfiguration()->SecurityType = i;
}

char* GetSSIDName(){

	return (char*)CThread::GetConfiguration()->SSID;


}

void SetSSIDName(unsigned char* p,unsigned char len){

	memset((void*)CThread::GetConfiguration()->SSID,0,sizeof(CThread::GetConfiguration()->SSID));
	memcpy((void*)CThread::GetConfiguration()->SSID,(void*)p,len);

}
char* GetBrokerAddress(short index){

	if (0==index)
		return (char*)CThread::GetConfiguration()->address1;
	else
		return (char*)CThread::GetConfiguration()->address2;
}

char* GetBrokerUserId(short index){

	if (0==index)
		return (char*)CThread::GetConfiguration()->userId1;
	else
		return (char*)CThread::GetConfiguration()->userId2;

}

char* GetBrokerPassword(short index){

	if (0==index)
		return (char*)CThread::GetConfiguration()->password1;
	else
		return (char*)CThread::GetConfiguration()->password2;

}

char* GetBrokerPublishEntry(){

	return (char*)CThread::GetConfiguration()->entryPublish;
}

char* GetBrokerSubscribeEntry(){

	return (char*)CThread::GetConfiguration()->entrySubscribe;
}

void SetBrokerPublishEntry(unsigned char *p, unsigned char len)
{
	//TODO check length, do not forget null terminated
	memset((void*)CThread::GetConfiguration()->entryPublish,0,sizeof(CThread::GetConfiguration()->entryPublish));
	memcpy((void*)CThread::GetConfiguration()->entryPublish,(void*)p,len);


}

void SetBrokerSubscribeEntry(unsigned char *p, unsigned char len)
{
	memset((void*)CThread::GetConfiguration()->entrySubscribe,0,sizeof(CThread::GetConfiguration()->entrySubscribe));
	memcpy((void*)CThread::GetConfiguration()->entrySubscribe,(void*)p,len);

}

unsigned short GetBrokerPort(short index){

	if (0==index)
		return CThread::GetConfiguration()->port1;
	else
		return CThread::GetConfiguration()->port2;
}


void SetBrokerAddress(short index,unsigned char *p, unsigned char len){

	if (0==index)
	{
		memset((void*)CThread::GetConfiguration()->address1,0,sizeof(CThread::GetConfiguration()->address1));
		memcpy((void*)CThread::GetConfiguration()->address1,(void*)p,len);
	}
	else{
		memset((void*)CThread::GetConfiguration()->address2,0,sizeof(CThread::GetConfiguration()->address2));
		memcpy((void*)CThread::GetConfiguration()->address2,(void*)p,len);

	}


}

void SetBrokerUserId(short index,unsigned char *p, unsigned char len){

	if (0==index)
	{
		memset((void*)CThread::GetConfiguration()->userId1,0,sizeof(CThread::GetConfiguration()->userId1));
		memcpy((void*)CThread::GetConfiguration()->userId1,(void*)p,len);
	}

	else{
		memset((void*)CThread::GetConfiguration()->userId2,0,sizeof(CThread::GetConfiguration()->userId2));
		memcpy((void*)CThread::GetConfiguration()->userId2,(void*)p,len);

	}

}

void SetBrokerPassword(short index,unsigned char *p, unsigned char len){

	if (0==index)
	{
		memset((void*)CThread::GetConfiguration()->password1,0,sizeof(CThread::GetConfiguration()->password1));
		memcpy((void*)CThread::GetConfiguration()->password1,(void*)p,len);

	}
	else{

		memset((void*)CThread::GetConfiguration()->password2,0,sizeof(CThread::GetConfiguration()->password2));
		memcpy((void*)CThread::GetConfiguration()->password2,(void*)p,len);

	}

}


void SetBrokerPort(short index,unsigned short port){

	if (0==index)
	{
		CThread::GetConfiguration()->port1 = port;
	}
	else{

		CThread::GetConfiguration()->port2 = port;
	}

}

