#include<stdio.h>


void fun(void *p) //可以有很强的扩展性
{
	//还原真实类型即可
}

int  main()
{

	//演示指针的本质
	int  a = 100;
	int *p = &a;//定义指针
	int  c = (int)p;//就是一个无符号的整型
	int *p2 = (int *)c;
	printf("%d\n", *p2);


	//真实项目开发中的使用技巧
	char buf[256];
	int  *p3 = (int *)buf;
	*p3 = 222;//是合法的，因为指向合法内存，大于4个字节
	printf("%d\n", *p3);

	float *p4 = (float *)buf;
	*p4 = 12.345f;
	printf("%f\n", *p4);//是合法的，因为指向合法内存，大于4个字节


	struct A
	{
		int a;
		double b; 
	};
	A *p5 = (A *)buf;
	p5->a= 34;
	p5->b = 34.567;
	printf("%d ,  %f\n", p5->a, p5->b);//是合法的，因为指向合法内存，大于A的字节数


	//演示void *类型
	int x = 100;
	char y = 'A';
	float z = 1.23456f;
	void *p6 = &x;//void *可以指向任何类型的地址
	void *p7 = &y;
	void *p8 = &z;

	//带来参数的可扩展性
	fun(&x);
	fun(&y);
	fun(&z);
	fun(p5);


	return  0;
}