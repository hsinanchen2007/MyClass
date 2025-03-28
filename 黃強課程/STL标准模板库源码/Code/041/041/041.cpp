// 041.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<functional>
using  namespace  std;


////一元函数对象（仿函数） 
//struct  IsOdd //判断奇数
//{
//	bool  operator()(int  a) //因为此处只有一个参数
//	{
//		return  a % 2 == 1; 
//	}
//
//};


//一元函数对象（仿函数） ,继承的方法
struct  IsOdd  :public  unary_function<int ,bool>
{
	result_type  operator()(argument_type  a) //因为此处只有一个参数
	{
		return  a % 2 == 1;
	}

};



////二元函数对象,求最小值
//struct  Min
//{
//	int  operator()(const  int & a, const int & b) //因为有两个参数
//	{
//		return  a < b ? a : b;
//	} 
//};

//二元函数对象,求最小值
struct  Min: public   binary_function<const int &,const int&,int>
{
	result_type  operator()(first_argument_type  a, second_argument_type  b) //因为有两个参数
	{
		return  a < b ? a : b;
	}
};


int main()
{
	//定义一个变量
	IsOdd::argument_type  a = 112; 
	IsOdd::result_type   ret = IsOdd()(a);
	cout << "是否是奇数:" <<ret<< endl; 


	//cout << "求最小值:" << Min()(111,222) << endl;
	Min::first_argument_type  a2 = 111;
	Min::second_argument_type  b2 = 222;
	Min::result_type  c2 = Min()(a2, b2);
	cout << "求最小值:" << c2<< endl;


    return 0;
}

