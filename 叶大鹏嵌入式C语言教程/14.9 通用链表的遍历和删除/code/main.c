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

/**
***********************************************************
* @brief 从链表中删除节点
* @param node：待删除节点
* @return 
***********************************************************
*/
void DelNode(List *node)
{
	node->next->prev = node->prev;
    node->prev->next = node->next;
}

/**
 ******************************************************************************
* @brief 获取结构体中成员的偏移量
* @param typeName: 结构体类型的名字
* @param memberName: 成员的名字
* @return 成员在结构体当中的偏移量
******************************************************************************
*/
#define OFFSET_OF(typeName, memberName)  ((uint32_t)&((typeName *)0)->memberName)

/**
 ******************************************************************************
* @brief 根据成员的地址获取结构体的首地址
* @param typeName: 结构体类型的名字
* @param memberName: 成员的名字
* @return 结构体的首地址
******************************************************************************
*/
#define CONTAINER_OF(pMember, typeName, memberName) \
		((typeName *)((uint8_t *)pMember - OFFSET_OF(typeName, memberName)))

/**
 ******************************************************************************
* @brief 遍历给定类型的通用链表
* @param pBusi:业务数据结构体指针变量，在循环语句中遍历业务数据块
* @param header:链表的头节点地址
* @param typeName:业务数据结构体类型的名字
* @param memberName:链表成员在业务数据结构体中的名字
* @return 
******************************************************************************
*/
#define  LIST_FOR_EACH_ENTRY(pBusi, header, typeName, memberName) \
               for (pBusi = CONTAINER_OF((header)->next, typeName, memberName); \
                      &pBusi->memberName != (header); \
                      pBusi = CONTAINER_OF(pBusi->memberName.next, typeName, memberName))


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

void PrintTempHumiSensor(void)
{
	TempHumiSensor *sensor;
	
//	for (sensor = CONTAINER_OF(g_tempHumiHeader->next, TempHumiSensor, list);
//		 &sensor->list != g_tempHumiHeader;
//		 sensor = CONTAINER_OF(sensor->list.next, TempHumiSensor, list))
	LIST_FOR_EACH_ENTRY(sensor, g_tempHumiHeader, TempHumiSensor, list)
	{
		printf("sensor %d, temp = %.1f, humi = %d.\n", sensor->id, sensor->temp, sensor->humi);
	}
}

void DelTempHumiSensor(uint8_t id)
{
	TempHumiSensor *sensor;
//	for (sensor = CONTAINER_OF(g_tempHumiHeader->next, TempHumiSensor, list);
//		 &sensor->list != g_tempHumiHeader;
//		 sensor = CONTAINER_OF(sensor->list.next, TempHumiSensor, list))
	LIST_FOR_EACH_ENTRY(sensor, g_tempHumiHeader, TempHumiSensor, list)
	{
		if (sensor->id == id)
		{
			DelNode(&sensor->list);
			free(sensor);
			sensor = NULL;
			return;
		}
	}
	printf("Can not find sensor %d.\n", id);
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
	PrintTempHumiSensor();
	
	DelTempHumiSensor(98);
	PrintTempHumiSensor();
	
	sensor = FindTempHumiSensor();
	AddTempHumiSensor(sensor);
	PrintTempHumiSensor();
	return 0;
}
