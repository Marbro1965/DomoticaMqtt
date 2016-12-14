/*
 * CThreadTCPServer.cpp
 *
 *  Created on: 17/mar/2016
 *      Author: marrelli
 */

#include "CThreadTCPServer.h"

#include "CThreadTCPClient.h"

#include <string.h>

#include <stdio.h>

#include "simplelink.h"

#include "spawner.h"

#include "FreeRTOS.h"

#include "semphr.h"

#define MAX_ALLOWED_CONNECTIONS		2

CThreadTCPServer::CThreadTCPServer(int p) {
	// TODO Auto-generated constructor stub

	port = p;

	threadClientPool = new CThreadTCPClient*[MAX_ALLOWED_CONNECTIONS];

	for (int i = 0; i<MAX_ALLOWED_CONNECTIONS;i++)
	{
		threadClientPool[i] = new CThreadTCPClient(-1,i);
	}


}

CThreadTCPServer::~CThreadTCPServer() {
	// TODO Auto-generated destructor stub
}

void CThreadTCPServer::Run(){



    int         status;

    int         server;

    sockaddr_in localAddr;

    sockaddr_in clientAddr;

    socklen_t   addrlen = sizeof(clientAddr);

    int 		sock = -1;

    CThreadTCPClient* pThread;

    SemaphoreHandle_t xSemaphore = NULL;

    xSemaphore = xSemaphoreCreateCounting(MAX_ALLOWED_CONNECTIONS,MAX_ALLOWED_CONNECTIONS);

    //create socket
    server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server == -1) {
        printf("Error: socket not created.\n");
        goto shutdown;
    }

    //prepare sockaddr_in structure
    memset(&localAddr, 0, sizeof(localAddr));
    localAddr.sin_family = AF_INET;
    localAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    localAddr.sin_port = htons(port);

    //bind
    status = bind(server, (const sockaddr *)&localAddr, sizeof(localAddr));
    if (status == -1) {
        printf("Error: bind failed.\n");
        goto shutdown;
    }

    //Listen
    status = listen(server, MAX_ALLOWED_CONNECTIONS);
    if (status == -1){
        printf("Error: listen failed.\n");
        goto shutdown;
    }

    //wait for incoming connections
    while (1)
    {
    	//for next accept
    	sock = -1;

    	//accept incoming connection
    	sock = accept(server, (sockaddr *)&clientAddr, &addrlen);

        if (sock == -1){
            printf("Error: listen failed.\n");
            goto shutdown;
        }

        xSemaphoreTake(xSemaphore,portMAX_DELAY);


        //spawn the new thread if less than max worker
        bool bAvailable = false;

    	for (int i = 0; i<MAX_ALLOWED_CONNECTIONS;i++)
    	{
    		if(threadClientPool[i]->IsFree())
    		{
    			threadClientPool[i]->SetFree(false);

    			threadClientPool[i]->SetSocket(sock);

    			threadClientPool[i]->SetSemaphoreHandle(xSemaphore);

    			pThread = threadClientPool[i];

    			bAvailable = true;

    			break;
    		}
    	}

    	if (!bAvailable){
    		//It should not come here because
    		//connections are limited by the semaphores
            printf("Error: listen failed.\n");
            goto shutdown;

    		}
    	else
    	{
    		//spawn the server client
    		initClientThread(pThread);
    	}


    }


shutdown:
    if (server >= 0) {
        close(server);
    }
    //clear semaphore
    //checks if all semaphores are free
    vSemaphoreDelete(xSemaphore);

    OsiTaskHandle tHandle = NULL;
    osi_TaskDelete(&tHandle);

}

void CThreadTCPServer::Terminate()
{

	CThread::Terminate();

	for (int i = 0; i<MAX_ALLOWED_CONNECTIONS;i++)
	{
		if(!threadClientPool[i]->IsFree())
		{
			threadClientPool[i]->Terminate();
		}
	}

}
