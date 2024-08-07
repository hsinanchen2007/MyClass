// 025.cpp: 定义控制台应用程序的入口点。

#include "stdafx.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//双向链表的节点定义
struct  Node
{
	char name[32];
	Node *prev;//指向前一个节点
	Node  *next;//指向后一个节点
};


//尾插法创建N个节点的双向链表
Node  *  CreateList(int  N)
{
	Node * pHead = NULL;
	Node * pTail = NULL;

	for (size_t i = 0; i < N; i++)
	{
		Node *pNode = (Node *)malloc(sizeof(Node));
		sprintf(pNode->name, "学生%d", i + 1);
		pNode->prev = NULL;
		pNode->next = NULL;

		if (pHead == NULL)
		{
			pHead = pTail = pNode;
		}
		else
		{
			pNode->prev = pTail;
			pTail->next = pNode;
			pTail = pNode;
		}
	}
	return  pHead;
}



void  PrintList(Node  *pHead)
{
	Node *pTail = NULL;

	//正向遍历
	Node  *p = pHead;
	while (p != NULL)
	{
		if (p->next == NULL) { pTail = p; }

		printf("%s  ", p->name);
		p = p->next;
	}
	printf("\n");

	//反向遍历
	p = pTail;
	while (p != NULL)
	{
		printf("%s  ", p->name);
		p = p->prev;
	}
	printf("\n");
}

//根据学生姓名删除链表节点（演示删除中部节点）
Node  * DeleteNodeByName(Node *pHead,  const char * name)
{
	Node  *pTemp = pHead;
	while (pTemp!=NULL)
	{
		//创建时保证每个学生的姓名唯一
		if (strcmp(pTemp->name, name) == 0) break;
		pTemp = pTemp->next;
	}

	if (pTemp != NULL)
	{
		printf("找到节点:   %s！\n",pTemp->name);

		//保存前一个，后一个的地址
		Node  *pLast = pTemp->prev;
		Node  *pNext = pTemp->next;

		free(pTemp);//释放该节点内存，该节点的prev，next为乱码了

		if (pLast != NULL)
		{
			//让删除节点的  前一个的next指向 删除节点的下一个节点
			pLast->next = pNext;
		}
		else
		{  //pLast==NULL,  说明此时删除的是头结点
			pHead = pNext; //更新头结点指针指向第二个节点
		}
	
		if (pNext != NULL)
		{
			//让删除节点的  下一个的prev指向 删除节点的上一个节点
			pNext->prev = pLast;
		}


	}
	else
	{
		printf("未找到该学生！\n");
	}


	return  pHead;
}


int main()
{
	Node  *pHead = CreateList(5);
	PrintList(pHead);
 
	pHead = DeleteNodeByName(pHead, "学生3");
	PrintList(pHead);

	pHead = DeleteNodeByName(pHead, "学生2");
	PrintList(pHead);

	pHead = DeleteNodeByName(pHead, "学生4");
	PrintList(pHead); 

	pHead = DeleteNodeByName(pHead, "学生5");
	PrintList(pHead);

	pHead = DeleteNodeByName(pHead, "学生1");
	PrintList(pHead);


	return 0;
}



