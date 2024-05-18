#include<iostream>
using  namespace  std;

 
class  A
{
public:
	//参数类型不同
	void  print(int  a)
	{
		cout <<"print(int  a)  "<< a << endl;
	}
	//参数类型不同
	void  print(char  a)
	{
		cout << "print(char  a)  " << a << endl;
	}

	//错误，无法重载仅仅返回值不同的函数
	/*
	int  print(char  a)
	{
		cout << "print(char  a)  " << a << endl;
	}
	*/


	//参数类型不同
	void  print(float  a)
	{
		cout << "print(float  a)  " << a << endl;
	}

	//参数个数不同
	void  print(int  a,int  b)
	{
		cout << " print(int  a,int  b) " << a <<b<< endl;
	}
	 

};


int  main()
{
 
	A  a;

	//同一函数名，根据函数重载，自动匹配
	a.print(123);
	a.print('A');
	a.print(1.234f);
	a.print(111, 222);



	return 0;
}