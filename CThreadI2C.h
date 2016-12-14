/*
 * CThreadIO.h
 *
 *  Created on: 24/mar/2016
 *      Author: marrelli
 */

#ifndef DOMOTICAMQTT_CTHREADI2C_H_
#define DOMOTICAMQTT_CTHREADI2C_H_

#include "CThread.h"



class CThreadI2C: public CThread{



public:

	CThreadI2C(void);

	virtual ~CThreadI2C(void);

	void Run(void);

	/*
	 *
	 *
	 */
	void ReadAccSensor(void);

};

#endif /* DOMOTICAMQTT_CTHREADI2C_H_ */
