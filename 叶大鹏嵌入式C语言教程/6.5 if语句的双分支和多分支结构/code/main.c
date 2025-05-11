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
	uint32_t co2 = 150;
    uint32_t level;

    if (co2 <= 100)
    {
        level = 1;
    }
    else if (co2  > 100 && co2 <= 200 )
    {
        level = 2;
    }
    else if (co2  > 200 && co2 <= 300 )
    {
        level = 3;
    }
    else
    {
        level = 4;
    }
//	uint32_t a = 10;
//	uint32_t b = 9;
//	uint32_t max;
//	if (a > b)
//	{
//		max = a;
//	}
//	else
//	{
//		max = b;
//	}
//	printf("max = %d\n", max);

	return 0;
}
