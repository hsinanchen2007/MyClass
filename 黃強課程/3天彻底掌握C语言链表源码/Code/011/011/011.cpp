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

//删除链表的头节点( 错误演示版本)
Node  * _DeleteHead(Node *pHead)
{ 
	printf("释放内存前，打印pHead->next的值：%p\n", pHead->next);
	free(pHead); //释放头结点的内存
	printf("释放内存后，打印pHead->next的值：%p\n", pHead->next);

	//此刻，pHead指向的内存已经释放， 内存中的next已经是无效值了
	pHead = pHead->next;//让头结点指针指向第二个节点

	return pHead;
}



//删除链表的头节点( 正确版本)
Node  *  DeleteHead(Node *pHead)
{

	if (pHead == NULL)  return  NULL;

	Node  *pTemp = pHead->next; //pTemp指向第二个节点

	free(pHead); //释放头结点的内存

	printf("释放内存后，pTemp的值： %p ,   pHead->next的值： %p\n",pTemp, pHead->next);

	//此刻，pHead指向的内存已经释放， 内存中的next已经是无效值了
	pHead = pTemp;//让头结点指针指向第二个节点

	return pHead;
}


int main()
{
	Node  *pHead = CreateList(5);
	PrintList(pHead);

	pHead= DeleteHead(pHead);
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

