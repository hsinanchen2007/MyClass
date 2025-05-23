// 027.cpp: 定义控制台应用程序的入口点。
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


//双向链表尾插法
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
				//插入第一个节点
				pHead = p;
				p->prev = p;
				p->next = p;
			}
			else
			{
				//有四个指针域需要赋值
				Node  *pTail= pHead->prev; //获取原尾节点

				pTail->next = p; //原尾节点next指向p
				pHead->prev = p;//头节点prev指向 新尾节点p

				p->prev = pTail;// 新节点的prev为  原尾节点
				p->next = pHead;//新节点的next为  头结点 
			}
		}

	}



	return 0;
}

