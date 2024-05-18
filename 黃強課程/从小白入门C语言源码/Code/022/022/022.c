#include<stdio.h> //系统头文件，包含了printf,scanf等系统函数的声明

int sum(int  a, int b)
{
	return a + b;
}

void  main()//系统主函数，整个程序的入口函数，这个是它的简写
{ 

	//函数名就是一个地址（函数入口地址）
	printf("%p\n", sum );


	//定义一个函数指针变量, 必须与指向的函数形式保持一致
	int    (*  pSum)(int a, int b);

	//把函数地址赋给函数指针变量
	pSum = sum;

	//函数指针的使用
	 int  c= pSum(100, 200);//直接当做函数名用 sum(100,200);
	 printf("%d\n", c);

}

