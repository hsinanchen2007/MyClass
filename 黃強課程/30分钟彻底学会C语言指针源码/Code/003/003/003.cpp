#include<stdio.h> 
 
int  main()
{
	int  *p1 = NULL;//初始化为空,0
/*
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif
 */

	char *p2 = NULL;
	float *p3 = NULL;


	int  a;//定义一个整型变量a
	//问题来了，如何获取a的内存地址？
	//通过& 来获取

	printf("a的内存地址： %p\n",  &a);

	//int *  pA = (int *)0x00D7FAF0 ;//理论上可以这么赋值,
	                                                    //但是你很难知道内存地址
	int  *pA = &a;//实际中的写法


	//char *pB = &a;//错误， char * 不能用int * 赋值， 所以需要保持一致


	int  b = 5;
	int  *pB = &b;
	printf("b中的内容： %d\n", *pB);



	return 0;
}