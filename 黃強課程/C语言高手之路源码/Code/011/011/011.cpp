#include<stdio.h>

 
struct A
{
	int  a; 
	char b;
	//...
};

struct  B
{
	int  a;
	//struct  B  next; //无限的去定义，错误
	struct  B * next; //利用指针，则不会报错，而可以实现同样的效果
};


//利用结构体可以传递多个参数
void   fun(void  *p)
{
	A  *pA = (A*)p;
	printf("%d  %c\n",pA->a,pA->b);
}


int  main()
{

	//1.利用指针更改常量的值
	 volatile const int  a = 100;
	//a = 200;//错误 ，常量不可以修改
	int  *pA = (int *)&a;
	*pA = 200;
	printf("%d\n", a);


	//2.利用void*传递 任何类型的参数,利用结构体传递多个参数
	A   x;
	x.a = 100;
	x.b = 'A';
	fun(&x);


	//3.利用指针实现链表结构
	B   b1;
	b1.a = 111;

	B   b2;
	b2.a = 222;
	b1.next =&b2;  //在这里形成链表

	B   b3;
	b3.a = 333;
	b2.next = &b3;  //在这里形成链表 
	b3.next = NULL;

	B *p = &b1;//链表头
	while (p)
	{
		printf("%d     ", p->a);
		p = p->next;
	}

}