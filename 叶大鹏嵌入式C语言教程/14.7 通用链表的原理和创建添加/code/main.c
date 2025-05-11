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

/**
***********************************************************
* 通用链表结构体
***********************************************************
*/
typedef struct List
{
	struct List *prev;
	struct List *next;
} List;

/**
***********************************************************
* @brief 初始化通用链表
* @param header：通用链表的头节点
* @return 
***********************************************************
*/
void InitList(List *header)
{
	header->prev = header;
	header->next = header;
}

/**
***********************************************************
* @brief 将节点添加到已有节点的后面
* @param oldNode：已有节点
* @param newNode：待添加节点
* @return 
***********************************************************
*/
void AddNode(List *oldNode, List *newNode)
{
    newNode->next = oldNode->next;
    newNode->prev = oldNode;
    oldNode->next->prev = newNode;
    oldNode->next = newNode;
}

/**
***********************************************************
* @brief 将节点添加到链表的尾部
* @param header：头节点
* @param node：待添加节点
* @return 
***********************************************************
*/
void AddNodeToTail(List *header, List *node)
{
    AddNode(header->prev, node);
}

/**
***********************************************************
* @brief 将节点添加到头节点的后面
* @param header：头节点
* @param node：待添加节点
* @return 
***********************************************************
*/
void AddNodeToHead(List *header, List *node)
{
	AddNode(header, node);
}

static List *g_tempHumiHeader;

typedef struct TempHumiSensor
{
	uint8_t id;
	uint8_t humi;
	float temp;
	List list;
} TempHumiSensor;

bool InitTempHumiSensor(void)
{
	g_tempHumiHeader = (List *)malloc(sizeof(struct List));
	if (g_tempHumiHeader == NULL)
	{
		return false;
	}
	InitList(g_tempHumiHeader);
	return true;
}

TempHumiSensor *FindTempHumiSensor(void)
{
	TempHumiSensor *sensor = (TempHumiSensor *)malloc(sizeof(TempHumiSensor));
	if (sensor == NULL)
	{
		return NULL;
	}
	static uint8_t id = 100;
	sensor->id = id;
	id--;
	sensor->humi = 40;
	sensor->temp = 20.5f;
	return sensor;
}

void AddTempHumiSensor(TempHumiSensor *sensor)
{
	AddNodeToTail(g_tempHumiHeader, &sensor->list);
}

int main(void)
{
	if (!InitTempHumiSensor())
	{
		return -1;
	}
	TempHumiSensor *sensor;
	for (uint8_t i = 0; i < 3; i++)
	{
		sensor = FindTempHumiSensor();
		if (sensor == NULL)
		{
			continue;
		}
		AddTempHumiSensor(sensor);
	}
	return 0;
}
