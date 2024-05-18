#include<stdio.h>

//将入口函数改为fun
#pragma  comment(linker ,"/entry:fun")

int   fun()
{
	printf("fun 成为了入口函数！");
	return 0;
}