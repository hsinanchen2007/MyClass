#include<stdio.h>


struct  A
{};

class  B
{};

void   fun(int  a  , int  b) //参数a，b在栈上， 在函数体结束的时候，栈内存释放
{
	int   c;//局部变量，在栈上， 在函数体结束的时候，栈内存释放
}

int  main()
{

	int  a = 10;//局部变量在栈上，  在main函数结束的时候，栈内存释放

	char  b[] = "hello";//数组变量也在栈上，  在main函数结束的时候，栈内存释放

	char  *c = NULL;//在栈上，  在main函数结束的时候，栈内存释放

	{
	    A   d;//结构体变量，  在栈上 
	    B   e;//类对象在栈上

	} //d,e 在离开这个{}时，栈内存销毁释放


	//测试栈的大小
	//char   buf[1024 * 1024] = { 'A' };//1M时崩溃了
	char   buf[1000* 1024] = { 'A' };//栈空间略小于1M

	//经过编译期设置为5M之后，栈空间变大了
	char   buf[49 * 1024 * 1024 / 10] = { 'A' };//栈空间略小于5M

	printf("%d" , sizeof(buf)  );



	return 0;
}


 