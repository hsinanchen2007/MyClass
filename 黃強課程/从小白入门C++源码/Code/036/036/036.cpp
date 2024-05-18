#include<iostream>
using  namespace  std;
 
//父类
class  A
{
public:
	A()
	{
		a = 100;
	}

	void  print()
	{
		cout << "A::print()" << endl;
	}

	int  a;//老爸的财产
};
 

//子类
class  B : public  A
{
	//什么都不做，坐享其成
};


int  main()
{
	B   b;
	cout<<b.a<<endl;//使用父类的成员变量
	b.print();//使用父类的成员函数


	return 0;
}