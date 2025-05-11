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

void Sum(void)
{
	volatile int32_t nums[254];
	nums[253] = 50;
	
	volatile int32_t x = 100, y = 200;
	volatile int32_t sum;

	sum = x + y;
}

int32_t g_test = 100;

int main(void)
{
	Sum();
	printf("g_test = %d.\n", g_test);
	return 0;
}
