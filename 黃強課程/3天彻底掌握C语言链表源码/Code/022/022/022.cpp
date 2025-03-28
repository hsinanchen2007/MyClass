// 022.cpp: 定义控制台应用程序的入口点。
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


//双向链表  中部插入节点
int main()
{
	//构建一条双向链表
	Node  A;
	Node  B;

	strcpy(A.name ,"学生A");
	strcpy(B.name, "学生B");

	A.prev = NULL;
	A.next = &B;

	B.prev = &A;
	B.next = NULL;


	//现在在A，B之间插入C
	Node  C; 
	strcpy(C.name, "学生C");

	//A  C   B

	C.prev = &A;
	C.next = &B; 

	A.next = &C;
	B.prev = &C;


	//正向打印
	Node  * pTemp= &A;
	while (pTemp!=NULL)
	{
		printf("%s   ", pTemp->name);
		pTemp = pTemp->next;
	}
	printf("\n");

	//方向打印
	pTemp = &B;
	while (pTemp != NULL)
	{
		printf("%s   ", pTemp->name);
		pTemp = pTemp->prev;
	}
	printf("\n");
	 
	return 0;
}


