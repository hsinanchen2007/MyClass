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
	 
	void print()
	{
		cout << a << endl;
	}

	//自定义&运算符重载函数
	A  *  operator  &()
	{
		cout << "自定义&运算符重载函数" << endl;
		return  this;//this指向当前对象的地址
	}
	  

private:
	int  a;
};


int  main()
{
 
	A  a(111);

	//实际上调用了系统默认提供的& 运算符重载函数
	cout << &a << endl;


	return 0;
}