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
	printf("sizeof(int8_t) = %d\n", sizeof(int8_t));
	printf("sizeof(int16_t) = %d\n", sizeof(int16_t));
	printf("sizeof(int32_t) = %d\n", sizeof(int32_t));
	printf("sizeof(int64_t) = %d\n", sizeof(int64_t));
	
	uint8_t a = 0;
	printf("sizeof(a) = %d\n", sizeof(a));
	return 0;
}
