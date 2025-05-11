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
	uint8_t i = 1;
	while (1)
	{
		uint8_t j = 1;
		while (1)
		{
			printf("*");
			j++;
			if (j == 6)
			{
				break;
			}
		}
		printf("\n");
		
		i++;
		if (i == 5)
		{
			break;
		}
	}
//	for (uint8_t i = 1; i <= 9; i++)
//	{
//		if (i % 3 == 0)
//		{
//			break;
//		}
//		printf("%d\n", i);
//	}
//	printf("main end.\n");
	
	return 0;
}
