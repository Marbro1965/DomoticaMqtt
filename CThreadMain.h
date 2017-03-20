/*
 * CThreadMain.h
 *
 *  Created on: 15 mar 2017
 *      Author: Fortunato
 */

#ifndef CTHREADMAIN_H_
#define CTHREADMAIN_H_

#include "CThread.h"

class CThreadMain: public CThread {

public:
	CThreadMain();

	virtual ~CThreadMain();

	void Run();

	//
	unsigned int ReadDeviceConfiguration();
};

#endif /* CTHREADMAIN_H_ */
