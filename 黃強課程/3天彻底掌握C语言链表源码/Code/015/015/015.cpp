// 015.cpp: 定义控制台应用程序的入口点。
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


int main()
{
	Node  *pHead = NULL;
	Node  *pTail = NULL;

	while (true)
	{
		printf("请输入学生姓名，quit退出，print打印:\n");
		char name[32] = { 0 };
		scanf("%s", name);

		if (strcmp(name, "quit") == 0)
		{
			break;
		}
		else  if (strcmp(name, "print") == 0)
		{
			//遍历单向 循环链表
			Node *pTemp = pHead;
			do
			{
				if (pTemp != NULL)
				{
					printf("%s   ", pTemp->name);
					pTemp = pTemp->next;
				}
			} while (pTemp != pHead); //判断是否再次到达头结点

			printf("\n");
		}
		else
		{
			//单向循环链表头插法

			Node *pNode = (Node *)malloc(sizeof(Node));
			strcpy(pNode->name, name);

			if (pHead == NULL) //空链表
			{
				pHead =pTail= pNode;
			}
			else
			{
				pNode->next = pHead;//新节点的next指向上一次的头结点（pHead）
				pHead = pNode;//新节点变成头节点
			}

			pTail->next = pHead;//因为新产生了头结点，所以尾节点的next需要指向新的头结点
		}

	}


	return 0;
}

