# include <stdio.h> 
# include <stdlib.h> 


void main()
{
	int    a = 10;
	char b = 'A';
	float c = 12.3456;


	//空类型可以指向任何类型的变量
	void *pA = &a;
	void *pB = &b;
	void *pC = &c;

	//如何来使用原来的变量 
	//int  a1 =(int)( *pA);//错误的

	int  a1 =  (*  (int*)pA );//正确的转换
	printf("%d\n", a1);

	int a3;//值是随机的
	printf("%d\n", a3);

	int *pA3;//野指针，危险
	pA3 = NULL;//   #define NULL ((void *)0)
	printf("%p\n", pA3);

	pA3 = (int *)malloc(4);
	printf("%p\n", pA3);//合法的内存地址

	free(pA3);
	printf("%p\n", pA3);//被销毁的内存地址，此时pA3沦为野指针
	pA3 = NULL;//置空，避免野指针

}