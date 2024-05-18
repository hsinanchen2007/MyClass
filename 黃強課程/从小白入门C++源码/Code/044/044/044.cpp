#include<iostream>
using namespace  std;

class  A
{
private:
	int   a1;
protected:
	int  a2;
public: 
	int  a3;
};


//公有继承  public
class B :public  A
{
public:
	B()
	{
	   //在子类的内部可以访问哪些
		//a1 = 100; //不可访问父类的私有成员, 不可见
		a2 = 200;//可访问父类的保护成员， 此刻它在子类中表现为protected
		a3 = 300;//可访问父类的公有成员 ,  此刻它在子类中表现为public 
	}

};

int  main()
{
	//利用子类的对象能否访问
	B  b;
	//b.a1=100;//不可见
	//b.a2=200;//它在子类中表现为protected， 对象无法访问
	b.a3 = 300;//它在子类中表现为public ,对象可以访问

	return 0;
}