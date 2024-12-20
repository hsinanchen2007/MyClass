// 019.cpp: 定义控制台应用程序的入口点。
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


//构造一条最简单的双向链表
int main()
{
	//定义3个学生节点（局部变量，栈内存）
	Node  stu1;
	Node  stu2;
	Node  stu3;

	//填充学生姓名信息
	strcpy(stu1.name, "学生A");
	strcpy(stu2.name, "学生B");
	strcpy(stu3.name, "学生C");

	//串成双向链表
	stu1.prev = NULL;  stu1.next = &stu2;

	stu2.prev = &stu1;  stu2.next = &stu3;

	stu3.prev = &stu2; stu3.next = NULL;


	Node  *pTemp =NULL;

	//正向遍历
	pTemp = &stu1;
	while (pTemp!=NULL)
	{
		printf("%s   ", pTemp->name);
		pTemp = pTemp->next;//获取下一个节点的地址
	}
	printf("\n");

	//反向遍历
	pTemp = &stu3;
	while (pTemp != NULL)
	{
		printf("%s   ", pTemp->name);
		pTemp = pTemp->prev;//获取前一个节点的地址
	}
	printf("\n");


    return 0;
}

