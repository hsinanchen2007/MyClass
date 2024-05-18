#include<stdio.h>

int  main()
{
   //字符串常量本身就是一个地址
	printf("%p\n", "hello");

	//定义字符串指针
	char *p = "hello";//用首地址赋值，可看做一个一维字符数组

	//利用指针访问字符数组,\0为最后一个元素
	for (int  i = 0; i < 6; i++)
	{
		//printf("%c", p[i]);
		//printf("%c",  *(p+i));
		printf("%c", *(p ++));
	}
	printf("---");//方便观看\0的存在
	printf("\n");

 
	//字符串常量不能赋值，哪怕你把它看做一个数组
	char *p2 = "hello";
	//p2[1] = 'a';//错误
	printf("%s", p2);


	return   0;
}