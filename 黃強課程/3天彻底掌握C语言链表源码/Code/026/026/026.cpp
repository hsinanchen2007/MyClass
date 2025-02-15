// 026.cpp: 定义控制台应用程序的入口点。
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


int main()
{
	//一条最简单的双向循环链表

	Node  stu1;
	Node  stu2;
	Node  stu3;

	strcpy(stu1.name, "学生A");
	strcpy(stu2.name, "学生B");
	strcpy(stu3.name, "学生C");


	//串成双向循环链表 
	stu1.prev = &stu3;  stu1.next = &stu2; //头结点的前一个为  尾节点

	stu2.prev = &stu1;  stu2.next = &stu3;

	stu3.prev = &stu2;  stu3.next = &stu1;//尾结点的前一个为  头节点

	//从头结点向后打印
	Node *pHead = &stu1;

	//不论你从哪个节点开始打印，都能访问到所有节点，因为它是环形
	//Node * pHead = &stu3;


	Node *pTemp = pHead;
	do
	{
		printf("%s   ", pTemp->name);
		pTemp = pTemp->next;//获取下一个节点的地址
	} 
	while (pTemp != pHead);
	printf("\n");


	//从尾结点向前打印
	Node *pTail = &stu3; 
	pTemp = pTail;
	do
	{
		printf("%s   ", pTemp->name);
		pTemp = pTemp->prev; //获取前一个节点的地址
	} while (pTemp != pTail);
	printf("\n");






    return 0;
}

