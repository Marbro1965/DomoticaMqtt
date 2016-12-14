/*
 * CThreadTCPClient.h
 *
 *  Created on: 17/mar/2016
 *      Author: marrelli
 */

#ifndef DOMOTICAMQTT_CTHREADTCPCLIENT_H_
#define DOMOTICAMQTT_CTHREADTCPCLIENT_H_

#include "CThread.h"

#include "FreeRTOS.h"

#include "semphr.h"

class CThreadTCPClient:public CThread {

protected:
	int 			 	sock;
	bool				isFree;
	int 				index;
	char        		buffer[256];

	SemaphoreHandle_t 	xSemaphore;

public:



	CThreadTCPClient(int s,int i);
	virtual ~CThreadTCPClient();

	void Run();

	void Terminate();

	int GetIndex(){

		return index;
	}

	bool IsFree(){

		return isFree;
	}

	void SetFree(bool b){

		isFree = b;
	}

	void SetSocket(int s){

		sock = s;
	}

	void SetSemaphoreHandle(SemaphoreHandle_t sh){

		xSemaphore = sh;
	}
};

#endif /* DOMOTICAMQTT_CTHREADTCPCLIENT_H_ */
