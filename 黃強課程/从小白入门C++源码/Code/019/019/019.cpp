#include<iostream>
using  namespace  std;
 

class  A
{
public:
	 
	void   printThis()
	{
	  //this指针只能在类的内部使用 ，并且this总是已经被赋值为当前对象的地址，可放心使用
		cout << typeid(this).name()<<"    "<< this << endl;
	} 
};


int  main()
{
 
	A  a;//定义对象a

	//pA指向对象的地址
	A* pA = &a; 
	cout << pA << endl; 
	a.printThis();


	//每个对象都有一个this指针，指向自己的首地址
	A  a2;
	A* pA2 = &a2;
	cout << pA2 << endl;  
	a2.printThis();


	return 0;
}