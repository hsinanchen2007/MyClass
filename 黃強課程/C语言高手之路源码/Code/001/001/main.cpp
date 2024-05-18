#include <stdio.h>
#include"001.h" 
#include"002.h"

//一个cpp文件就是一个编译单元    .h不参加编译


//重复定义全局变量
//int   a1 = 333;

 

int  main()
{

	fun1();
	fun2();


	//fun111(); //无法解析的外部符号

	//需要链接接标准库函数
	printf("hello  world!");

	return 0;
}