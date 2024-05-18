#include <stdio.h>

void  swap(int a, int b)
{
	int  temp = a;
	a = b;
	b = temp; 
}

void  swap2(int *a, int *b)
{
	int  temp = *a;
	*a = *b;
	*b = temp;
}

void  swap3(int **a, int **b)
{
	int *  temp = *a;
	*a = *b;
	*b = temp;
}

 

void  main()
{
	int  a = 10;
	int  b = 20;

	//交换失败，函数内仅仅是实参的拷贝，与实参无关
	swap(a,b);
	printf("%d, %d\n",a,b );

	//交换成功， 实参的地址传入，直接操作实参的内容 
	swap2(&a, &b);
	printf("%d, %d\n", a, b);


	int c = 30;
	int d = 40;
	int *pC = &c;
	int *pD = &d;
	//交换失败，函数内仅仅是实参的拷贝，与实参无关
	swap(pC, pD);
	printf("%d, %d\n", *pC, *pD);

	//错误的传参、但是由于强制类型转换、阴差阳错的对了
 	swap3(pC, pD);
  	printf("%d, %d\n", *pC, *pD);

	//交换成功，正确的写法、原理同上，因为指针变量也是变量，并没有什么特殊
	swap3(&pC, &pD);
	printf("%d, %d\n", *pC, *pD);
}