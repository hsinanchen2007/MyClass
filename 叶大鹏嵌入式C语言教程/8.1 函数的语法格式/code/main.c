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

int32_t Sum(int32_t begin, int32_t end)
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
	res = Sum(1, 100);
	printf("sum of 1~100 is %d\n", res);
	
	res = Sum(201, 300);
	printf("sum of 201~300 is %d\n", res);

	res = Sum(401, 500);
	printf("sum of 401~500 is %d\n", res);

	return 0;
}
