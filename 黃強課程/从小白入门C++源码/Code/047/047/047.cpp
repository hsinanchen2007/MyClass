#include<iostream>
using namespace  std;

class  A
{
	//声明友元函数，赋予访问私有成员的特权
	friend  void  print(A   a);

public:
	A()
	{
		a = 100;
	}

private:
	int  a; //私有成员
};


void  print(A   a)
{
	//错误，对象无法访问类的保护、私有成员
	//声明为友元后，即可访问
	cout << "友元函数"<<a.a << endl;
}


int  main()
{
 
	A   a;
	print(a);

	return 0;
}