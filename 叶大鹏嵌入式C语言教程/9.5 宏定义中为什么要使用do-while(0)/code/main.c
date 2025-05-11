#include <stdio.h>
#include "ARMCM4.h"   

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

#define EXCH(x ,y) 	do { \
		int32_t tmp; \
		tmp = x; \
		x = y; \
		y = tmp;    \
} while (0)

int main(void)
{	
	int32_t x = 9, y = 10;
	
	if (x < y)
		//EXCH(x ,y);
		do { \
			int32_t tmp; \
			tmp = x; \
			x = y; \
			y = tmp;    \
		} while (0);
	else
	{
		printf("x is not smaller than y.\n");
	}
	return 0;
}
