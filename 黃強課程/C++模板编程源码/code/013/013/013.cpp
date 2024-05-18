#include<iostream>
using namespace std;
 
template<typename T>//使用正在定义的A<void>
class A {
private:
	A<void> a;  //进入了一个递归定义，以致于无法明确A的定义
};

//特化终结递归定义
template <>
class A<void>
{
};


template<int N>
class Sum
{
public:
	enum//用枚举类型，因为用变量，它不会去在编译期推导值的（C++类成员变量初始化不能放在类定义中）
	{
		value = N + Sum<N - 1>::value 
	};
};

//需要特化0, 特化到哪里，定义就停在哪里，  如果特化到-1， 则结果到-1
template<>
class Sum<0>
{
public:
	enum
	{
		value = 0
	};
};


//定义到98就终止了求和
template<>
class Sum<98>
{
public:
	enum
	{
		value = 98
	};
};




// 主模板
template<unsigned long N>
struct  BinToDec
{
	static    const unsigned   val = BinToDec<N / 10>::val * 2 + N % 10;
};

template<>
struct  BinToDec<0>//特化
{
	static    const unsigned   val = 0;
};



void  main()
{
	A<int>  a;//模板类


	//利用编译期递归实现求和函数
   cout<<	Sum<100>::value<<endl;


   //利用编译期递归实现二进制转十进制
   cout << BinToDec<10000>::val << endl;
   cout << BinToDec<10001>::val << endl;
}