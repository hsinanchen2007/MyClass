#include<stdio.h> //系统头文件，包含了printf,scanf等函数的声明
#include"014.h"//自定义函数的头文件，包含sum的声明


void  main()//系统主函数，整个程序的入口函数，这个是它的简写
{
	//调用sum函数
	int  c = sum(100 , 200);
	printf("%d", c);
}

//sum 函数的实现
int  sum(int  a, int b)
{
	return  a + b;
}