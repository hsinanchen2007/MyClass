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
	uint32_t year = 2023;
	uint8_t month = 2;

	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("month %d has 31 days.\n", month);
			break;
		case 2: 
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			{
				printf("month %d has 29 days.\n", month);	
			}
			else
			{
				printf("month %d has 28 days.\n", month);	
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf("month %d has 30 days.\n", month);	
			break;
		default :
			printf("Invalid month\n");
			break;
	}	

//	switch (month)
//	{
//		case 1:
//			printf("month %d has 31 days.\n", month);
//			break;
//		case 2: 
//			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//			{
//				printf("month %d has 29 days.\n", month);	
//			}
//			else
//			{
//				printf("month %d has 28 days.\n", month);	
//			}
//			break;
//		case 3:
//			printf("month %d has 31 days.\n", month);	
//			break;
//		case 4:
//			printf("month %d has 30 days.\n", month);	
//			break;
//		case 5:
//			printf("month %d has 31 days.\n", month);	
//			break;
//		case 6:
//			printf("month %d has 30 days.\n", month);	
//			break;
//		case 7:
//			printf("month %d has 31 days.\n", month);	
//			break;
//		case 8:
//			printf("month %d has 31 days.\n", month);	
//			break;
//		case 9:
//			printf("month %d has 30 days.\n", month);	
//			break;
//		case 10:
//			printf("month %d has 31 days.\n", month);	
//			break;
//		case 11:
//			printf("month %d has 30 days.\n", month);	
//			break;
//		case 12:
//			printf("month %d has 31 days.\n", month);	
//			break;
//		default :
//			printf("Invalid month\n");
//			break;
//	}	
	return 0;
}
