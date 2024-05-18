#include<stdio.h>

int  main()
{
	int   a = 100; //整型变量
	int  *p = &a;//指针变量,它自身也有内存地址
	int* *pp = &p;//指针的指针变量，它自身也有内存地址

	//举一反三
	int**   *ppp = &pp;//指针的指针的指针变量，它自身也有内存地址

	printf("%d \n", **pp);//获取内容
	printf("%d \n", ***ppp);//获取内容

	return   0;
}