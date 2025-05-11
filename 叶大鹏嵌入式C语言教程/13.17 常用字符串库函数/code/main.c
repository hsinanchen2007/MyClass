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

char *strcpyTest(char *dest, const char *src)
{
	uint32_t idx = 0;
	while (src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return dest;
}

int main(void)
{
	char *src = "malloc for m failed.";
	char *dest = (char *)malloc(strlen(src) + 1);
	strcpyTest(dest, src);
	printf("%s\n", dest);
	int8_t res = strcmp(src, "Malloc for m failed.");
	if (res == 0)
	{
		printf("res == 0\n");
	}
	else
	{
		printf("res !=0\n");
	}
	printf("%s\n", strchr(src, 'l'));
	printf("%s\n", strrchr(src, 'l'));
	return 0;
}