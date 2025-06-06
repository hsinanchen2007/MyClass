// 023.cpp: 定义控制台应用程序的入口点。

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
		if (p->next == NULL) {   pTail = p; }

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

//删除尾巴节点
Node *  DeleteTail(Node  *pHead)
{
	//空链表
	if (pHead == NULL) return  NULL;

	//判断是否只剩一个节点
	if (pHead->next == NULL)
	{
		free(pHead);//释放最后一个节点
		return  NULL;
	}

	//找到倒数第二个节点
	Node  *pTemp = pHead;
	while (pTemp->next->next != NULL)
	{
		pTemp  = pTemp->next;
	}

	printf("找到倒数第二个节点：  %s\n", pTemp->name);

	//释放最后一个节点的内存
	free(pTemp->next);
	pTemp->next = NULL;//倒数第二个成为尾节点，所以next必须为NULL

	return pHead;
}


//双向链表  尾部删除节点
int main()
{
	Node  *pHead = CreateList(5);
	PrintList(pHead);

	pHead=DeleteTail(pHead);
	PrintList(pHead);

	pHead = DeleteTail(pHead);
	PrintList(pHead);

	pHead = DeleteTail(pHead);
	PrintList(pHead);

	pHead = DeleteTail(pHead);
	PrintList(pHead);

	pHead = DeleteTail(pHead);
	PrintList(pHead);

	return 0;
}



