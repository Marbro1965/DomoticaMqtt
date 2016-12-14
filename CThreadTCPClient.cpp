/*
 * CThreadTCPClient.cpp
 *
 *  Created on: 17/mar/2016
 *      Author: marrelli
 */

#include "CThreadTCPClient.h"

#include <string.h>

#include <stdio.h>

#include "simplelink.h"

CThreadTCPClient::CThreadTCPClient(int soc,int ind):CThread() {
	// TODO Auto-generated constructor stub


	sock = soc;

	isFree = true;

	index = ind;


}

CThreadTCPClient::~CThreadTCPClient() {
	// TODO Auto-generated destructor stub
	printf("Destructor called\n");
}

void CThreadTCPClient::Run(){


	int ret;
    int packetLen;
    int status;

    printf("%s %d %s","Thread nr: ", index, "\r\n");

    //Echo to the client
    packetLen = sprintf(buffer,"%s","Accepted incoming connection\r");

    status = send(sock,buffer,packetLen,0);

    if (status == -1){

    }


	while(1){

		//blocking
		ret = recv(sock,buffer,sizeof(buffer),0);

		if (0==ret)
			break;

		if (terminate)
			break;

		//echo of received character
		status = send(sock,buffer,ret,0);


	}

    isFree = true;

    close(sock);

    xSemaphoreGive(xSemaphore);

    OsiTaskHandle tHandle = NULL;

    osi_TaskDelete(&tHandle);


}

void CThreadTCPClient::Terminate()
{

	CThread::Terminate();

	close(sock);
}
