#pragma once
#include<iostream>
using namespace std;
/*
//类的定义和实现放到同一文件中
class  A
{
public :
	A(int  a);
	void  Print();
private:
	int  a;
};


A::A(int  a)
{
	this->a = a;
}


void  A::Print()
{
	cout << a << endl;
}


*/


//类的定义和实现放到同一文件中
template <typename T>
class  A
{
public:
	A(T  a);
	void  Print();
private:
	T  a;
};


template <typename T>
A<T>::A(T  a)
{
	this->a = a;
}

template <typename T>
void  A<T>::Print()
{
	cout << a << endl;
}
