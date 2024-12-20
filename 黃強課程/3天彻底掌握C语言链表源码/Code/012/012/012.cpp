// 011.cpp: 定义控制台应用程序的入口点。
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


//创建一条链表,拥有N个节点，尾插法
Node  *   CreateList(int  N)
{
	Node  *pHead = NULL;
	Node  *pTail = NULL;

	for (size_t i = 0; i < N; i++)
	{
		Node  * pNode = (Node *)malloc(sizeof(Node));
		sprintf(pNode->name, "学生%d", i + 1);
		pNode->next = NULL;

		if (pHead == NULL)//如果是第一个节点
		{
			pHead = pNode;
		}
		else
		{
			pTail->next = pNode;
		}
		pTail = pNode;
	}

	return  pHead;//返回链表头结点的指针
}


//打印一条链表
void  PrintList(Node  *pHead)
{
	while (pHead != NULL)
	{
		printf("%s    ", pHead->name);
		pHead = pHead->next;//pHead的改变不影响实参,因为是参数的拷贝
	}
	printf("\n");
}


//根据删除指定学生名字的节点
Node   *  DeleteNodeByName(Node  *pHead, const  char *name)
{
	//第一步，找到要删除的节点的前一个节点
	Node *pTemp = pHead;
	Node  *pLast = NULL;//保存前一个节点

	while (pTemp)
	{
		if (strcmp(pTemp->name, name) == 0)
		{
			break; //找到了跳出循环，此刻pTemp指向学生姓名为name的节点
		}
		pLast = pTemp;
		pTemp = pTemp->next;//指向下一个
	}

	if (pTemp != NULL)
	{
		printf("找到了要删除的节点：%s\n", pTemp->name);
		printf("找到了要删除的节点的前一个：%s\n", pLast->name); 

		if (pLast == NULL)//说明删除的是头结点
		{
			pHead = pTemp->next;
			free( pTemp);
		}
		else
		{
			//让删除节点的前一个的next  指向    删除节点的  下一个地址
			pLast->next = pTemp->next;

			//删除当前节点的内存
			free(pTemp);
		}

	}
	else
	{
		printf("未找到了要删除的节点！\n");
	} 

	return pHead;
}


int main()
{
	Node  *pHead = CreateList(5);
	PrintList(pHead);

	pHead = DeleteNodeByName(pHead, "学生4");
	PrintList(pHead);

	pHead = DeleteNodeByName(pHead, "学生5");
	PrintList(pHead);
	 
	pHead = DeleteNodeByName(pHead, "学生2");
	PrintList(pHead);

	pHead = DeleteNodeByName(pHead, "学生3");
	PrintList(pHead);

	pHead= DeleteNodeByName(pHead, "学生1");
	PrintList(pHead);

	pHead = DeleteNodeByName(pHead, "学生4");
	PrintList(pHead);

	return 0;
}

