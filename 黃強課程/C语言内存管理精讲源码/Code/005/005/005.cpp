#include<stdio.h>


//储存在全局静态区

int   a;  //全局变量，未初始化
short   b = 10;//全局变量，已赋值
char  *c = NULL;//全局变量，已赋值
static  int   f = 200;//静态变量


int  main()
{
	static  int  d = 100;
	static  int  e = 200;

	printf("%p\n", &a);
	printf("%p\n", &b);
	printf("%p\n", &c);
	printf("%p\n", &d);
	printf("%p\n", &e);
	printf("%p\n", &f);
}