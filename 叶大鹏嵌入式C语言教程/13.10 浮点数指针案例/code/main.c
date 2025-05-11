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
	uint8_t value[4] = {0x9A, 0x99, 0x99, 0x3F};  
	float *f = (float *)value;
	printf("*f = %.1f.\n", *f);
//	float f = 1.2f;
//	uint8_t *p;
//	p = (uint8_t *)&f;
//	printf("*p = %#x.\n", *p);
//	p++;
//	printf("*p = %#x.\n", *p);	
//	p++;
//	printf("*p = %#x.\n", *p);	
//	p++;
//	printf("*p = %#x.\n", *p);	
	return 0;
}
