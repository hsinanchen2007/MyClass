#include<iostream>
using namespace std;

//外部类模板
template<typename T1>
class  Outer
{
public:
	//内部类模板
	template<typename T2>
	class  Inner
	{
	public:
		T2   i;
		void print();
	};


public:
	T1 o;
	void  print(); 
};


template<typename T>
void Outer<T>::print()
{
	cout << "Outer print!" << endl;
}
  
//需要两级类名限定,同时需要两级模板声明
template<typename T1>
template<typename T2>
void Outer<T1>::Inner<T2>::print()
{
	cout << "Inner print!" << endl;
}



void main()
{
	//外部类
	Outer<int>  o;
	o.print();

	//内部类 
	Outer<int>::Inner<float> i;//同样加上::作用域限定符
	i.print();

}