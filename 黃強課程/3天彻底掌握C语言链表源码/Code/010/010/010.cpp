// 010.cpp: 定义控制台应用程序的入口点。
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
		sprintf(pNode->name, "学生%d", i+1);
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
	while (pHead!=NULL)
	{
		printf("%s    ", pHead->name);
		pHead = pHead->next;//pHead的改变不影响实参,因为是参数的拷贝
	}
	printf("\n");
}


//删除链表的尾部节点
Node *   DeleteTail(Node *pHead)
{
	//需要判断这个链表是否只有一个节点，不存在倒数第二个节点
	if (pHead->next == NULL)
	{
		printf("当前链表只有一个节点\n");
		free(pHead);//删完后，这条链表一个节点也没有了 
		return  NULL;  
	}


	Node *pTemp = pHead;
	//需要获取尾部节点的前一个节点指针（因为我们要把前一个节点的next设置为NULL）
	while (pTemp->next->next!=NULL) //获取倒数第二个节点的指针
	{

		pTemp = pTemp->next;//pTemp的改变不影响实参
	}

	printf("当前节点是：%s  \n", pTemp->name);

	//删除最后一个节点的内存
	free(pTemp->next);
	//将倒数第二个的next置为NULL,让倒数第二个变成尾节点
	pTemp->next = NULL;


	return pHead;
}


int main()
{
	Node  *pHead= CreateList(5);
	PrintList(pHead);

	pHead = DeleteTail(pHead);
	PrintList(pHead);

	pHead = DeleteTail(pHead);
	PrintList(pHead);

	pHead = DeleteTail(pHead);
	PrintList(pHead);

	pHead = DeleteTail(pHead);
	PrintList(pHead);

	//接受新的pHead
	pHead =DeleteTail(pHead);
	PrintList(pHead);

    return 0;
}

