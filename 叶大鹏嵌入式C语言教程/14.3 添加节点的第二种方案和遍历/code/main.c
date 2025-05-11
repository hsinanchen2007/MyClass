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
} TempHumiListNode;

TempHumiListNode *InitSensorList(void)
{
	TempHumiListNode *header = (TempHumiListNode *)malloc(sizeof(TempHumiListNode));
	if (header == NULL)
	{
		return NULL;
	}
	header->id = 0;
	header->next = NULL;
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

void AddSensorNode(TempHumiListNode *header, TempHumiListNode *node)
{
	TempHumiListNode *current = header;
	
	while (current->next != NULL)
	{
		current = current->next;
	}
	
	current->next = node;
	node->next = NULL;
	
//	TempHumiListNode *prev = header;
//	TempHumiListNode *current = header->next;
//	
//	while (current != NULL)
//	{
//		prev = current;
//		current = current->next;
//	}
//	
//	prev->next = node;
//	node->next = NULL;
}

void PrintSensorData(TempHumiListNode *header)
{
	TempHumiListNode *current = header->next;
	
	if (current == NULL)
	{
		printf("List has no node!\n");
		return;
	}
	
	while (current != NULL)
	{
		printf("\nSensor id:%d, temp = %.1f, humi = %d.\n",
				current->id, current->temp, current->humi);
		current = current->next;
	}
}


static TempHumiListNode *g_header;

int main(void)
{
	g_header = InitSensorList();
	if (g_header == NULL)
	{
		return -1;
	}
	PrintSensorData(g_header);
	TempHumiListNode *node;
	
	for (uint8_t i = 0; i < 3; i++)
	{
		node = FindTempHumiSensor();
		if (node == NULL)
		{
			continue;
		}
		AddSensorNode(g_header, node);
	}
	PrintSensorData(g_header);
	
	return 0;
}
