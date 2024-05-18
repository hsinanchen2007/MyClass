#include<stdio.h>

void  main()
{
	int  a[5] = {1,2,3,4,5};

	//数组名就是一个地址，是这一段内存空间的首地址
	printf("%p  ， %p\n",a  ,  &a[0]);

	int *p = a;

	//操作数组方式一，把指针变量当数组名用
	for (int i = 0; i < 5; ++i)
	{
		printf("%d    ",  p[i]);
	}

	printf("\n");

	//操作数组方式二，把指针变量+ 偏移量 来获得每个元素的首地址
	printf("%p    ", p );
	for (int i = 0; i < 5; ++i)
	{
		printf("%d    ",  *(p + i) );//指针变量的值不变
	}
	printf("%p    ", p);


	printf("\n");

	//操作数组方式三，把指针变量 自加++  来获得每个元素的首地址
	printf("%p    ", p);
	for (int i = 0; i < 5; ++i)
	{
		printf("%d    ",  *(p++)  );//指针变量的值改变了
	}
	printf("%p    ", p);


	// 错误、数组名a 是常量，不可改变
	for (int i = 0; i < 5; ++i)
	{
		//printf("%d    ", *(a++)); 
	} 

	printf("\n");
	//指针数组，每个元素都是地址
	int  * d[3] = {   a,  &a[1],  &a[2] };
	for (int i = 0; i <3; ++i)
	{
		printf("%p    ", d[i]); 
	}


}