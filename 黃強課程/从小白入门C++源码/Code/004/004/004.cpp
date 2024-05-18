#include<iostream>
using namespace std;

struct A {};

int  main()
{
	//直接输出类型名称
	cout<<typeid(int).name()<<endl;

	//直接输出类型名称
	cout << typeid(A).name() << endl;

	//输出变量的类型
	char  c = 'A';
	cout << typeid(c).name() << endl;

	//输出表达式的类型
	cout << typeid(  1.23*45    ).name() << endl;

	//输出字符串的类型
	cout << typeid( "hello").name() << endl;

	//指针类型
	int *p =  NULL;
	cout << typeid( p ).name() << endl;

	//const类型
	const char *p2 = NULL;
	cout << typeid(p2).name() << endl;



	return 0;
}