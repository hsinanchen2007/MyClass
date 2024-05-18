#include<stdio.h>
#include<windows.h>


struct A
{
	char a;  //0-1
	double  b;  //  8-15
	int c;      //16-20  ,最终24
};
 
int  main()
{
	printf("sizeof(A) :%d\n",sizeof(A));

	// 0可以转换为任何类型的NULL指针

	A *p = (A*)0;
	//printf("%d\n", p->a ); //NULL指针指向成员变量非法

	// 获取每个成员的偏移量     
    printf("%d\n", &(p->a)); //合法
	printf("%d\n", &(p->b));
	printf("%d\n", &(p->c));


	//如果我知道某个成员变量的地址，我是不是就可以知道整个结构体的首地址
	A   x;  //  &x 可以获取结构体x的首地址
	x.a = 'A';
	x.b = 1.234;
	x.c = 333;
	//假设只知道成员变量x.b的首地址 &x.b，如何获取x的首地址 
	A  *pStart = (A *) (   (int ) &x.b  -   (int )&(p->b) );
	printf("%c, %f, %d\n", pStart->a, pStart->b, pStart->c);

	 
	//利用windows提供的宏来获取，原理一样
	A  *pStart2 = CONTAINING_RECORD(&x.b, A, b);
	printf("%c, %f, %d\n", pStart2->a, pStart2->b, pStart2->c);

	 

	return    0;
}