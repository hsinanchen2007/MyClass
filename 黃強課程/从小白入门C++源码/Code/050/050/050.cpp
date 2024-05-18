#include<iostream>
using namespace  std;
 
class   A
{
public :

	//虚函数
	virtual  void print()
	{
		cout << "A::print()" << endl;
	}

};


class  B: public  A
{
public:

	//虚函数, 重写虚函数
	virtual  void print()
	{
		cout << "B::print()" << endl;
	}

};




int  main()
{
	A  *pA = NULL;

	pA = new A;
	//同样的调用方法，不同的表现
	pA->print();


	pA = new B;
	//同样的调用方法，不同的表现
	pA->print();


	return 0;
}