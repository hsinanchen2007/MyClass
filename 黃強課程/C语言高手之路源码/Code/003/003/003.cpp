#include<stdio.h>
#include<stdlib.h>

void  fun(char a[3])//这里参数为指针
{
	printf("fun   %d\n", sizeof(a));//指针
}

void  fun2(char (&a)[3]) //这里参数为数组的引用
{
	printf("fun   %d\n", sizeof(a));//数组
}
 
void  fun3(char(*a)[3]) //这里参数为指向一维数组的指针
{
	printf("fun   %d\n", sizeof( *a));//  *a数组
}


struct  A
{ 
	int   sum(int  a,int  b)
	{
		return a + b;
	} 
};


union  B
{
	char  a[13]; //最大空间为13，考虑对齐，为16
	int  b; 
};


//得到数组元素个数
#define   count(arr)   ( sizeof(arr)  /  sizeof(arr[0]))


int  main()
{
	//sizeof测试指针，指针全部都是4字节
	char  *p1 = "hello";
	printf("p1   %d\n",  sizeof(p1));

	char *  p2 = (char *)malloc(10);
	printf("p2   %d\n", sizeof(p2));

	void  *p22 = NULL;
	printf("p22   %d\n", sizeof(p22));

	//sizeof测试数组
	int  p3[100] = { 1, 2, 3 };
	printf("p3   %d\n", sizeof(p3));//注意：总字节 是整型4 *100 个元素

	int  p4[] = { 1, 2, 3, 4 ,5 };
	printf("p4   %d\n", sizeof(p4)); 

	char p5[] = "hello"; //注意， hello后面还有\0,所以大小为1*6
	printf("p5   %d\n", sizeof(p5));

	//sizeof测试二维数组
	int  p6[3][4];
	printf("p6   %d\n", sizeof(p6));//两个维度相乘*类型大小   3*4*4


	//sizeof测试函数参数
	char   a[3] = {1,2,3};
	fun(a);
	fun2(a);
	fun3(&a); //取一维数组的地址

	//sizeof测试空结构体
	printf("A   %d\n", sizeof(A));//空结构体内存最小为1
	//函数不占用内存空间
	 
	//sizeof测试联合体
	printf("B   %d\n", sizeof(B));//最大的成员大小，考虑内存对齐

	//sizeof陷阱
	int  i = 1;
	int  n = sizeof(++i);//因为sizeof是操作符，而不是函数，在编译时就确定了
	printf("sizeof(++i)   %d     n:%d\n", i  ,n);  //++i无效

	//测试得到数组个数
	printf("count    %d\n",  count(a));  



	return 0;
}