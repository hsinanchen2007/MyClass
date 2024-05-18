#include<iostream>
using namespace  std;

 //len就是非类型参数，它是一个整数
template<  int   len>
void   test()
{
	int  arr[len];//数组必须在编译期确定大小
	cout << sizeof(arr)<<endl;
}


char  str2[] = "hello world!";
//传入一个字符串
template< char *str>
void   test2()
{ 
	cout << str << endl;
}


int  i3 = 100;
//传入整型的引用
template< int &  i>
void   test3()
{
	cout << i << endl;
}


//传入指针
template< int *  p>
void   test4()
{
	cout << *p << endl;
}


void  fun5(int a)
{
	cout << a << endl;
}
//传入函数指针
template<void(*pf)(int)>void  test5(){	pf(666);};


void  main()
{
	//实现了动态数组，由用户指定长度
	test<10>();
	test<20>();


	//不能引用非外部实体
	//test2<"hello world!">();

	//char  str[] = "hello world!";
	//test2< str>();//非静态存储的变量

	test2<str2>();
 
	test3<i3>();

	test4<&i3>(); 

	test5<fun5>();
}