#include<iostream> 
using namespace std;


//加上引用，参数变成实参的别名,实现了和指针一样的效果
void  swap(int  & a, int  &b)
{
	int  temp = a;
	a = b;
	b = temp;
}

int  main()
{

	int  a = 111;
	int & a1 = a ;// a1 是a的引用类型， 即a1就是a的别名，他们是同一个变量

	cout << a << "," << a1 << endl;
	cout << &a << "," << &a1 << endl;//a与a1地址一模一样，是同一个变量

	a1 = 222;//同时改变a的值
	cout << a << "," << a1 << endl;


	int  b = 333;
	swap(a, b);
	cout << a << "," << b << endl;

	cout << a1 << endl;

	//int  &c;//错误，引用必须初始化


	return 0;
}
