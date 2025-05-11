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

int main(void)
{
//	volatile float temp = 20.1234f;
//	//volatile double temp = 20.5;
//	if (temp == 20.1234f)
//	{
//		printf("temp == 20.5 \n");
//	}
//	temp = temp * 1.2 + 25;
	
//	int8_t i1 = 1, i2 = 4;  
//    volatile float f;  
//    f = (float)i1 / (float)i2;
	float f1 = 1.123f, f2 = 1.345f;
	float f3 = f1 + f2;
	if (f3 == 2.468)
	{
		printf("f3 == 2.68 \n");
	}
	return 0;
}
	//printf("sizeof(float) = %d, sizeof(double) = %d \n", sizeof(long double), sizeof(double));
//	uint8_t val1 = 10;
//	uint8_t val2 = 100 - val1;
//	for (uint8_t i = 0; i < 100; i++)
//	{
//	
//	}
//	*(uint8_t *)0x20000400 = 0x64;