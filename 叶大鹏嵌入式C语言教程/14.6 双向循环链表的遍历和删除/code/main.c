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

typedef struct TempHumiListNode_t
{
	uint8_t id;
	uint8_t humi;
	float temp;
	struct TempHumiListNode_t *next;
	struct TempHumiListNode_t *prev;
} TempHumiListNode;

TempHumiListNode *InitSensorList(void)
{
	TempHumiListNode *header = (TempHumiListNode *)malloc(sizeof(TempHumiListNode));
	if (header == NULL)
	{
		return NULL;
	}
	header->id = 0;
	header->next = header;
	header->prev = header;
	return header;
}

TempHumiListNode *FindTempHumiSensor(void)
{
	TempHumiListNode *node = (TempHumiListNode *)malloc(sizeof(TempHumiListNode));
	if (node == NULL)
	{
		return NULL;
	}
	
	static uint8_t id = 100;
	node->id = id;
	id--;
	node->temp = 20.5f;
	node->humi = 40;
	return node;
}

void AddNode(TempHumiListNode *oldNode, TempHumiListNode *newNode)
{
	newNode->next = oldNode->next;
	newNode->prev = oldNode;
	oldNode->next->prev = newNode;
	oldNode->next = newNode;
}

void AddNodeToHead(TempHumiListNode *header, TempHumiListNode *node)
{
	AddNode(header, node);
}

void AddNodeToTail(TempHumiListNode *header, TempHumiListNode *node)
{
	AddNode(header->prev, node);
}

void PrintSensorData(TempHumiListNode *header)
{
	TempHumiListNode *current;
	current = header->next;
	
	printf("\n*****print list begin*****\n");
	if (current == header)
	{
		printf("List has no node!\n");
		return;
	}
	
	while (current != header)
	{
		printf("\nSensor id:%d, temp = %.1f, humi = %d.\n",
				current->id, current->temp, current->humi);
		current = current->next;
	}
	printf("\n*****print list end*****\n");
}

void DelNode(TempHumiListNode *node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

void DelSensorNode(TempHumiListNode *header, uint8_t id)
{
	TempHumiListNode *current;
	current = header->next;
	
	while (current != header)
	{
		if (current->id == id)
		{
			break;
		}
		current = current->next;
	}
	
	if (current == header)
	{
		printf("Can not find sensor %d.\n", id);
		return;
	}
	
	DelNode(current);
	free(current);
	current = NULL;
}

static TempHumiListNode *g_header;

int main(void)
{
	g_header = InitSensorList();
	if (g_header == NULL)
	{
		return -1;
	}
	
	TempHumiListNode *node;
	for (uint8_t i = 0; i < 3; i++)
	{
		node = FindTempHumiSensor();
		if (node == NULL)
		{
			continue;
		}
		AddNodeToHead(g_header, node);
	}
	PrintSensorData(g_header);
	
	node = FindTempHumiSensor();
	AddNodeToTail(g_header, node);
	PrintSensorData(g_header);	
	
	node = FindTempHumiSensor();
	AddNodeToHead(g_header, node);
	PrintSensorData(g_header);	
	
	DelSensorNode(g_header, 97);
	DelSensorNode(g_header, 96);
	PrintSensorData(g_header);	
	
	return 0;
}
