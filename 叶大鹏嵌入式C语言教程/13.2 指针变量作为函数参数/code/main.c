#include <stdio.h>
#include "ARMCM4.h"   
#include "temp_humi.h"
#include "co2.h"
#include "pm25.h"

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

float GetTemCofHmi(void)
{
	return 1.2f;
}

void DisplayAirQuality(AirQuality airQuality)
{
	for (uint8_t i = 0; i < TEMP_SENSOR_NUM; i++)
	{											  
		printf("sensor 0x%x, temp = %.1f, humi = %d.\n", 
				airQuality.tempHumiData[i].id, airQuality.tempHumiData[i].temp, airQuality.tempHumiData[i].humi);
	}
	DisplayCo2Level(airQuality.co2Level);
	DisplayPm25Level(airQuality.pm25Level);
}

int main(void)
{
	float tempData = 0;
	uint8_t humiData = 0;
	
	SetTemCof(GetTemCofHmi());

	GetTempHumi(0x1234, &tempData, &humiData);
	printf("sensor 0x%x, temp = %.1f, humi = %d.\n", 0x1234, tempData, humiData);
	return 0;
}
