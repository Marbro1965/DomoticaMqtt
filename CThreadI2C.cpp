/*
 * CThreadIO.cpp
 *
 *  Created on: 24/mar/2016
 *      Author: marrelli
 */

#include "CThreadI2C.h"

#include "stdlib.h"

#include "bma222drv.h"

#include "tmp006drv.h"

#include "i2c_if.h"

CThreadI2C::CThreadI2C() {
	// TODO Auto-generated constructor stub

	/*
	 * Create Message Queue
	 */
    //osi_MsgQCreate(&g_I2CQueue,"I2CQueue",sizeof(osi_messages),10);


}

CThreadI2C::~CThreadI2C() {
	// TODO Auto-generated destructor stub
}


void CThreadI2C::Run()
{

	long   lRetVal = -1;
	/*
	Legge la temperatura
	
	Posta la temperatura
	
	Legge l'accelerazione
	
	Posta l'accelerazione
	*/

    //
    // I2C Init
    //
    lRetVal = I2C_IF_Open(I2C_MASTER_MODE_FST);
    if(lRetVal < 0)
    {
        //ERR_PRINT(lRetVal);
        //LOOP_FOREVER();
    }

    //Init Temprature Sensor
    lRetVal = TMP006DrvOpen();
    if(lRetVal < 0)
    {
        //ERR_PRINT(lRetVal);
        //LOOP_FOREVER();
    }

    //Init Accelerometer Sensor
    lRetVal = BMA222Open();
    if(lRetVal < 0)
    {
        //ERR_PRINT(lRetVal);
        //LOOP_FOREVER();
    }


    for (;;)
    {

        TMP006DrvGetTemp(&fCurrentTemp);

    	osi_Sleep(100);

        ReadAccSensor();

    	osi_Sleep(100);

        osi_messages var = TEMPERATURE_READ;
        //
        // write message indicating publish message
        //
        osi_MsgQWrite(&CThread::g_PBQueue,&var,OSI_NO_WAIT);

    	osi_Sleep(1000);
		
    }

}





//*****************************************************************************
//
//! ReadAccSensor
//!
//!    @brief  Read Accelerometer Data from Sensor
//!
//!
//!     @return none
//!
//!
//
//*****************************************************************************
void CThreadI2C::ReadAccSensor()
{
    //Define Accelerometer Threshold to Detect Movement
    const short csAccThreshold    = 5;

    signed char cAccXT1,cAccYT1,cAccZT1;
    signed char cAccXT2,cAccYT2,cAccZT2;
    signed short sDelAccX, sDelAccY, sDelAccZ;
    int iRet = -1;
    int iCount = 0;

    iRet = BMA222ReadNew(&cAccXT1, &cAccYT1, &cAccZT1);
    if(iRet)
    {
        //In case of error/ No New Data return
        return;
    }
    for(iCount=0;iCount<2;iCount++)
    {

    	//inserire un delay
    	osi_Sleep(200);

        iRet = BMA222ReadNew(&cAccXT2, &cAccYT2, &cAccZT2);

        if(iRet)
        {
            //In case of error/ No New Data continue
            iRet = 0;
            continue;
        }

        else
        {
            sDelAccX = abs((signed short)cAccXT2 - (signed short)cAccXT1);
            sDelAccY = abs((signed short)cAccYT2 - (signed short)cAccYT1);
            sDelAccZ = abs((signed short)cAccZT2 - (signed short)cAccZT1);

            //Compare with Pre defined Threshold
            if(sDelAccX > csAccThreshold || sDelAccY > csAccThreshold ||
               sDelAccZ > csAccThreshold)
            {
                //Device Movement Detected, Break and Return
                g_ucDryerRunning = 1;
                break;
            }
            else
            {
                //Device Movement Static
                g_ucDryerRunning = 0;
            }
        }
    }

}

