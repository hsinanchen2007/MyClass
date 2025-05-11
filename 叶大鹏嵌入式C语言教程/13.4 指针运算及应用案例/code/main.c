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

int main()
{
	uint32_t date = 0x1413061D;
	uint8_t *temp;
	temp = (uint8_t *)&date;
	uint8_t day = *temp;
	temp++;
	uint8_t month = *temp;
	temp++;
	uint8_t yearLow = *temp;
	temp++;
	uint8_t yearHigh = *temp;
	printf("day = 0x%x, month = 0x%x, yearLow = 0x%x, yearHigh = 0x%x.\n",
			day, month, yearLow, yearHigh);
	return 0;
}
