/*
 * CThreadTCPServer.h
 *
 *  Created on: 17/mar/2016
 *      Author: marrelli
 */

#ifndef DOMOTICAMQTT_CTHREADTCPSERVER_H_
#define DOMOTICAMQTT_CTHREADTCPSERVER_H_

#include "CThread.h"

class  CThreadTCPClient;

class CThreadTCPServer:public CThread {

protected:

	int 				port;

	CThreadTCPClient** threadClientPool;

public:
	CThreadTCPServer(int i);

	virtual ~CThreadTCPServer();

	void Run();

	void Terminate();
};

#endif /* DOMOTICAMQTT_CTHREADTCPSERVER_H_ */
