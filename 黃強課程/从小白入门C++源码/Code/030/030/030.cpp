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

	//运算符重载
	A   operator  +(const A  & a1)
	{
		return  A(a + a1.a);
	}


	void print()
	{
		cout << a << endl;
	}


private:
	int  a;
};


int  main()
{
 
	A  a(111);//调用有参构造函数
	A  b(222);//调用有参构造函数

	//求两个对象的和,  +号运算符重载
	A   c = a + b;//调用有参构造函数
	c.print();

	return 0;
}