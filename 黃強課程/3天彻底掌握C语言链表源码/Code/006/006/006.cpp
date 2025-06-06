// 006.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>

//定义单向链表的节点

struct  Node
{
	//数据成员，也可以有多个，可以是原始类型，也可以是struct，enum，union
	char  name[32];

	//一定不能缺的成员
	Node  *  next;//指向下一个节点的指针，可以通过它，知道下个节点的地址
};


int main()
{

	//1.产生3个节点
	Node stu1;
	Node stu2;
	Node stu3;

	//2.给节点的数据域赋值
	strcpy(stu1.name, "学生A");
	strcpy(stu2.name, "学生B");
	strcpy(stu3.name, "学生C");

	//3.  上面三个节点是散乱分布的，需要把他们串成链表
	//stu1作为头结点，  stu3作为尾节点
	stu1.next = &stu2; 
	stu2.next = &stu3;
	stu3.next =  NULL; //stu3是最后一个节点，所以next为NULL

	//以上步骤，单向链表构造完成

	//打印链表，从链表头开始
	Node  * pHead = &stu1;//头指针，指向第一个节点

	while (pHead != NULL)
	{
		printf("%s        ", pHead->name);
		pHead = pHead->next; //获取下一个节点的内存位置
	}
	printf("\n");





    return 0;
}

