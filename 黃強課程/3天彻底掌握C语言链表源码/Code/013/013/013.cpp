// 013.cpp: 定义控制台应用程序的入口点。
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
	Node stu1;
	Node stu2;
	Node stu3;

	strcpy(stu1.name, "学生A");
	strcpy(stu2.name, "学生B");
	strcpy(stu3.name, "学生C");


	//链表的构成

	stu1.next = &stu2;
	stu2.next = &stu3;
	//stu3.next = NULL;//单向链表，尾节点没有下一个节点
	stu3.next = &stu1;//单向循环链表，尾节点的下一个为 头结点


	//单向循环链表的遍历，不能靠判断next为NULL了，因为没有任何一个节点的next为NULL
	//Node *pHead = &stu1;
	//while (pHead != NULL)
	//{
	//	printf("%s    ", pHead->name);
	//	pHead=pHead->next;
	//}
	//printf("\n");

	//Node *pHead = &stu1;
    Node *pHead = NULL;
	Node *pTemp = pHead;
	do
	{
		if (pTemp != NULL)
		{ 
			printf("%s    ", pTemp->name);
			pTemp = pTemp->next;
		}
	} 
	while (pTemp != pHead);
	printf("\n");

    return 0;
}

