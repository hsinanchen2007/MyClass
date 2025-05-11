#include <stdio.h>
#include "ARMCM4.h"   
#include "temp_humi.h"
#include "co2.h"
#include "pm25.h"
#include "wifi.h"

struct __FILE { int handle; /* Add whatever needed */ };
FILE __stdout;
FILE __stdin;
 
int fputc(int ch, FILE *f) 
{
    return ITM_SendChar(ch);
}

volatile int32_t ITM_RxBuffer = ITM_RXBUFFER_EMPTY;
int fgetc(FILE *f) 
{
    while(ITM_CheckChar() != 1)
	      __NOP();
    return (ITM_ReceiveChar());
}
int ferror(FILE *f) 
{
  /* Your implementation of ferror */
  return EOF;
}

void _ttywrch(int ch) 
{
	fputc(ch, &__stdout);
}

void _sys_exit(int return_code) 
{
  while (1);    /* endless loop */
}

void ParaseCfgParam(CfgParam *cfgParam)
{
	if (cfgParam->paramType == 1) //温度传感器校准系数
	{
		float *tempCof = (float *)cfgParam->value;
		printf("*tempCof = %.1f", *tempCof);
		SetTemCof(*tempCof);
	}
}

void DisplayTempHumi(TempHumiSensor tempHumiData[], uint32_t len)
{
	for (uint8_t i = 0; i < len; i++)
	{											  
		printf("sensor 0x%x, temp = %.1f, humi = %d.\n", 
				tempHumiData[i].id, tempHumiData[i].temp, tempHumiData[i].humi);
	}
}

void DisplayAirQuality(AirQuality *airQuality)
{
	DisplayTempHumi(airQuality->tempHumiData, TEMP_SENSOR_NUM);
	DisplayCo2Level(airQuality->co2Level);
	DisplayPm25Level(airQuality->pm25Level);
}

int main(void)
{
	CreateWifiCb(ParaseCfgParam);
	WifiHandler();
	
	AirQuality airQuality;
	airQuality.tempHumiData[0].id = 0x1234;
	airQuality.tempHumiData[1].id = 0x2345;
	airQuality.tempHumiData[2].id = 0x3456;


	for (uint8_t i = 0; i < TEMP_SENSOR_NUM; i++)
	{											  
		GetTempHumi(&airQuality.tempHumiData[i]);
	}

	airQuality.co2Level = GetCo2Level();
	airQuality.pm25Level = GetPm25Level();
	
	DisplayAirQuality(&airQuality);
	
	return 0;
}
