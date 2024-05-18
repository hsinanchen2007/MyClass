#include<stdio.h>

void  main()
{
	int  a = 10;
	int b = 20;
	int  c = 30;

	//指针数组，  本身数组名是一个地址，数组元素又是一个地址，双重指针
	int  * d[3] = {&a,  &b, &c};


	//定义指针的指针
	int  **p = d;//理解为指针的指针就是为指针数组而生的


	//1指针当成数组名
	for (int i = 0; i < 3; ++i)
	{
		printf("%d     ", *p[i] );
	}

	printf("\n");

	//2指针加上偏移量
	for (int i = 0; i < 3; ++i)
	{
		printf("%d     ",   *( * ( p+i )  ) );
	}


}