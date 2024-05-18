#include<iostream>
using namespace  std;


//多重继承方式一
/*
//小明的爷爷
class  A
{
public:
	A()
	{
		a = 100;
	}
public:
	int  a;//爷爷的财产
};

//小明的爸爸
class  B : public  A
{
public:
	B()
	{
		b = 200;
	}
public:
	int  b;//爸爸的财产
};



class  C : public  B
{ 
};*/

//多重继承方式二
//小明的爸爸
class  A
{
public:
	A()
	{
		a = 100;
	}
public:
	int  a;//爸爸的财产
};

//小明的干爹
class  B 
{
public:
	B()
	{
		b = 200;
	}
public:
	int  b;//干爹的财产
};


//小明
class  C :   public  B  ,  public  A
{
};


int  main()
{

	C   c;
	cout << c.a<< endl;//拥有爸爸的财产
	cout << c.b << endl;//拥有干爹的财产

	return  0;
}