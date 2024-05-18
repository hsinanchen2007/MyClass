#include<iostream>
using namespace  std;


class A;//前置声明

class B
{public:	//只声明，不实现	void  print(A  a); 

};


class  A
{

public:
	//声明类的成员函数为友元函数
	friend  void  B::print(A   a);

	A()
	{
		a = 100;
	}

private:
	int  a; //私有成员
};

//只有把类成员函数的实现放到A定义的后面，才能够识别A
void  B::print(A  a)
{
	cout << a.a << endl;//类的成员函数访问A私有成员
}
 

int  main()
{
	A   a;
	B   b;
	b.print(a);

	return 0;
}