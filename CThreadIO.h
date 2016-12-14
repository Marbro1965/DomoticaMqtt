/*
 * CThreadIO.h
 *
 *  Created on: 24/mar/2016
 *      Author: marrelli
 */

#ifndef DOMOTICAMQTT_CTHREADIO_H_
#define DOMOTICAMQTT_CTHREADIO_H_

#include "CThread.h"



class CThreadIO: public CThread{


public:

	CThreadIO();

	virtual ~CThreadIO();

	void Run();

	/*
	 *
	 *
	 *
	 */

	static void pushButtonInterruptHandler2();

	static void pushButtonInterruptHandler3();

};

#endif /* DOMOTICAMQTT_CTHREADIO_H_ */
