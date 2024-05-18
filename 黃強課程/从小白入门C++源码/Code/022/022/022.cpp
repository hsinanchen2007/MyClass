#include<iostream>
using  namespace  std;


class   A
{
public:

	//1.在构造函数体内初始化
	/*
	A(int a, int b)
	{
		//  成员变量a 与 b 这里并没有被赋值，因为这里的a，b全部都是形参，把成员变量隐藏了
		a = a;
		b = b;
		cout << "自定义有参构造函数！" << endl;
	}

	//解决方法一：  形参与成员变量名不同即可
	A(int a1, int b1)
	{
		a = a1;
		b = b1;
		cout << "自定义有参构造函数！" << endl;
	}
	

	//解决方法二：  使用this指针
	A(int a, int b)
	{
		this->a = a;//明确的指出是对象自己的a、b
		this->b = b;
		cout << "自定义有参构造函数！" << endl;
	}
	*/

	//2.使用初始化列表进行成员变量的初始化
	A(int a1, int b1):  b(b1), a(a1)
	{ 
		cout << "自定义有参构造函数！" << endl;
	}
	 
	void  print()
	{
		cout << a<<"   " <<b<< endl; 
	}

private:
	int  a;//按照此处的定义顺序初始化
	int  b; 
};


int  main()
{
 
	A  a(111,222);
	a.print();

	return 0;
}