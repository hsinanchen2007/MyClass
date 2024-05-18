#include<iostream> 
using  namespace  std;//使用std名字空间下的所有变量

int   a = 100;

namespace  A
{
	int  a = 200;
	int   b = 300;

	namespace  B//名字空间的嵌套
	{
		int  b = 400;
		int  z = 900;
	}


	namespace  B//可以重复定义命名空间，相当于扩充
	{
		int  m= 800; 
	}

	//namespace  E;//错误，不能嵌套声明
}

namespace  C
{
	int  a = 500;
	int  b = 600;


	//匿名的名字空间
	namespace
	{
		int   c=1000;
	}
}
 
int  main()
{

	cout << a << endl;
	cout << A::a<< endl;
	cout << C::a << endl;


	cout << A::b << endl;
	cout << C::b << endl;

	cout << A::B::b << endl;

	//使用B名字空间下的所有变量
	using  namespace A::B;
	cout << b << endl;//可直接使用，无需前缀
	cout << z << endl;
	cout << m << endl;

	//演示了加前缀的写法，如果不加using  namespace  std， 必须加前缀std::cout
	std::cout << "hello!" << endl;



	//命名空间  A::B的别名FF
	namespace   FF =   A::B; 
	cout << FF::z << endl;


	//使用匿名的名字空间的变量
	cout << C::c << endl;

	return 0;
}