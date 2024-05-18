#include<stdio.h> //系统头文件，包含了printf,scanf等系统函数的声明
#include<stdlib.h>//系统头文件，包含了malloc，free等函数

 

int  g = 100;//全局数据区，一般存放全局变量，静态变量，常量

void  main()//系统主函数，整个程序的入口函数，这个是它的简写
{ 

	int  a = 10;//栈区，局部变量，函数参数

	
	static  int b = 10;//哪怕是在函数体内，依然在全局数据区，只初始化一次


	char  str[] = "hello";// "hello"是常量、在全局数据区，但是str在栈区
 
	//程序员手动分配4个字节的内存空间，首地址给p
	int  *p = (int *)malloc(4);//堆内存 

	//程序员手动释放堆内存
	free(p);

} 

 