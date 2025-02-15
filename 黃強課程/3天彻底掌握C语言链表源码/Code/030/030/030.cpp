// 030.cpp: 定义控制台应用程序的入口点。
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

	for (size_t i = 0; i < N; i++)
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
	pTemp = pHead->prev; //头结点的prev 就指向尾节点
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

//删除双向循环链表的头节点
Node  * DeleteHead(Node  *pHead)
{
	if (pHead == NULL)  return NULL;

	if (pHead->prev == pHead)//判断是否只有一个节点
	{
		free(pHead);//释放内存
		return NULL;
	}

	Node *pLast = pHead->prev;//头结点的前一个节点地址
	Node *pNext = pHead->next;//头结点的下一个节点地址

     //放心大胆的释放头节点内存
	free(pHead);

	//此刻，链表是断裂的，把前一个节点和后一个节点链接起来
	pLast->next= pNext; //头结点前一个节点的 next 指向  头结点下一个节点的地址
	pNext->prev= pLast;//头结点后一个节点的 prev 指向  头结点前一个节点的地址

	//因为删除头节点后，第二个节点变成了新的头节点
	pHead = pNext;// 更新pHead的指向

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

