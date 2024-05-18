#include<iostream>
using namespace  std;
 

//定义类模板
template<typename T>
class Math
{
public:
	//在类内部仅声明
	T  Sum(T  a, T  b); 

	//在类的内部定义实现
	T   Max(T  a, T  b)
	{
		return a > b ? a : b;
	}

private:
	T   a;//成员变量

};

//类的外部实现成员函数
template<typename T>
T  Math<T>::Sum(T  a, T  b)
{
	return  a + b;
}


int  main()
{
 
	//int型的模板类Math
	Math<int >  m1;
	cout << m1.Sum(111, 222) << endl;


	//float型的模板类Math
	Math<float >  m2;
	cout << m2.Max(1.234, 4.567) << endl;

	return 0;
}