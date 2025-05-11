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

typedef struct List
{
	struct List *prev;
	struct List *next;
} List;

typedef struct
{
	uint8_t id;
	uint8_t humi;
	float temp;
	List list;
} TempHumiSensor;

/**
* @brief 获取结构体中成员的偏移量
* @param typeName: 结构体类型的名字
* @param memberName: 成员的名字
* @return 成员在结构体当中的偏移量
*/
#define OFFSET_OF(typeName, memberName)  ((uint32_t)&((typeName *)0)->memberName)

/**
* @brief 获取结构体的首地址
* @param typeName: 结构体类型的名字
* @param memberName: 成员的名字
* @return 结构体的首地址
*/
#define CONTAINER_OF(pMember, typeName, memberName) \
		((typeName *)((uint8_t *)pMember - OFFSET_OF(typeName, memberName)))

int main(void)
{
	TempHumiSensor sensor = {1, 40, 20.5f};
	List *l = &sensor.list;
	//TempHumiSensor *p = (TempHumiSensor *)((uint8_t *)(l) - (uint32_t)&((TempHumiSensor *)0)->list);
	TempHumiSensor *p = CONTAINER_OF(l, TempHumiSensor, list);
	printf("id = %d, humi = %d, temp = %.1f.\n", p->id, p->humi, p->temp);
	
	return 0;
}
