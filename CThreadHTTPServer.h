/*
 * CThreadHTTPServer.h
 *
 *  Created on: 17/mar/2016
 *      Author: marrelli
 */

#ifndef DOMOTICAMQTT_CTHREADHTTPSERVER_H_
#define DOMOTICAMQTT_CTHREADHTTPSERVER_H_

#include "CThread.h"

class CThreadHTTPServer:public CThread {

protected:

	
public:
	CThreadHTTPServer();

	virtual ~CThreadHTTPServer();

	void Run();

	void Terminate();
};

#endif /* DOMOTICAMQTT_CTHREADHTTPSERVER_H_ */
