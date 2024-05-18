#include<iostream>
using  namespace  std;
 
class A
{
public:
	//自定义的有参构造函数
	explicit   A(int a) //加上explicit关键字，禁止隐式转换
	{ 
		this->a = a;
	}

	void  print()
	{
		cout << a << endl;
	}

private:
	int   a;
};


int  main()
{ 
	//标准的写法，调用有参构造函数
	A   a(111);
	a.print();

	//第二种写法, 编译器自动隐式将整数转换了A对象，因为构造函数是int参数
	A   a2 = 222;
	a2.print();


	return 0;
}