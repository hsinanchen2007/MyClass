#include<iostream>
using  namespace  std;


class  A
{
public:
	A()
	{
		++count;//每产生一个对象，引用计数加1
	}

	void print()
	{
		cout << "此时共产生了" << count << "个对象！" << endl;
	}

	//静态成员函数
	static  void print2()
	{
		//静态成员函数无法访问  非静态成员变量
		//cout << a << endl;//错误

		cout <<"静态成员函数："<< count << endl;//访问静态成员变量与静态成员函数
	}

public:
	static  int  count;//统计有多少个对象,静态成员，被所有的对象共享，只有一份内存空间
	int   a;
};

//静态成员变量只能在类外初始化，并且加上A::前缀
int    A::count = 0;


int  main()
{
	A  a;
	a.print();

	A   b;
	a.print();
	b.print();

	A  c;
	a.print();
	b.print();
	b.print();


	//两种访问公有静态成员变量的方式   A::     对象.
	cout << A::count << endl;
	cout << a.count << endl;

	//两种访问公有静态成员函数的方式   A::     对象.
	A::print2();
	a.print2();

	return 0;
}