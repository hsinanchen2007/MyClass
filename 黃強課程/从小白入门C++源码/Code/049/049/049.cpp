#include<iostream>
using namespace  std;
 
class  A
{
	//声明友元类
	friend  class  B;

public: 
	A()
	{
		a = 100;
	}

private:
	int  a; //私有成员
};

 
class  B
{
public:

	//成为A的友元函数
	void  print(A  a)
	{
		cout << a.a << endl;
	}

	//成为A的友元函数，加&真正改变a的成员变量
	void  setValue(A &  a,  int  a2)
	{
		a.a= a2;
	}
	 
};



int  main()
{

	A  a;
	B  b;

	//可以随意访问A的私有成员
	b.setValue(a, 200);
	b.print(a);
 

	return 0;
}