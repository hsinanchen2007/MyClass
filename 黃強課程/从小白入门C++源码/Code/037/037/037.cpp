#include<iostream>
using  namespace  std;
 
class  A
{
public:
	A(int  a1)
	{
		a = a1;
		cout << "A的带参数构造函数！" << endl;
	}

	void  print()
	{
		cout << a << endl;
	}
private :
	int  a;
};


class  B: public  A
{
public:
	//构造父类需要在初始化构造列表里实现
	B(int  b1, int  a1):   A(a1)
	{ 
		b = b1;
		cout << "B的带参构造函数！" << endl;
	}

	void  print()
	{
		A::print();//明确的指出调用A的print，  或者两个名字取不同的
		cout << b << endl;
	}


private:
	int  b;
};


int  main()
{
 
	//先有父亲，再有儿子， 先构造父类，再构造子类
	B  b(222,111);
	b.print();


	return 0;
}