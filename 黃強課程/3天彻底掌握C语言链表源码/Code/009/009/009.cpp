// 009.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>


struct  Node
{
	char name[32];
	Node  * next;
};


void  PrintList(Node *pHead) //指针的拷贝，不会影响实参
{
	while ( pHead)
	{
		printf("%s   ", pHead->name);
		pHead = pHead->next; //指向下个节点
	}
	printf("\n");
}


int main()
{
	//定义一条链表，两个节点A，B
	Node A;
	strcpy_s(A.name, 32, "学生A");

	Node B;
	strcpy_s(B.name, 32, "学生B");

	//形成一条链表
	A.next = &B;
	B.next = NULL;

	//打印链表
	PrintList(&A);


	//在A，B之间插入新节点
	Node  C;
	strcpy_s(C.name, 32, "学生C");

	//插入(知道前后节点地址的前提下，可以这么写)
	//C.next = &B; //  C->B
	//A.next = &C;  //  A->C

	 //插入(只知道插入位置的前一个节点,只知道A的地址)
	//C.next = (&A)->next;
	C.next = A.next; //A的下一个地址，就是B的地址
	A.next = &C;

	//打印
	PrintList(&A);


    return 0;
}

