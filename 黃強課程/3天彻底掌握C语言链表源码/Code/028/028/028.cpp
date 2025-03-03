// 028.cpp: 定义控制台应用程序的入口点。
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


//双向链表头插法
int main()
{

	Node  *pHead = NULL; //一直指向头节点 

	while (true)
	{
		printf("请输入学生姓名，quit退出，print打印:\n");
		char  name[32] = { 0 };
		scanf("%s", name);

		if (strcmp(name, "quit") == 0)
		{
			break;
		}
		else  if (strcmp(name, "print") == 0)
		{
			//从头结点向后遍历
			Node  *pTemp = pHead;
			do
			{
				printf("%s   ", pTemp->name);
				pTemp = pTemp->next;//获取下一个节点的地址
			} while (pTemp != pHead);
			printf("\n");

			//从尾结点向前遍历
			pTemp = pHead->prev; //头结点的前一个，就是尾节点
			do
			{
				printf("%s   ", pTemp->name);
				pTemp = pTemp->prev;//获取前一个节点的地址
			} while (pTemp != pHead->prev);
			printf("\n");

		}
		else
		{  //录入学生信息
			Node  *p = (Node *)malloc(sizeof(Node));
			strcpy(p->name, name);
			p->prev = NULL;
			p->next = NULL;


			if (pHead == NULL)
			{
				pHead = p;
				p->prev = p; //只有一个节点时，prev，next均指向自己
				p->next = p;
			}
			else
			{
				//获取尾节点指针
				Node *pTail = pHead->prev;

				//开始四个指针域的赋值（和尾插法代码一样）
				pHead->prev = p; //原头结点的 prev 指向 新节点
				pTail->next = p;  //尾节点的 next 指向新的头结点

				p->prev = pTail; // 新头结点的prev指向尾节点
				p->next = pHead;// 新头结点的next指向 原头结点

				pHead = p;//pHead指向新的头结点
			}  
		}

	}



	return 0;
}

