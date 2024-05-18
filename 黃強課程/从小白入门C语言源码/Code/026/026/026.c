#include<stdio.h> //系统头文件，包含了printf,scanf等系统函数的声明
 

//定义链表的结构体（火车车厢）
struct  Node
{
	int   data;//数据域（车厢里的货物）
	struct  Node  *  next;// 指针域 (车厢与车厢的挂钩)
};

 
void  main()//系统主函数，整个程序的入口函数，这个是它的简写
{ 
	//先定义三节火车车厢并初始化
	struct  Node  n1 = { 60 ,  NULL  };
	struct  Node  n2 = { 70 ,  NULL };
	struct  Node  n3 = { 80 ,  NULL };

	//把每节车厢链接起来
	n1.next = &n2; //把第一节与第二节链接
	n2.next = &n3; //把第二节与第三节链接

	//把头指针指向第一节车厢
	struct  Node *pHead = &n1;

	//打印出这辆火车 
	while (pHead!=NULL)
	{
		printf("货物:%d  ",  pHead->data);
		pHead = pHead->next;
	}


}

