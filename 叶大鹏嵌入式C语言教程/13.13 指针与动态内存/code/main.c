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

uint8_t *MemTest(void)
{
	uint8_t *p = (uint8_t *)malloc(4);
	if (p == NULL)
	{
		printf("malloc for p failed!\n");
		return NULL;
	}
	return p;
}

int main(void)
{
	uint8_t *m = MemTest();
	if (m == NULL)
	{
		printf("malloc for m failed!\n");
		return -1;
	}
	m[0] = 0x05;
	m[1] = 0x06;
	free(m);
	m = NULL;
	return 0;
}

/*
int main(void)
{
	uint8_t *p = (uint8_t *)malloc(4);
	if (p == NULL)
	{
		printf("malloc for p failed!\n");
		return -1;
	}
	p[0] = 0x01;
	p[1] = 0x02;
	p[2] = 0x03;
	p[3] = 0x04;
	free(p);
	p = NULL;
	
	uint8_t *m = (uint8_t *)malloc(4);
	if (m == NULL)
	{
		printf("malloc for m failed!\n");
		return -1;
	}
	m[0] = 0x05;
	m[1] = 0x06;
	m[2] = 0x07;
	m[3] = 0x08;
	
	p[0] = 0x01;
	p[1] = 0x02;
	p[2] = 0x03;
	p[3] = 0x04;

	return 0;
}
*/
