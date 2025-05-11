#include <stdio.h>
#include "ARMCM4.h"   
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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
	char *fmt = (char *)malloc(strlen("malloc for m failed!\n") );
	memset(fmt, 'E', 100);
	strcpy(fmt, "malloc for m failed!\n");
	fmt[21] = 'E';
	printf("fmt = %s", fmt);

	
//	char *fmt = "malloc for m failed!\n";
//	fmt[0] = 'M';
//	printf("fmt[0] = %c, fmt[1] = %c, fmt[2] = %c\n",     
//				 fmt[0], fmt[1], fmt[2]);

	return 0;
}