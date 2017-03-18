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

/*Defining Number of topics*/
#define TOPIC_COUNT             3


typedef struct connection_config{
	SlMqttClientCtxCfg_t broker_config;
	void *clt_ctx;
	unsigned char *client_id;
	unsigned char *usr_name;
	unsigned char *usr_pwd;
	bool is_clean;
	unsigned int keep_alive_time;
	SlMqttClientCbs_t CallBAcks;
	int num_topics;
	char *topic[TOPIC_COUNT];
	unsigned char qos[TOPIC_COUNT];
	SlMqttWill_t will_params;
	bool is_connected;
}connect_config;

class CThreadMqttClient:public CThread {


protected:

	static const char *pub_topic_sw2;

	static const char *pub_topic_sw3;

	static const char *pub_topic_sw4;

	static const char *pub_topic_sw5;

	static unsigned char *data_sw2;

	static unsigned char *data_sw3;

	static unsigned char *data_sw4;

	static unsigned char *data_sw5;

	static connect_config usr_connect_config[2];

	static SlMqttClientLibCfg_t Mqtt_Client;

	void *app_hndl;

	bool bToggle;

public:

	CThreadMqttClient();

	virtual ~CThreadMqttClient();

	void Run();

	void Terminate();

	void MqttClient(void *pvParameters);

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
