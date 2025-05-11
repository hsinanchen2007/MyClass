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
	char level = 'C';
	
//	switch (level)
//	{
//		case 'A':
//			printf("Excellent");
//			break;
//		case 'B':
//			printf("Good");
//			break;
//		case 'C':
//			printf("Fair");
//			break;
//		case 'D':
//			printf("Poor");
//			break;
//		default:
//			printf("Invalid value");
//			break;
//	}
	if (level == 'A')
	{
		printf("Excellent");
	}
	else if (level == 'B')
	{
		printf("Good");
	}
	else if (level == 'C')
	{
		printf("Fair");
	}
	else if (level == 'D')
	{
		printf("Poor");
	}
	else
	{
		printf("Invalid value");
	}

	return 0;
}
