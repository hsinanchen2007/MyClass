#include <stdio.h>
#include "ARMCM4.h"   
#include <stdbool.h>
#include <stdlib.h>
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
	int32_t buffer[5] = {3, 2, 1, 5, 4};
	int32_t *ptr = buffer;
	for (uint8_t i = 0; i < 5; i++)
	{
		printf("*(buffer + %d) = %d.\n", i, *(buffer + i));
	}
	for (uint8_t i = 0; i < 5; i++)
	{
		printf("ptr[%d] = %d.\n", i, ptr[i]);
	}

	return 0;
}
