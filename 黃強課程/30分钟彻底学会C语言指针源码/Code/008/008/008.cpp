#include<stdio.h>

int  main()
{
	//验证数组时一段连续的内存
	int   a[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; ++i)
	{
		printf("%p   ", &a[i]);
	}
	printf("\n");

	//数组名就是数组的首地址，并且&a[0]也是数组的首地址
	printf("%p    %p\n", a,  &a[0]);

	//指向一维数组的指针，事实上只要指向首地址，
	//后面的元素使用指针+N就可以访问
	int  *p = a;
	for (int i = 0; i < 5; ++i)
	{
		//printf("%p   ",  p+i   );//指针的加法
		printf("%d   ",*(p + i));//获取每个元素的值
	}
	printf("\n");


	for (int i = 0; i < 5; ++i)
	{
		// printf("%p   ",  p++   );//指针++
		printf("%d   ", *(p++));//获取每个元素的值,此刻这里的p值已经改变了
	}
	printf("\n");


	for (int i = 0; i < 5; ++i)
	{
		// printf("%p   ",  a+i   );//指针++
		printf("%d   ", *(a+i));//数组名是一个常量，不可改变，因而不能++
	}
	printf("\n");

 
 

	return 0;
}