// 014.cpp: 定义控制台应用程序的入口点。
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
		else  if(strcmp(name, "print") == 0)
		{
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
			Node *pNode = (Node *)malloc(  sizeof(Node));
			strcpy(pNode->name,  name);

			if (pHead == NULL)
			{
				pHead = pNode; 
			}
			else
			{
				pTail->next = pNode; 
			} 
			pNode->next = pHead; //新尾节点next指向头节点
			pTail = pNode; //指向新的尾部节点
		}

	}


    return 0;
}

