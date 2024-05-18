#include<iostream>
using  namespace  std;


class  A
{
public:
	A(int  a1):   a(a1)//初始化列表
	{
		//a = a1;  //这种写法不能用于 const的成员变量，需用初始化列表
	}

	void  print()
	{
		//a = 200;  //成员函数中，无法修改const成员变量
		cout << a << endl;
	}

private:
	const  int   a;//加上const、常成员变量
};


class  B
{
public:
	B(int  b1)  
	{
		 b = b1; 
	}

	//希望print中无法改变任何成员变量的值，则把他声明为const  、常成员函数
	void  print()  const
	{
		//b = 200;  不能进行任何修改成员变量的值，哪怕b可以修改
		cout << b << endl;
	}

	//普通成员函数
	void  print2()  
	{
		 b = 200;   
		cout << b << endl;
	}

private:
  int   b; 
};




 
int  main()
{
    //常成员变量
	A  a(111);
	a.print();
 
	//常成员函数
	B  b(333);
	b.print();
	b.print2();

	return 0;
}