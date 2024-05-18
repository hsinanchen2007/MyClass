#include<stdio.h> 

struct  A
{
	int m;
	char n;
};

int  main()
{
	 //定义结构体变量
	struct   A    a = {555,'A'};
	struct   A*   pA = &a;//获取结构体变量的地址，赋给结构体指针变量
	printf("pA的值： %p\n",  pA);

	//  *pA 等价于 a
	printf("m:  %d,  n: %c \n", (*pA).m, (*pA).n);

	//利用结构体指针变量 加上-> 来 访问结构体成员
	printf("m:  %d,  n: %c \n",pA->m, pA->n);

	return 0;
}