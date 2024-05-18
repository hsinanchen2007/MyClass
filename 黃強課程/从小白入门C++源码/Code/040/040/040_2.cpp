#include<iostream>
using namespace  std;


//多重继承方式一
class  A
{
public:
	A(int  a1)
	{
		cout << "A构造函数！" << endl;
		a = a1;
	}
public:
	int  a;
};


class  B  
{
public:
	B(int  b1) 
	{
		cout << "B构造函数！" << endl;
		b = b1;
	}
public:
	int  b;
};

class  C : public A ,  public  B //这里AB顺序决定构造顺序
{
public:
	//用初始化列表构造父类带参数的构造函数
	C(int  a1, int b1, int  c1) : A(a1 ) , B(b1)//这里AB顺序无所谓
	{
		cout << "C构造函数！" << endl;
		c = c1;
	}
public:
	int  c;
};




int  main()
{

	C   c(111, 222, 333);

	cout << c.a << c.b << c.c << endl;


	return  0;
}