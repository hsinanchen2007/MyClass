#include<iostream>
using  namespace  std;

class  A
{
public:
	A(int a1)
	{
		a = a1;
	}
	//普通成员函数
	void  print1()
	{
		a = 200;
		cout << a << endl;
	}

	//常成员函数
	void  print2()  const
	{
		//a = 200;//常成员函数中不可修改任何成员变量的值
		cout << a << endl;
	}

private:
	int  a;
};


int  main()
{
 
	const   A    a(111);// a是常对象，只能调用常成员函数
	a.print2();
	//a.print1();//不能调用非常成员函数


	return 0;
}