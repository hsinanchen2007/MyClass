#include<iostream>
using namespace  std;
 

class  A
{
public:
	void  print()
	{
		cout << "A" << endl;
	}
};

class  B
{
private:
	A  a;//对象作为成员变量，组合思想，代理的思想
public:
	void  print()
	{
		cout << "B" << endl;
		a.print();
	}
};


template <typename  T>
class A1
{
public:
	void print();
};

template <typename T>
void A1<T>::print()
{
	cout << "A1" << endl;
}


//定义成这样，才能表示T是个模板
template <    template <typename X> typename     T  >
class B1
{
private:
	T<int>   a;//需要T是一个模板，才能这样写T<int>
public:
	void print();
};



template < template <typename X> typename   T>
void B1<T>::print()
{
	cout << "B1" << endl;
	a.print();
}




void  main()
{
	B b;
	b.print();

	//需要T是一个模板，用模板实例化
	B1<A1>  b1;
	b1.print();

}