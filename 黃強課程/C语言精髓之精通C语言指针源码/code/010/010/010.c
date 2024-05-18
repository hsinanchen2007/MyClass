#include<stdio.h>


typedef int(*PFUN)(int); //定义函数指针类型

PFUN  fun(int a, int b){	PFUN  f = NULL;	return f;}

void  main()
{
	int  a = 10;
	int  b = 20;

	//指针常量，指针值不可改变，也就是说，不能改变指向
	int * const   p = &a;
	//p = &b;//错误


	//指向的内存空间的内容不可改变
	const int  *p1 = a;
	//*p1 = 30;//错误


	const int *  const p2 = &a;
	 //p2 = &b;//错误
	 //*p2 = 30;//错误


	int(*pA)[10];	int arr[2][10] = { 0 };	pA = arr; 	//指向一个指针（是一个指向二维数组的指针，第二维是10）	int(**p3)[10] = &pA;

 	int *c[2] = { &a,  &b };	//指向一个指针数组的地址  （这个指针数组，有两个元素）	int *(*p4)[2] = &c;
	PFUN  f1;	PFUN  f2;	//指针数组，数组中的每个元素都是函数指针（指向的函数返回值是int，参数int）	int(*p5[2])(int) = { f1,f2 };


	//函数指针 ，指向的函数返回值是函数指针（指向的函数返回值是int，参数int） ，参数是两个int	int(*(*p6)(int, int))(int);	p6 = fun;

}