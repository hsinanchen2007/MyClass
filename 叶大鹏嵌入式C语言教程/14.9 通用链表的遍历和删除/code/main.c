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
* ͨ������ṹ��
***********************************************************
*/
typedef struct List
{
	struct List *prev;
	struct List *next;
} List;

/**
***********************************************************
* @brief ��ʼ��ͨ������
* @param header��ͨ�������ͷ�ڵ�
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
* @brief ���ڵ���ӵ����нڵ�ĺ���
* @param oldNode�����нڵ�
* @param newNode������ӽڵ�
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
* @brief ���ڵ���ӵ������β��
* @param header��ͷ�ڵ�
* @param node������ӽڵ�
* @return 
***********************************************************
*/
void AddNodeToTail(List *header, List *node)
{
    AddNode(header->prev, node);
}

/**
***********************************************************
* @brief ���ڵ���ӵ�ͷ�ڵ�ĺ���
* @param header��ͷ�ڵ�
* @param node������ӽڵ�
* @return 
***********************************************************
*/
void AddNodeToHead(List *header, List *node)
{
	AddNode(header, node);
}

/**
***********************************************************
* @brief ��������ɾ���ڵ�
* @param node����ɾ���ڵ�
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
* @brief ��ȡ�ṹ���г�Ա��ƫ����
* @param typeName: �ṹ�����͵�����
* @param memberName: ��Ա������
* @return ��Ա�ڽṹ�嵱�е�ƫ����
******************************************************************************
*/
#define OFFSET_OF(typeName, memberName)  ((uint32_t)&((typeName *)0)->memberName)

/**
 ******************************************************************************
* @brief ���ݳ�Ա�ĵ�ַ��ȡ�ṹ����׵�ַ
* @param typeName: �ṹ�����͵�����
* @param memberName: ��Ա������
* @return �ṹ����׵�ַ
******************************************************************************
*/
#define CONTAINER_OF(pMember, typeName, memberName) \
		((typeName *)((uint8_t *)pMember - OFFSET_OF(typeName, memberName)))

/**
 ******************************************************************************
* @brief �����������͵�ͨ������
* @param pBusi:ҵ�����ݽṹ��ָ���������ѭ������б���ҵ�����ݿ�
* @param header:�����ͷ�ڵ��ַ
* @param typeName:ҵ�����ݽṹ�����͵�����
* @param memberName:�����Ա��ҵ�����ݽṹ���е�����
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
