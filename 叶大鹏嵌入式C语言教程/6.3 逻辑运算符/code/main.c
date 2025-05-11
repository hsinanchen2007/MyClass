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

int main(void)
{
//	int year = 2016;
//	int daysOfFebruary;
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//	{
//		daysOfFebruary = 29;
//	}
//	else
//	{
//		daysOfFebruary = 28;
//	}
//	printf("daysOfFebruary = %d\n", daysOfFebruary);	
	uint8_t a = 10;
	uint8_t b = 9;
	if (a != 10 && ++b == 10)
	{
		printf("This is true\n");
	}
	printf("b = %d\n", b);

	return 0;
}
