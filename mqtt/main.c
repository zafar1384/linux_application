#include <stdio.h>
#include <mqtt.h>
#include <stdlib.h>
#include <unistd.h>

const char* brokerIP = "139.59.24.104";
const int port  =  1883;
const char* clientName = "Linux_APP";
const char* topic1 = "test1";



static mqtt_broker_handle_t* broker = NULL;


int main()
{
	static char uData[100];
	uint32_t i=0;
	int32_t n=0;
	
	broker = mqtt_connect( clientName, brokerIP, port );
	
	if( broker == NULL )
	{
		printf("Failed to connect to the broker...\r\n");
		exit(-1);
	}
	
	printf("Now sending the data...\r\n");
	i = 0;
	while(1)
	{
		sprintf(uData, "The data =%d", i);
		n = mqtt_publish(broker, topic1, uData, QoS0);
		
		if( n  < 0 )
		{
			printf("failed to publish the data...\r\n");
		}
		else
		{
			printf("Published data sucessfully...\r\n");
		}
		i++;
		
		sleep(3);
	}
}
