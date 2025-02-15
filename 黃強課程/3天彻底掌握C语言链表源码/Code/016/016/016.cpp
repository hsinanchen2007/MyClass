// 016.cpp: 定义控制台应用程序的入口点。
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

//删除单向循环链表的尾部节点
Node  * DeleteTail(Node * pHead)
{
	//需要知道链表的倒数第二个节点
	Node  *pTemp = pHead;

	//判断是否只剩下一个节点
	if (pTemp->next == pHead)
	{
		free(pTemp);
		return  NULL; //此刻变成空链表
	}
	 
	while (pTemp->next->next != pHead)
	{
		pTemp = pTemp->next;
	}
	printf("获取倒数第二个节点的指针：  %s   \n", pTemp->name);

	//释放最后一个节点的内存
	free(pTemp->next);

	//让新尾节点的next指向头部节点地址
	pTemp->next = pHead;

	return  pHead;
}

int main()
{
	Node * pHead = NULL;
	pHead = CreateList(5);
	PrintList(pHead);
	pHead = DeleteTail(pHead);
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

