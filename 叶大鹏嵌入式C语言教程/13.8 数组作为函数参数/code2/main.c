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

void Exch(int32_t nums[], int32_t res[], uint32_t n)
{
	for (uint32_t i = 0; i < n; i++) 
	{
		res[2 * i] = nums[i];
		res[2 * i + 1] = nums[i + n];
	}
}
int main(void)
{
	int32_t nums[] = {1,2,3,4,4,3,2,1}, n = 4;
	int32_t res[2 * n];

	Exch(nums, res, n);
	for (uint32_t i = 0; i < 2 * n; i++)
	{
		printf("%d, ", res[i]);
	}
	printf("\n");
}
