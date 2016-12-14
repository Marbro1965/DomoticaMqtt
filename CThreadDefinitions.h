/*
 * CThreadDefinitions.h
 *
 *  Created on: 30/mar/2016
 *      Author: marrelli
 */

#ifndef CTHREADDEFINITIONS_H_
#define CTHREADDEFINITIONS_H_

#include "CThread.h"

#include "simplelink.h"



class CThreadDefinitions:public CThread {

public:

	CThreadDefinitions();

	virtual ~CThreadDefinitions();

	void Run();

	void Terminate();

	static long ReadFromFile(unsigned long ulToken, long lFileHandle);

	static long WriteToFile(unsigned long *ulToken, long *lFileHandle);

	static char* ini_buffer_reader(char* str, int num, void* stream);

	static int handler(void* user, const char* section, const char* name,const char* value);

	static int parseFile();

	static int outputFile();

};

#endif /* CTHREADDEFINITIONS_H_ */
