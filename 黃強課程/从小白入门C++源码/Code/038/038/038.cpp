#include<iostream>
using  namespace  std;

class  A
{
public:
	A( )
	{ 
		pA = new int[10];
		cout << "A的构造函数！" << endl;
	}
	~A()
	{
		//做内存释放清理工作
		delete[]pA;
		pA = NULL;
		cout << "A的析构函数！" << endl;
	}
 
private:
	int  *pA;
};


class  B : public  A
{
public:
	 
	B()
	{ 
		pB = new int[10];
		cout << "B的构造函数！" << endl;
	}
	~B()
	{
		//做内存释放清理工作
		delete[]pB;
		pB = NULL;
		cout << "B的析构函数！" << endl;
	}


private:
	int  *pB;
};


int  main()
{
	//析构和构造的顺序正好相反
	B  b;

	return 0;
}