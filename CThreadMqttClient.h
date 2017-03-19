/*
 * CThreadMqttClient.h
 *
 *  Created on: 17/mar/2016
 *      Author: marrelli
 */

#ifndef DOMOTICAMQTT_CTHREADMQTTCLIENT_H_
#define DOMOTICAMQTT_CTHREADMQTTCLIENT_H_

#include "CThread.h"

#include "sl_mqtt_client.h"

#include "gpio_if.h"




class CThreadMqttClient:public CThread {



public:

	CThreadMqttClient();

	virtual ~CThreadMqttClient();

	void Run();

	void Terminate();

	void MqttClient(void *pvParameters);

	void HandleMessages(void);
	/*
	 *
	 *
	 */

	static void Mqtt_Recv(void *app_hndl, const char  *topstr, long top_len, const void *payload,
	          long pay_len, bool dup,unsigned char qos, bool retain);
	static void sl_MqttEvt(void *app_hndl,long evt, const void *buf,
	                       unsigned long len);
	static void sl_MqttDisconnect(void *app_hndl);

	static void ToggleLedState(ledEnum LedNum);

	static void InitUserConnectConfig();

};

#endif /* DOMOTICAMQTT_CTHREADMQTTCLIENT_H_ */
