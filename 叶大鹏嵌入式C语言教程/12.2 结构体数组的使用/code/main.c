#include <stdio.h>
#include "ARMCM4.h"   
#include "tem.h"
#include "co2.h"
#include "pm25.h"

#define TEM_SENSOR_NUM  3
#define TEM_DATA_NUM    5

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

int main(void)
{
	SetTemCof(GetTemCofHmi());

	TempHumiSensor tempHumiData[TEM_SENSOR_NUM] = {
													{0x1234, 0, 0},
													{0x2345, 0, 0},
													{0x3456, 0, 0}
												  };
	for (uint8_t i = 0; i < TEM_SENSOR_NUM; i++)
	{											  
		tempHumiData[i].temp = GetCelTem(tempHumiData[i].id);
		tempHumiData[i].humi = GetHumiData(tempHumiData[i].id);

		printf("sensor 0x%x, temp = %.1f, humi = %d.\n", 
				tempHumiData[i].id, tempHumiData[i].temp, tempHumiData[i].humi);
	}
	QualityLevel co2Level;
	co2Level = GetCo2Level();
	DisplayCo2Level(co2Level);
	
	QualityLevel pm25Level;
	pm25Level = GetPm25Level();
	DisplayPm25Level(pm25Level);
	return 0;
}
