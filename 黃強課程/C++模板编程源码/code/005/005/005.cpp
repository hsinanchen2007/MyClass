#include<iostream>
using namespace std;


//类模板
template <typename T1, typename  T2>
class A
{
private:
	T1  a1;
	T2   a2;
public:
	void print()
	{
		cout << "A <T1,T2>: print!" << endl;
	}
};

//类的全特化,结构与主模板无需一致， 这就叫私人定制
template <>
class A<int ,float>
{

public:
	void print()
	{
		cout << "A <int,float>: print!" << endl;
	}

	void show()
	{
		cout << "A <int,float>: show!" << endl;
	}
};


//类的全特化,结构与主模板无需一致， 这就叫私人定制
template <>
class A<float, float>
{

public:  
	void show()
	{
		cout << "A <int,float>: show!" << endl;
	}
};


//类的偏特化
template <typename  T1>
class A<T1, float>
{
public:
	void show()
	{
		cout << "A <T1,float>: show!" << endl;
	}
};


//函数主模板
template <typename T1, typename T2>
void  test(T1  a, T2  b)
{
	cout << "test<T1,T2>！" << endl;
}

//函数的全特化
template <>
void  test(int  a,  int  b)
{
	cout << "test<int,int>！" << endl;
}


//函数没有偏特化，因为有了函数重载
template <typename T1>
void  test(T1  a, double  b)
{
	cout << "test<T1,char>！" << endl;
}

void main()
{
	//普通的
	A<int, int> a;
	a.print();
	//a.show();//没有这个成员函数，这就是与特化的区别

	//被全特化的
	A<int, float> a2;
	a2.print();
	a2.show();

	A<float, float> a3;
	//a3.print();//没有这个成员函数，这就是与特化的区别
	a3.show();


	//偏特化
	A< char, float> a4;
	a4.show();


	//普通的函数模板
	test<int, float>(1,2.0f);

	//全特化的模板
	test<int, int>(1, 2);

	//函数偏特化
	test<int, double>(1,1.234);
}