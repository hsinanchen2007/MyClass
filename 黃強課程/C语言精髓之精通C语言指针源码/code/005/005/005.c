#include<stdio.h>
 
int  sum(int a, int b)
{
	return a + b;
}

typedef  int(*PFUN) (int);

//此函数返回函数指针，参数为整数
PFUN   fun(int  a)
{
	return NULL;
}



void  main()
{
	//函数名就是一个地址值
	printf("%p\n", sum);

	//定义sum函数指针变量pSum
	int(*pSum)(int ,int );
	pSum = sum;//给函数指针变量赋地址值

	 //定义sum函数指针变量pSum2
	int(*pSum2)(int, int);

	//定义函数指针类型
	typedef   int(*PSUM) (int, int);//只需要加入typedef

	//通过函数指针类型，定义指针变量
	PSUM   pSum3 = sum;

	//通过指针变量调用函数
	int  c = pSum3(111,999);
	printf("%d\n", c);

	//p是一个函数指针， 指向的函数，参数整型， 
	//返回值又是一个函数指针（参数、返回值都是整型）
	int(*(*p)(int)) (int);
	p = fun;

	//调用
	p(111);

}