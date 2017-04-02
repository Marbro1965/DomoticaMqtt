/*
 * CThreadHTTPServer.cpp
 *
 *  Created on: 17/mar/2016
 *      Author: marrelli
 */

#include "CThreadHTTPServer.h"

#include "CThreadDefinitions.h"

#include <string.h>

#include <stdio.h>

#include <stdlib.h>

#include "simplelink.h"

#include "spawner.h"

#include "FreeRTOS.h"

#include "semphr.h"

#define MAX_ALLOWED_CONNECTIONS		2

//////////////////////TOKEN Get

#define TOKEN_G_SSID				"__SL_G_U01"

#define TOKEN_G_PASSWORD			"__SL_G_U03"

#define TOKEN_G_SECURITY			"__SL_G_U02"

#define TOKEN_G_ADDRESS_BROKER_1	"__SL_G_U05"

#define TOKEN_G_USER_ID_1			"__SL_G_U07"

#define TOKEN_G_PASSWORD_1			"__SL_G_U08"

#define TOKEN_G_PORT_1				"__SL_G_U11"

#define TOKEN_G_ADDRESS_BROKER_2	"__SL_G_U06"

#define TOKEN_G_USER_ID_2			"__SL_G_U09"

#define TOKEN_G_PASSWORD_2			"__SL_G_U10"

#define TOKEN_G_PORT_2				"__SL_G_U12"

#define TOKEN_G_ENTRY_PUBLISH       "__SL_G_U13"

#define TOKEN_G_ENTRY_SUBSCRIBE     "__SL_G_U14"

/////////////////////Token Post

#define TOKEN_P_SSID				"__SL_P_U01"

#define TOKEN_P_PASSWORD			"__SL_P_U03"

#define TOKEN_P_SECURITY			"__SL_P_U02"

#define TOKEN_P_ADDRESS_BROKER_1	"__SL_P_U05"

#define TOKEN_P_USER_ID_1			"__SL_P_U07"

#define TOKEN_P_PASSWORD_1			"__SL_P_U08"

#define TOKEN_P_PORT_1				"__SL_P_U11"

#define TOKEN_P_ADDRESS_BROKER_2	"__SL_P_U06"

#define TOKEN_P_USER_ID_2			"__SL_P_U09"

#define TOKEN_P_PASSWORD_2			"__SL_P_U10"

#define TOKEN_P_PORT_2				"__SL_P_U12"

#define TOKEN_P_ENTRY_PUBLISH       "__SL_P_U13"

#define TOKEN_P_ENTRY_SUBSCRIBE     "__SL_P_U14"

///variabile di trigger complex post

int triggerPost = 0;

CThreadHTTPServer::CThreadHTTPServer() {
	
	// TODO Auto-generated constructor stub



}

CThreadHTTPServer::~CThreadHTTPServer() {
	// TODO Auto-generated destructor stub
}

void CThreadHTTPServer::Run(){

	long lRetVal = -1;

    //Stop Internal HTTP Server
    lRetVal = sl_NetAppStop(SL_NET_APP_HTTP_SERVER_ID);
    if(lRetVal < 0)
    {
        ;//LOOP_FOREVER();
    }


    //Start Internal HTTP Server
    lRetVal = sl_NetAppStart(SL_NET_APP_HTTP_SERVER_ID);
    if(lRetVal < 0)
    {
        ;//LOOP_FOREVER();
    }

    while(1)
    {

    	osi_Sleep(10);

    	//handle message
    	my_message RecvQue;
	    osi_MsgQRead( &CThread::g_FileWriteQueue, &RecvQue, OSI_NO_WAIT);
	    if(SAVE_POST_DATA == RecvQue.ulmessage)
	    	{
	    	CThreadDefinitions::outputFile();
	    	}


    };



}

void CThreadHTTPServer::Terminate()
{

	CThread::Terminate();


}


//*****************************************************************************
//
//! This function gets triggered when HTTP Server receives Application
//! defined GET and POST HTTP Tokens.
//!
//! \param pHttpServerEvent Pointer indicating http server event
//! \param pHttpServerResponse Pointer indicating http server response
//!
//! \return None
//!
//*****************************************************************************
void SimpleLinkHttpServerCallback(SlHttpServerEvent_t *pSlHttpServerEvent,
                               SlHttpServerResponse_t *pSlHttpServerResponse)
{
    unsigned char strLenVal = 0;

    if(!pSlHttpServerEvent || !pSlHttpServerResponse)
    {
        return;
    }

    switch (pSlHttpServerEvent->Event)
    {
        case SL_NETAPP_HTTPGETTOKENVALUE_EVENT:
        {

          unsigned char *ptr;

          triggerPost = 0;
          ///////////////SECURITY

          ptr = pSlHttpServerResponse->ResponseData.token_value.data;
          pSlHttpServerResponse->ResponseData.token_value.len = 0;
          if(memcmp(pSlHttpServerEvent->EventData.httpTokenName.data, TOKEN_G_SSID,
                    strlen((const char *)TOKEN_G_SSID)) == 0)
          {
            strLenVal = strlen(GetSSIDName());
            memcpy(ptr, GetSSIDName(), strLenVal);
            ptr += strLenVal;
            pSlHttpServerResponse->ResponseData.token_value.len += strLenVal;
            *ptr = '\0';
          }
          if(memcmp(pSlHttpServerEvent->EventData.httpTokenName.data, TOKEN_G_PASSWORD,
                    strlen((const char *)TOKEN_G_PASSWORD)) == 0)
          {
            strLenVal = strlen((char*)GetSecurityKey());
            memcpy(ptr, GetSecurityKey(), strLenVal);
            ptr += strLenVal;
            pSlHttpServerResponse->ResponseData.token_value.len += strLenVal;
            *ptr = '\0';
          }

          if(memcmp(pSlHttpServerEvent->EventData.httpTokenName.data, TOKEN_G_SECURITY,
                    strlen((const char *)TOKEN_G_SECURITY)) == 0)
          {
        	int st = GetSecurityType();
        	char buffer[2];
        	int i = sprintf(buffer,"%d",st);
            memcpy(ptr,buffer , i);
            ptr += i;
            pSlHttpServerResponse->ResponseData.token_value.len += i;
            *ptr = '\0';
          }
          ///////////////BROKER 1
          if(memcmp(pSlHttpServerEvent->EventData.httpTokenName.data, TOKEN_G_ADDRESS_BROKER_1,
                    strlen((const char *)TOKEN_G_ADDRESS_BROKER_1)) == 0)
          {
            strLenVal = strlen((char*)GetBrokerAddress(0));
            memcpy(ptr, GetBrokerAddress(0), strLenVal);
            ptr += strLenVal;
            pSlHttpServerResponse->ResponseData.token_value.len += strLenVal;
            *ptr = '\0';
          }

          if(memcmp(pSlHttpServerEvent->EventData.httpTokenName.data, TOKEN_G_USER_ID_1,
                    strlen((const char *)TOKEN_G_USER_ID_1)) == 0)
          {
            strLenVal = strlen((char*)GetBrokerUserId(0));
            memcpy(ptr, GetBrokerUserId(0), strLenVal);
            ptr += strLenVal;
            pSlHttpServerResponse->ResponseData.token_value.len += strLenVal;
            *ptr = '\0';
          }

          if(memcmp(pSlHttpServerEvent->EventData.httpTokenName.data, TOKEN_G_PASSWORD_1,
                    strlen((const char *)TOKEN_G_PASSWORD_1)) == 0)
          {
            strLenVal = strlen((char*)GetBrokerPassword(0));
            memcpy(ptr, GetBrokerPassword(0), strLenVal);
            ptr += strLenVal;
            pSlHttpServerResponse->ResponseData.token_value.len += strLenVal;
            *ptr = '\0';
          }
          if(memcmp(pSlHttpServerEvent->EventData.httpTokenName.data, TOKEN_G_PORT_1,
                    strlen((const char *)TOKEN_G_PORT_1)) == 0)
          {
        	unsigned short us = GetBrokerPort(0);
        	char buffer[5];
        	int i = sprintf(buffer,"%d",us);
            memcpy(ptr,buffer, i);
            ptr += i;
            pSlHttpServerResponse->ResponseData.token_value.len += i;
            *ptr = '\0';
          }



          //////////////BROKER 2

          if(memcmp(pSlHttpServerEvent->EventData.httpTokenName.data, TOKEN_G_ADDRESS_BROKER_2,
                    strlen((const char *)TOKEN_G_ADDRESS_BROKER_2)) == 0)
          {
            strLenVal = strlen((char*)GetBrokerAddress(1));
            memcpy(ptr, GetBrokerAddress(1), strLenVal);
            ptr += strLenVal;
            pSlHttpServerResponse->ResponseData.token_value.len += strLenVal;
            *ptr = '\0';
          }

          if(memcmp(pSlHttpServerEvent->EventData.httpTokenName.data, TOKEN_G_USER_ID_2,
                    strlen((const char *)TOKEN_G_USER_ID_2)) == 0)
          {
            strLenVal = strlen((char*)GetBrokerUserId(1));
            memcpy(ptr, GetBrokerUserId(1), strLenVal);
            ptr += strLenVal;
            pSlHttpServerResponse->ResponseData.token_value.len += strLenVal;
            *ptr = '\0';
          }

          if(memcmp(pSlHttpServerEvent->EventData.httpTokenName.data, TOKEN_G_PASSWORD_2,
                    strlen((const char *)TOKEN_G_PASSWORD_2)) == 0)
          {
            strLenVal = strlen((char*)GetBrokerPassword(1));
            memcpy(ptr, GetBrokerPassword(1), strLenVal);
            ptr += strLenVal;
            pSlHttpServerResponse->ResponseData.token_value.len += strLenVal;
            *ptr = '\0';
          }
          if(memcmp(pSlHttpServerEvent->EventData.httpTokenName.data, TOKEN_G_PORT_2,
                    strlen((const char *)TOKEN_G_PORT_2)) == 0)
          {
        	unsigned short us = GetBrokerPort(1);
        	char buffer[5];
        	int i = sprintf(buffer,"%d",us);
            memcpy(ptr,buffer, i);
            ptr += i;
            pSlHttpServerResponse->ResponseData.token_value.len += i;
            *ptr = '\0';
          }

          /////////////////////// ENTRY
          if(memcmp(pSlHttpServerEvent->EventData.httpTokenName.data, TOKEN_G_ENTRY_PUBLISH,
                    strlen((const char *)TOKEN_G_ENTRY_PUBLISH)) == 0)
          {
              strLenVal = strlen((char*)GetBrokerPublishEntry());
              memcpy(ptr, GetBrokerPublishEntry(), strLenVal);
              ptr += strLenVal;
              pSlHttpServerResponse->ResponseData.token_value.len += strLenVal;
              *ptr = '\0';
          }

          if(memcmp(pSlHttpServerEvent->EventData.httpTokenName.data, TOKEN_G_ENTRY_SUBSCRIBE,
                    strlen((const char *)TOKEN_G_ENTRY_SUBSCRIBE)) == 0)
          {
              strLenVal = strlen((char*)GetBrokerSubscribeEntry());
              memcpy(ptr, GetBrokerSubscribeEntry(), strLenVal);
              ptr += strLenVal;
              pSlHttpServerResponse->ResponseData.token_value.len += strLenVal;
              *ptr = '\0';
          }


        }
        break;

        case SL_NETAPP_HTTPPOSTTOKENVALUE_EVENT:
        {

          unsigned char *ptr = pSlHttpServerEvent->EventData.httpPostData.token_name.data;

          unsigned char *action = pSlHttpServerEvent->EventData.httpPostData.action.data;

          if(memcmp(action,
        		  "/ssid_view", strlen((const char *)"/ssid_view")) == 0)
          {
              if(memcmp(ptr, TOKEN_P_SSID, strlen((const char *)TOKEN_P_SSID)) == 0)
              {
                ptr = pSlHttpServerEvent->EventData.httpPostData.token_value.data;
                strLenVal = pSlHttpServerEvent->EventData.httpPostData.token_value.len;
                SetSSIDName(ptr,strLenVal);

                triggerPost++;
            	}

              if(memcmp(ptr, TOKEN_P_PASSWORD, strlen((const char *)TOKEN_P_PASSWORD)) == 0)
              {
                ptr = pSlHttpServerEvent->EventData.httpPostData.token_value.data;
                strLenVal = pSlHttpServerEvent->EventData.httpPostData.token_value.len;
                SetSecurityKey((signed char*)ptr,strLenVal);

                triggerPost++;
            	}

              if(memcmp(ptr, TOKEN_P_SECURITY, strlen((const char *)TOKEN_P_SECURITY)) == 0)
              {
                ptr = pSlHttpServerEvent->EventData.httpPostData.token_value.data;
                strLenVal = pSlHttpServerEvent->EventData.httpPostData.token_value.len;
                char secKey[2];
                memset(secKey,0,sizeof(secKey));
                memcpy(&secKey,ptr,strLenVal);
                int i = atoi((const char*)secKey);
                SetSecurityType(i);

                triggerPost++;
            	}

              if (3==triggerPost)
              {

            	  //create queue message
            	  my_message var;

            	  var.ulmessage= SAVE_POST_DATA;
            	  //
            	  // write message indicating publish message
            	  //
            	  osi_MsgQWrite(&CThread::g_FileWriteQueue,&var,OSI_NO_WAIT);

            	  triggerPost = 0;

            	  osi_Sleep(10);
              }
          }
          //////////////////////////// BROKER 1,2
          if(memcmp(action,
            		  "/broker_view", strlen((const char *)"/broker_view")) == 0)
              {
                  if(memcmp(ptr, TOKEN_P_ADDRESS_BROKER_1, strlen((const char *)TOKEN_P_ADDRESS_BROKER_1)) == 0)
                  {
                    ptr = pSlHttpServerEvent->EventData.httpPostData.token_value.data;
                    strLenVal = pSlHttpServerEvent->EventData.httpPostData.token_value.len;
                    SetBrokerAddress(0,ptr,strLenVal);
                    triggerPost++;
                	}

                  if(memcmp(ptr, TOKEN_P_ADDRESS_BROKER_2, strlen((const char *)TOKEN_P_ADDRESS_BROKER_2)) == 0)
                  {
                    ptr = pSlHttpServerEvent->EventData.httpPostData.token_value.data;
                    strLenVal = pSlHttpServerEvent->EventData.httpPostData.token_value.len;
                    SetBrokerAddress(1,ptr,strLenVal);
                    triggerPost++;
                	}

                  if(memcmp(ptr, TOKEN_P_USER_ID_1, strlen((const char *)TOKEN_P_USER_ID_1)) == 0)
                  {
                    ptr = pSlHttpServerEvent->EventData.httpPostData.token_value.data;
                    strLenVal = pSlHttpServerEvent->EventData.httpPostData.token_value.len;
                    SetBrokerUserId(0,ptr,strLenVal);
                    triggerPost++;
                	}

                  if(memcmp(ptr, TOKEN_P_USER_ID_2, strlen((const char *)TOKEN_P_USER_ID_2)) == 0)
                  {
                    ptr = pSlHttpServerEvent->EventData.httpPostData.token_value.data;
                    strLenVal = pSlHttpServerEvent->EventData.httpPostData.token_value.len;
                    SetBrokerUserId(1,ptr,strLenVal);
                    triggerPost++;
                	}

                  if(memcmp(ptr, TOKEN_P_PASSWORD_1, strlen((const char *)TOKEN_P_PASSWORD_1)) == 0)
                  {
                    ptr = pSlHttpServerEvent->EventData.httpPostData.token_value.data;
                    strLenVal = pSlHttpServerEvent->EventData.httpPostData.token_value.len;
                    SetBrokerPassword(1,ptr,strLenVal);
                    triggerPost++;
                	}

                  if(memcmp(ptr, TOKEN_P_PASSWORD_2, strlen((const char *)TOKEN_P_PASSWORD_2)) == 0)
                  {
                    ptr = pSlHttpServerEvent->EventData.httpPostData.token_value.data;
                    strLenVal = pSlHttpServerEvent->EventData.httpPostData.token_value.len;
                    SetBrokerPassword(1,ptr,strLenVal);
                    triggerPost++;
                	}

                  if(memcmp(ptr, TOKEN_P_PORT_1, strlen((const char *)TOKEN_P_PORT_1)) == 0)
                  {
                    ptr = pSlHttpServerEvent->EventData.httpPostData.token_value.data;
                    strLenVal = pSlHttpServerEvent->EventData.httpPostData.token_value.len;

                    char port[5];
                    memset(port,0,sizeof(port));
                    memcpy(&port,ptr,strLenVal);
                    int i = atoi((const char*)port);
                    SetBrokerPort(0,i);

                    triggerPost++;
                	}

                  if(memcmp(ptr, TOKEN_P_PORT_2, strlen((const char *)TOKEN_P_PORT_2)) == 0)
                  {
                    ptr = pSlHttpServerEvent->EventData.httpPostData.token_value.data;
                    strLenVal = pSlHttpServerEvent->EventData.httpPostData.token_value.len;

                    char port[5];
                    memset(port,0,sizeof(port));
                    memcpy(&port,ptr,strLenVal);
                    int i = atoi((const char*)port);
                    SetBrokerPort(1,i);

                    triggerPost++;
                	}

                  if (8==triggerPost)
                  {

                	  //create queue message
                	  my_message var;

                	  var.ulmessage = SAVE_POST_DATA;
                	  //
                	  // write message indicating publish message
                	  //
                	  osi_MsgQWrite(&CThread::g_FileWriteQueue,&var,OSI_NO_WAIT);

                	  triggerPost = 0;

                	  osi_Sleep(10);
                  }

              }
          if(memcmp(action,
            		  "/topic_view", strlen((const char *)"/topic_view")) == 0)
          {
              if(memcmp(ptr, TOKEN_P_ENTRY_PUBLISH, strlen((const char *)TOKEN_P_ENTRY_PUBLISH)) == 0)
              {
                ptr = pSlHttpServerEvent->EventData.httpPostData.token_value.data;
                strLenVal = pSlHttpServerEvent->EventData.httpPostData.token_value.len;
                SetBrokerPublishEntry(ptr,strLenVal);
                triggerPost++;
            	}

              if(memcmp(ptr, TOKEN_P_ENTRY_SUBSCRIBE, strlen((const char *)TOKEN_P_ENTRY_SUBSCRIBE)) == 0)
              {
                ptr = pSlHttpServerEvent->EventData.httpPostData.token_value.data;
                strLenVal = pSlHttpServerEvent->EventData.httpPostData.token_value.len;
                SetBrokerSubscribeEntry(ptr,strLenVal);
                triggerPost++;
            	}

              if (2==triggerPost)
              {

            	  //create queue message
            	  my_message var;

            	  var.ulmessage = SAVE_POST_DATA;
            	  //
            	  // write message indicating publish message
            	  //
            	  osi_MsgQWrite(&CThread::g_FileWriteQueue,&var,OSI_NO_WAIT);

            	  triggerPost = 0;

            	  osi_Sleep(10);
              }


          }


        }
          break;
        default:
          break;
    }
}
