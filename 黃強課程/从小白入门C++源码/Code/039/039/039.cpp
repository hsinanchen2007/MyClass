#include<iostream>
using namespace  std;


//���ؼ̳з�ʽһ
/*
//С����үү
class  A
{
public:
	A()
	{
		a = 100;
	}
public:
	int  a;//үү�ĲƲ�
};

//С���İְ�
class  B : public  A
{
public:
	B()
	{
		b = 200;
	}
public:
	int  b;//�ְֵĲƲ�
};



class  C : public  B
{ 
};*/

//���ؼ̳з�ʽ��
//С���İְ�
class  A
{
public:
	A()
	{
		a = 100;
	}
public:
	int  a;//�ְֵĲƲ�
};

//С���ĸɵ�
class  B 
{
public:
	B()
	{
		b = 200;
	}
public:
	int  b;//�ɵ��ĲƲ�
};


//С��
class  C :   public  B  ,  public  A
{
};


int  main()
{

	C   c;
	cout << c.a<< endl;//ӵ�аְֵĲƲ�
	cout << c.b << endl;//ӵ�иɵ��ĲƲ�

	return  0;
}