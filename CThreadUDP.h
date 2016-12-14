/*
 * CThreadUDP.h
 *
 *  Created on: 17/mar/2016
 *      Author: marrelli
 */

#ifndef DOMOTICAMQTT_CTHREADUDP_H_
#define DOMOTICAMQTT_CTHREADUDP_H_

#include "CThread.h"

class CThreadUDP:public CThread {

protected:

	int 		port;
	char        buffer[256];


public:
	CThreadUDP( int i);
	virtual ~CThreadUDP();

	void Run();
};

#endif /* DOMOTICAMQTT_CTHREADUDP_H_ */
