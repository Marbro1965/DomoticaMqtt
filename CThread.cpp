/*
 * CThread.cpp
 *
 *  Created on: 17/mar/2016
 *      Author: Marrelli
 */

#include "CThread.h"

OsiMsgQ_t CThread::g_PBQueue = 0;

OsiMsgQ_t CThread::g_FileWriteQueue = 0;

OsiMsgQ_t CThread::g_FileReadQueue = 0;

OsiMsgQ_t CThread::g_I2CQueue = 0;

configuration CThread::config;


float CThread::fCurrentTemp;

float CThread::fAmbientTemp;


CThread::CThread() {
	// TODO Auto-generated constructor stub

	terminate = false;

}

CThread::~CThread() {
	// TODO Auto-generated destructor stub
}

void CThread::Run()
{

	for(;;)
	{

	if (terminate)
		break;

	}

	//when thread finishes spawn callback to free resourses

}

void CThread::Exit(){



}

void CThread::Terminate(){

	terminate = true;

}
