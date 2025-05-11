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

typedef struct
{
	uint8_t paramType;
	uint8_t *value;
	uint32_t size;
} CfgParam;   

int main()
{
	CfgParam  *cfgParam;   
	cfgParam = (CfgParam *)malloc(sizeof(CfgParam));

	cfgParam->value = (uint8_t *)malloc(5);
	cfgParam->value[0] = 0x01;
	cfgParam->value[1] = 0x02;
	cfgParam->value[2] = 0x03;
	cfgParam->value[3] = 0x04;
	cfgParam->value[4] = 0x05;

	free(cfgParam->value);
	cfgParam->value = NULL;

	free(cfgParam);
	cfgParam = NULL;

	return 0;
}

#if 0
int main()
{

    CfgParam cfgParam;
	printf("sizeof(cfgParam) = %d\n", sizeof(cfgParam));
	printf("&paramType = 0x%p, &value = 0x%p, &size = 0x%p.\n", &cfgParam.paramType, &cfgParam.value, &cfgParam.size);
    cfgParam.value = (uint8_t *)malloc(5);
    cfgParam.value[0] = 0x01;
    cfgParam.value[1] = 0x02;
    cfgParam.value[2] = 0x03;
    cfgParam.value[3] = 0x04;
    cfgParam.value[4] = 0x05;	 

	return 0;
}
#endif