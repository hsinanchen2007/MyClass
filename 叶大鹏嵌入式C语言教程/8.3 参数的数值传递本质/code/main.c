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

void Swap(int32_t x, int32_t y)
{
    int32_t temp = x;
    x = y;
    y = temp;
}

int main(void)
{
    int32_t a = 8;
    int32_t b = 9;
    Swap(a, b);
    printf("after swap, a = %d, b = %d \n", a, b);
    return 0;
}

#if 0
int32_t Sum(volatile int32_t begin, volatile int32_t end) //begin = a; end = b;
{
	int32_t sum = 0;
	for (int32_t i = begin; i <= end; i++)
	{
		sum += i;
	}
	return sum;
}

int main(void)
{
	int32_t res = 0;
	volatile int32_t a = 201;
	volatile int32_t b = 300;

	res = Sum(a, b);

	return 0;
}
#endif