/*
 * CThread.cpp
 *
 *  Created on: 17/mar/2016
 *      Author: Marrelli
 */

#include "CThread.h"

#ifndef NOTERM
#include "uart_if.h"
#endif

#define UART_PRINT              Report


/*Publishing topics and messages*/
const char *CThread::pub_topic_sw2 = NULL;

const char *CThread::pub_topic_sw3 = NULL;

const char *CThread::pub_topic_sw4 = NULL;

const char *CThread::pub_topic_sw5 = NULL;

unsigned char *CThread::data_sw2=(unsigned char*)"Push button sw2 is pressed on CC32XX device";

unsigned char *CThread::data_sw3=(unsigned char*)"Push button sw3 is pressed on CC32XX device";

unsigned char *CThread::data_sw4= NULL;

unsigned char *CThread::data_sw5= NULL;

/*Background receive task priority*/
#define TASK_PRIORITY           3

connect_config CThread::usr_connect_config[2];

/* library configuration */
SlMqttClientLibCfg_t CThread::Mqtt_Client={
    1882,
    TASK_PRIORITY,
    30,
    true,
    (long(*)(const char *, ...))UART_PRINT
};


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
