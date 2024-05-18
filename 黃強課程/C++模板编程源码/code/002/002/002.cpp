#include<iostream>
using namespace std;

//typedef  string  T;


//函数模板
 template  <typename  T>//不允许重复定义T
 inline  T  sum(T  a, T  b)//inline关键字不能写在template前面
{
    //typedef  string  T;//放到模板体里面则会错误，不允许T重名

	//这里的T不受外界的干扰
	T  tmp = a + b;
	return  tmp;
}

//演示多个类型参数,意义不大
template  <typename  T1, typename T2,  class  T3 >//每种类型参数前必须有class或者typename
T3  sum(T1  a, T2  b)
{
	T3  tmp = a + b;
	return  tmp;
}


void main()
{
 
	//模板函数

	//整型求和函数
    int  a= 	sum<int>(111, 999);
	cout << a << endl;
	 
	//单精度求和函数
	float  b = sum<float>(1.234f,  2.345f);
	cout << b << endl;

	//双精度求和函数
	double  c= sum<double>(1.234f, 2.345f);
	cout << c << endl;


	//第二种函数模板
	double  d = sum<int ,float,double>(100, 2.345f);
	cout << d << endl;
 
}