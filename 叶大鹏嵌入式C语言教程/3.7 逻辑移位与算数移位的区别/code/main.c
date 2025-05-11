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
//	volatile int8_t a = 0x8F;
//	volatile uint8_t b = 0x8F;
//	a >>= 2;
//	b >>= 2;
	uint32_t date = 0x1413061D; 
	uint8_t day = date;
	date >>= 8;
	uint8_t month = date;
	date >>= 8;
	uint8_t year_low = date;
	date >>= 8;
	uint8_t year_high = date;
	return 0;
}







//	uint32_t date = 0x1413061D;    //00010100 00010011 00000110 00011101;
//	uint8_t  day = date;      //(计算结果是00011101，十进制表示是29，也就是日期是29)。