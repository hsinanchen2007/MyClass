#include<stdio.h>

int  main()
{ 
	//二维数组也是一段连续的内存空间
	int  a[2][3] = { {1,2,3},{4,5,6} }; 
	for (int i = 0; i < 2;++i)
    for (int j = 0; j < 3; ++j)
	 {
		 printf("%p  ", &a[i][j]);
	 } 
	printf("\n");

	//二维数组的首地址，数组名或者第一个元素(这个元素是个一维数组)的地址
	printf("%p  %p\n", a, &a[0]);


	//定义二维数组指针
	int(*p)[3] =NULL;
	p = a;//赋值为二维数组名
	p = &a[0];//第一个元素(又是一个一维数组)的首地址

	//把指针当成数组名
	 for (int i = 0; i < 2; ++i)
	 for (int j = 0; j < 3; ++j)
    {
			printf("%d  ", p[i][j]);
	 }
	printf("\n");

	//利用指针访问元素
	for (int i = 0; i < 2; ++i)
	 for (int j = 0; j < 3; ++j)
	 {
			printf("%d  ",   *(p[i]+j)  );// p[i] 代表行指针,把p[i]看做一个数组名
	 }
	printf("\n");

	//利用指针访问元素
	for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 3; ++j)
	 {
			printf("%d  ", *(  *(p+i)  + j));// 把p[i] 这个一维数组再次分解
	 }
	printf("\n");


	//几种正确的赋值方式
	int(*p2)[3] ;
	p2= a;//行指针
	p2 = &a[0];//行指针 

	int  *p3;
	//p3 = a;//错误
	p3 = a[0];//普通指针
	p3 = &a[0][0];


	return 0;
}