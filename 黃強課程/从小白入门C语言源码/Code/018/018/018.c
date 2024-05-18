#include<stdio.h> //系统头文件，包含了printf,scanf等系统函数的声明
  
void  main()//系统主函数，整个程序的入口函数，这个是它的简写
{
	
	int a = 10;//整型变量
	char b = 'A';//字符型变量
	float c = 1.2345f;//单精度浮点型变量

	int    *  pA;//整型指针变量
	char *  pB;//字符型指针变量
	float *  pC;//单精度浮点型指针变量


	//给指针赋值, 你是什么类型的指针，就应该指向什么类型变量的地址
	pA = &a;// &是取变量的地址
	pB = &b;
	pC = &c;

	//打印一下指针变量的值,地址值
	printf("%p ,%p  \n", &a, pA);
	printf("%p ,%p  \n", &b, pB);
	printf("%p ,%p  \n", &c, pC);


	//获取指针指向内存空间中的内容   *pA
	printf("%d\n",  *pA );
	printf("%c\n", *pB);
	printf("%f\n", *pC);
 
}

