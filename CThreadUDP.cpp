/*
 * CThreadUDP.cpp
 *
 *  Created on: 17/mar/2016
 *      Author: marrelli
 */

#include "CThreadUDP.h"

#include <string.h>

#include <stdio.h>

#include "simplelink.h"

CThreadUDP::CThreadUDP(int _port):CThread() {
	// TODO Auto-generated constructor stub

	port = _port;
}

CThreadUDP::~CThreadUDP() {
	// TODO Auto-generated destructor stub
}

void CThreadUDP::Run(){


    int         bytesSent;
    int         server;
    int 		lenData;

    sockaddr_in localAddr;


    SlNetCfgIpV4Args_t 	ipV4;
    unsigned char  		len = sizeof(ipV4);
    unsigned char       dhcpIsOn;

    isAlive = true;

    /* Print IP address */
    sl_NetCfgGet(SL_IPV4_STA_P2P_CL_GET_INFO, &dhcpIsOn, &len,
            (unsigned char *)&ipV4);

    /* MAC Address */
    unsigned char 		macAddressVal[SL_MAC_ADDR_LEN];
    unsigned char 		macAddressLen = SL_MAC_ADDR_LEN;
    sl_NetCfgGet(SL_MAC_ADDRESS_GET,NULL,&macAddressLen,macAddressVal);



    server = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (server == -1) {
    	//UART_PRINT("Error: socket not created.\n");
    	printf("Error: socket not created.\n");
        goto shutdown;
    }

    memset(&localAddr, 0, sizeof(localAddr));
    localAddr.sin_family = AF_INET;
    localAddr.sin_addr.s_addr = SL_IPV4_VAL(255,255,255,255);
    localAddr.sin_port = htons(port);

    memset(buffer,0,sizeof(buffer));

    lenData = sprintf(buffer,"%s %d. %d. %d. %d. %s","test UDP ",
    		SL_IPV4_BYTE(ipV4.ipV4, 3),
			SL_IPV4_BYTE(ipV4.ipV4, 2),
			SL_IPV4_BYTE(ipV4.ipV4, 1),
			SL_IPV4_BYTE(ipV4.ipV4, 0),
			"\r");

    do {

       bytesSent = sendto(server, buffer, lenData, 0,(sockaddr *)&localAddr, sizeof(localAddr));

       if (bytesSent < 0 )
       	   {
    	   printf("Error: sendto failed.\n");
           goto shutdown;

           }

       if (terminate)
    	   goto shutdown;

       osi_Sleep(1000);

       } while (bytesSent > 0);

shutdown:
    if (server >= 0) {
        close(server);
    }

    isAlive = false;
    terminate = false;

    OsiTaskHandle tHandle = NULL;
    osi_TaskDelete(&tHandle);

}
