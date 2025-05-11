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

typedef  struct 
{
	uint32_t id;
	uint8_t humi;
	float temp;
} TempHumiSensor;

int main()
{
	TempHumiSensor tempHumiData;
	TempHumiSensor *tempHumiPtr;
	tempHumiPtr = &tempHumiData;
	tempHumiPtr->temp = 20.5f;
	printf("&tempHumiData = 0x%p, &tempHumiPtr = 0x%p.\n", &tempHumiData, &tempHumiPtr);
	printf("&tempHumiData.temp = 0x%p, &tempHumiPtr->temp = 0x%p.\n", &tempHumiData.temp, &tempHumiPtr->temp);
	(*tempHumiPtr).temp = 21.5f;
	return 0;
}
