/*
 * CThreadIO.cpp
 *
 *  Created on: 24/mar/2016
 *      Author: marrelli
 */

#include "CThreadIO.h"

#include "button_if.h"

CThreadIO::CThreadIO() {
	// TODO Auto-generated constructor stub

	/*
	 * Create Message Queue
	 */
    osi_MsgQCreate(&g_PBQueue,"PBQueue",sizeof(osi_messages),10);


}

CThreadIO::~CThreadIO() {
	// TODO Auto-generated destructor stub
}


void CThreadIO::Run()
{

    //
    // Register Push Button Handlers
    //
    Button_IF_Init(CThreadIO::pushButtonInterruptHandler2,CThreadIO::pushButtonInterruptHandler3);

    for (;;)
    {

    	osi_Sleep(1000);
    }

}


//****************************************************************************
//
//! Push Button Handler1(GPIOS2). Press push button2 (GPIOSW2) Whenever user
//! wants to publish a message. Write message into message queue signaling the
//!    event publish messages
//!
//! \param none
//!
//! return none
//
//****************************************************************************
void CThreadIO::pushButtonInterruptHandler2()
{
    osi_messages var = PUSH_BUTTON_SW2_PRESSED;
    //
    // write message indicating publish message
    //
    osi_MsgQWrite(&g_PBQueue,&var,OSI_NO_WAIT);
}

//****************************************************************************
//
//! Push Button Handler3(GPIOS3). Press push button3 (GPIOSW3) Whenever user
//! wants to publish a message. Write message into message queue signaling the
//!    event publish messages
//!
//! \param none
//!
//! return none
//
//****************************************************************************
void CThreadIO::pushButtonInterruptHandler3()
{
    osi_messages var = PUSH_BUTTON_SW3_PRESSED;
    //
    // write message indicating exit from sending loop
    //
    osi_MsgQWrite(&g_PBQueue,&var,OSI_NO_WAIT);

}
