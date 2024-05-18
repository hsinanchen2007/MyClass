#include<stdio.h>
#include<stdlib.h>

int  main()
{

	//malloc  ,参数是字节数 , 并且这块内存空间的值是随机的
	int  *p = (int *)malloc(5 *  sizeof(int));
	p[0] = 123;
	for (int i = 0; i < 5; ++i)
	{ 
		printf("%d   ", p[i]); //后面4个值随机
	}

	printf("\n------------------------------------------------------------\n " );

	//calloc，参数两个， 自动将内存空间初始化为0
	int   *p2 = (int *)calloc(5, sizeof(int));
	p2[4] = 123;
	for (int i = 0; i < 5; ++i)
	{
		printf("%d   ", p2[i]); 
	}



	printf("\n------------------------------------------------------------\n ");
	 
	//realloc ，可以调整内存空间的大小 ，并且拷贝原来的内容(调大，或者  缩小)
	//int  *p3 =(int *) realloc(p, 6* sizeof(int));//调大一点点，两个地址相同
	//int  *p3 = (int *)realloc(p, 2 * sizeof(int));//缩小，两个地址相同
	int  *p3 = (int *)realloc(p, 100 * sizeof(int));//调很大，两个地址不同 ,释放原来的内存空间
	for (int i = 0; i <2; ++i)
	{
		printf("%d   ", p3[i]);
	} 

	printf("\np地址：  %p   ，  p3的地址：  %p   ", p,  p3);
	 



	return 0;
}