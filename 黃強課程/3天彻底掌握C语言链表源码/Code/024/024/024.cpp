// 024.cpp: 定义控制台应用程序的入口点。

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

//删除头部节点
Node *  DeleteHead(Node  *pHead)
{
	if (pHead == NULL)  return NULL;

	//保留第二个节点的地址（因为它即将成为新的头结点）
	Node  *pTemp = pHead->next;

	//释放头结点内存
	free(pHead);

	//让pHead指向新的头节点
	pHead = pTemp;

	//此刻pTemp->prev还存在着一个已经释放的地址值（就是之前头结点的地址）
	//printf("%p\n", pTemp->prev);

	if (pTemp != NULL)
	{
		pTemp->prev = NULL;//头结点的prev必须为NULL
	} 

	return pHead;
}



int main()
{
	Node  *pHead = CreateList(5);
	PrintList(pHead);

	pHead = DeleteHead(pHead);
	PrintList(pHead);

	pHead = DeleteHead(pHead);
	PrintList(pHead);

	pHead = DeleteHead(pHead);
	PrintList(pHead);

	pHead = DeleteHead(pHead);
	PrintList(pHead);

	pHead = DeleteHead(pHead);
	PrintList(pHead);

	pHead = DeleteHead(pHead);
	PrintList(pHead);

	return 0;
}



