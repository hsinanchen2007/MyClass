#include<iostream>
using  namespace  std;


class  A
{
public:
	A(int  a1)
	{
		a = a1;
		cout << "调用自定义构造函数！" << endl;
	}

	A(const  A  &  a1)
	{
		a = a1.a;
		cout << "调用自定义拷贝构造函数！" << endl;
	}

	void print()
	{
		cout << a << endl;
	}

	//自定义=赋值运算符重载函数
	A   &  operator = (const A  &a1)
	{
		if (this == &a1)//自己赋值自己
		{
			return *this;//直接返回自己
		}

		a = a1.a;//进行赋值
		cout << "自定义=赋值运算符重载函数" << endl;
		return   *this;//返回对象本身
	}


private:
	int  a;
};


int  main()
{
	A  a(111);//调用有参的构造函数

	A     b(a);//调用拷贝构造函数 
	A    c = a;//调用拷贝构造函数


	A   e(222);//调用有参的构造函数

	//事实上，调用了默认的 =运算符重载函数, 进行了赋值
	a = e;//没有调用拷贝构造，这个时候，对象没有发生构造，a早就构造好了
	a.print();

	a = a;//自己赋值给自己
	a.print();

	return 0;
}