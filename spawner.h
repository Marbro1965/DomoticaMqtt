/*
 * spawner.h
 *
 *  Created on: 17/mar/2016
 *      Author: marrelli
 */

#ifndef DOMOTICAMQTT_SPAWNER_H_
#define DOMOTICAMQTT_SPAWNER_H_


#ifdef __cplusplus
extern "C" {
#endif

void* udpThread;

void* tcpServerThread;

void* ioThread;

void* mqttThread;

void* httpServerThread;

void initThreadsPointer();

void initUdpThread();

void initServerThread();

void initIOThread();

void initClientThread(void*);

void initMqttClient();

void initDefinitionsThread();

void initHTTPServerThread();

void terminateThreads();

signed char* GetSecurityKey();

void SetSecurityKey(signed char*, unsigned char len);

int GetSecurityKeyLen();

int GetSecurityType();

void SetSecurityType(int);

char* GetSSIDName();

void SetSSIDName(unsigned char*,unsigned char len);

char* GetBrokerAddress(short index);

char* GetBrokerUserId(short index);

char* GetBrokerPassword(short index);

unsigned short GetBrokerPort(short index);

char* GetBrokerPublishEntry();

char* GetBrokerSubscribeEntry();

void SetBrokerPublishEntry(unsigned char *, unsigned char len);

void SetBrokerSubscribeEntry(unsigned char *, unsigned char len);

void SetBrokerAddress(short index,unsigned char *, unsigned char len);

void SetBrokerUserId(short index,unsigned char *, unsigned char len);

void SetBrokerPassword(short index,unsigned char *, unsigned char len);

void SetBrokerPort(short index,unsigned short port);





#ifdef __cplusplus
}
#endif /*  __cplusplus */


#endif /* DOMOTICAMQTT_SPAWNER_H_ */
