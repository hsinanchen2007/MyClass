// 007.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

struct  Node
{
	char  name[32];//节点的数据成员
	// int  age;

	Node  * next;//必须要有的成员，指向下一个节点的内存地址
};


int main()
{
	//定义两个节点指针，一个指向头结点（方便遍历），一个指向尾节点（方便插入新节点）
	Node  *pHead = NULL;
	Node  *pTail = NULL;//空链表的时候

	//让用户可以随时输入学生
	while (true)
	{
		printf("请输入学生姓名，quit(退出)   print(打印):\n");
		char  name[32] = {0};
		scanf("%s", name);

		if ( strcmp(name, "quit")==0)
		{
			break;
		}
		else  if (strcmp(name, "print") == 0)
		{
			//遍历链表
			Node  *pNode = pHead; //不要改变pHead的值，让它一直指向头部
			while ( pNode!=NULL)
			{
				printf("%s    ", pNode->name);
				pNode = pNode->next;//指向下一个节点
			}
			printf("\n");
		}
		else
		{
			//Node  stu;//这样定义一个节点可不可以？ 但是这样定义的话，stu局部变量，
			                 //离开这个}内存就释放了
			     
			//分配节点堆内存，除非free，否则内存一直有效
			Node  *pNode = (Node*)malloc(sizeof(Node));
			strcpy(pNode->name, name);
			pNode->next = NULL;//因为这个节点即将作为尾部节点
			 
			//把节点放到链表中
			//判断是不是第一个节点
			if (pHead == NULL)
			{
				pHead = pNode;
				pTail = pNode;//第一个节点即是头，又是尾部
			}
			else
			{
				pTail->next = pNode;//让一个尾巴 的next =新节点
				pTail = pNode;//让pTail始终指向最新的尾巴
			}    
		}


	}



    return 0;
}

