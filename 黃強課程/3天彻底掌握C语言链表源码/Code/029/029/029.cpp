// 029.cpp: 定义控制台应用程序的入口点。
//

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


//尾插法创建N个节点的双向循环链表 
Node *  CreateList(int  N)
{
	Node  *pHead = NULL;

	for (size_t i = 0; i <  N; i++)
	{
		Node *pNode = (Node *)malloc(sizeof(Node)); 
        sprintf(pNode->name, "学生%d", i + 1);
		pNode->prev = NULL;
		pNode->next = NULL;

		if (pHead == NULL)
		{//插入第一个节点
			pHead = pNode;
			pNode->prev = pNode;
			pNode->next = pNode;
		}
		else
		{
			//高手的写法， 你也可以定义一个Node *pTail  =pHead->prev；辅助你理解

			pNode->prev = pHead->prev;// 新尾节点的prev指向 原尾节点
			pNode->next = pHead;// 新尾节点的下一个 指向 头结点

			pHead->prev->next = pNode;//  原尾节点 的 next 指向新尾节点
			pHead->prev = pNode;// 头结点 的prev 指向 新尾节点
		} 
	}

	return pHead;
}

//正反向打印双向循环链表
void  PrintList(Node  *pHead)
{ 
	if (pHead == NULL) return;

	//从头结点向后遍历
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

	//从尾结点向前遍历
	pTemp = pHead->prev; 
	do
	{
		if (pTemp != NULL)
		{
			printf("%s  ", pTemp->name);
			pTemp = pTemp->prev;
		}

	} while (pTemp != pHead->prev);
	printf("\n");

}
 
//删除双向循环链表的尾节点
Node  * DeleteTail(Node  *pHead)
{
	if (pHead == NULL) return NULL;

	//先判断是不是只有一个节点
	if (pHead->next == pHead)
	{
		free(pHead);//释放节点内存
		return  NULL;
	}

	Node  *pTail = pHead->prev; //头结点的前一个就是尾节点

	pTail->prev->next = pHead;//  新尾节点（倒数第二个节点）的next 指向 头结点
	pHead->prev = pTail->prev;//  头节点的 prev 指向 新的尾节点

	free(pTail);//释放尾节点内存

	return pHead;
}


int main()
{
	Node  *pHead = CreateList(5);
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

	pHead = DeleteTail(pHead);
	PrintList(pHead);

	pHead = DeleteTail(pHead);
	PrintList(pHead);

    return 0;
}

