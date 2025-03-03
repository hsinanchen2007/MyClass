// 017.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct  Node
{
	char name[32];
	Node  *next;
};

//尾插法创建一条有N个节点的单向循环链表
Node  *  CreateList(int  N)
{
	Node * pHead = NULL;
	Node * pTail = NULL;

	for (size_t i = 0; i < N; i++)
	{
		Node *pNode = (Node *)malloc(sizeof(Node));
		sprintf(pNode->name, "学生%d", i + 1);

		if (pHead == NULL)
		{
			pHead = pTail = pNode;
		}
		else
		{
			pTail->next = pNode;
			pTail = pNode;
		}
	}

	pTail->next = pHead;
	return  pHead;
}


//遍历单向循环链表
void  PrintList(Node  *pHead)
{
	//从头结点遍历
	Node  *pTemp = pHead;
	do
	{
		if (pTemp != NULL)
		{
			printf("%s  ", pTemp->name);
			pTemp = pTemp->next;
		}

	} while (pTemp != pHead);
	printf("\n");
}

//删除单向循环链表的头部节点
Node  * DeleteHead(Node * pHead)
{ 
	//判断只有一个节点的情况
	if (pHead->next == pHead)
	{
		free(pHead);
		return NULL;
	}
	 
	//先获取尾部节点
	Node  *pTemp = pHead ;
	while (pTemp->next != pHead)
	{
		pTemp = pTemp->next;
	}
	printf("获取尾节点指针：  %s\n", pTemp->name);
	 

	//先获取第二个节点(即新的头结点)的指针
	Node  *pSecond = pHead->next;

	 //释放第一个节点的内存
	  free(pHead);

	 //第二个节点变成新头结点
	  pHead = pSecond;

	  //让尾节点的next指向新的头节点
	  pTemp->next = pHead;

	return  pHead;
}



int main()
{
	Node * pHead = NULL;
	pHead = CreateList(5);
	PrintList(pHead);
	
	pHead=DeleteHead(pHead);
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

