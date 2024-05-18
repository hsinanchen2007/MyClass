#include<iostream>
using  namespace  std;

class  A
{
public:
	A(int  a1)
	{
		a = a1;
		cout << "调用构造函数！" << endl;
	}

	//固定写法，可以认为是构造函数的重载
	A(const  A   & a1)
	{
		a = a1.a;
		cout << "调用拷贝构造函数！" << endl;
	}


	void print()
	{
		cout << a << endl;
	}

private:
	int a;
};


int  main()
{
	A  a(111);//调用有参的构造函数

	A   b(a);//定义的时候用对象初始化，调用拷贝构造函数
	A   c = a;//定义的时候用对象初始化，调用拷贝构造函数
 

	//三个对象的成员变量a的值一样
	a.print();
	b.print();
	c.print();

	return 0;
}