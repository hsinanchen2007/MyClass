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


//创建一条有环的链表
Node  *  CreateCycleList()
{
	Node *pA = (Node *)malloc(sizeof(Node));
	strcpy(pA->name, "学生A");
	Node *pB = (Node *)malloc(sizeof(Node));
	strcpy(pB->name, "学生B");
	Node *pC = (Node *)malloc(sizeof(Node));
	strcpy(pC->name, "学生C");
	Node *pD = (Node *)malloc(sizeof(Node));
	strcpy(pD->name, "学生D");
	Node *pE = (Node *)malloc(sizeof(Node));
	strcpy(pE->name, "学生E");

	pA->next = pB;
	pB->next = pC;
	pC->next = pD;
	pD->next = pE;

	//pE->next = NULL; 
	pE->next = pB;//产生环

	return pA;
}


//打印一条有环的链表
void  PrintCyCleList(Node  *pHead)
{
	int i = 0;
	while (pHead != NULL  && ( i ++<17) ) //这里的17是避免不停地打印
	{
		printf("%s    ", pHead->name);
		pHead = pHead->next;//pHead的改变不影响实参,因为是参数的拷贝
	}
	printf("\n");
}
 

//检测链表是否有环路
bool     IsCycle(Node  *pHead)
{
	Node  *pFast = pHead;
	Node *pSlow = pHead;

	while (pFast!=NULL  && pFast->next!=NULL)
	{
		pFast = pFast->next->next;//一次走两步
		pSlow = pSlow->next;//一次走一步

		if (pFast == pSlow)//快，慢指针相遇，说明有环路
		{
			return  true;
		}
	}
	 
	return  false;
}


int main()
{
	Node  *pHead = CreateCycleList();
	PrintCyCleList(pHead);

	bool  bRet=IsCycle(pHead);
	printf("是否有环路： %d\n", bRet);

	return 0;
}

