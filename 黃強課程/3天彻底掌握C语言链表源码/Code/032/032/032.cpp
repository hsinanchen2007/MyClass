// 032.cpp: 定义控制台应用程序的入口点。
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


//只遍历一次，找到单向链表倒数第K个节点
Node *   rFind(Node *pHead, int  k)
{
	Node  *first =pHead;
	Node  *second = pHead;

	//让fisrt先走k-1步
	while (k--)
	{ 
		first = first->next;

		if (first == NULL && k>0) //说明k的长度超出范围
		{
			return NULL;
		}
	}

	//然后两个人同时开始走，此时他们之间的距离始终保持不变为k-1
	//当first先到达尾部时，此刻second正好是倒数第K个节点的位置
	while (first)
	{
		first = first->next;
		second = second->next;
	}

	return second;
}

int main()
{
	Node  *pHead = CreateList(6);
	PrintList(pHead);
	 
	int  k =7;
	Node *pFind = rFind(pHead, k);
	if (pFind != NULL)
	{
		printf("找到倒数第%d个节点：%s\n", k, pFind->name);
	}
	else
	{
		printf("未找到倒数第%d个节点!\n", k);
	}


	return 0;
}

