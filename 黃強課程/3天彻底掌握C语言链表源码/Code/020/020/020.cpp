// 020.cpp: 定义控制台应用程序的入口点。
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
	Node  *pTail = NULL; //一直指向尾节点

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
			//正向遍历
			Node *pTemp = pHead;
			while (pTemp != NULL)
			{
				printf("%s   ", pTemp->name);
				pTemp = pTemp->next;
			}
			printf("\n");

			//反向遍历
			pTemp = pTail;
			while (pTemp != NULL)
			{
				printf("%s   ", pTemp->name);
				pTemp = pTemp->prev;
			}
			printf("\n"); 

		}
		else
		{  //录入学生信息
			Node  node;//不可以，因为这个是栈内存，一旦出了}括号，这个节点就销毁了，
			                      //里面的信息也就丢失了，链表失效
			Node  *p = (Node *)malloc(sizeof(Node));
			strcpy(p->name, name);
			p->prev = NULL;
			p->next = NULL;

			//是不是第一个节点
			if (pHead == NULL)
			{
				pHead = p; 
			}
			else
			{
				pTail->next = p;//让旧尾节点的next指向新节点
				p->prev = pTail; //新节点的prev指向旧的尾节点 
			}
			pTail = p;//将pTail指向新的尾节点
		}

	}



	return 0;
}

