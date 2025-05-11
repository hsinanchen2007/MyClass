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
	uint32_t sum = 0;
	for (uint32_t i = 1, j = 100; i <= j; i++, j--)
	{
			sum += i + j;
	}
	printf("%d\n", sum);

//	for (uint8_t i = 1; i < 5; i++)
//	{
//		printf("%d", i);
//		for (uint8_t j = 1; j < i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
	return 0;
}
