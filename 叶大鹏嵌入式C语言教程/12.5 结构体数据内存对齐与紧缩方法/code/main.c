#include <stdio.h>
#include "ARMCM4.h"   
#include <stdbool.h>
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

#pragma  pack (1) 
typedef  struct
{
	uint8_t id;
	uint8_t humi1;
	double temp;
	uint8_t humi2;
} TempHumiSensor;
#pragma pack()


typedef struct
{
	uint8_t  co2Level;
	TempHumiSensor tempHumiData;
	double  pm25Level;
} AirQuality;


int main()
{
	printf("sizeof(TempHumiSensor) = %d.\n", sizeof(TempHumiSensor));
	printf("sizeof(AirQuality) = %d.\n", sizeof(AirQuality));
	return 0;
}
