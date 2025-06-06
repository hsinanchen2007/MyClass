// 040.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace  std;

int   nCount=0;//Min函数调用次数

//函数实现比较最小值 
int  Min(const int & a, const  int & b)
{
	nCount++;
	return  a < b ? a : b;
}

//仿函数   1、它是struct 或者 class   2.  ()运算符重载
struct   Min2
{
	typedef     int  ret_type;//定义内部类型

	//默认就是public
	int  operator () (const int & a, const  int & b)
	{
		++m_nCount;
		return  a < b ? a : b;
	}

	static  int m_nCount ; //保存Min2调用的次数
};
int   Min2::m_nCount=0;



class   Min3
{
public:
	int  operator () (const int & a, const  int & b)
	{
		return  a < b ? a : b;
	}

private:
	void(*pMin) (int a, int b); //可以包装函数指针
};



int main()
{ 
	//普通函数调用
	cout<<"最小值是："<<Min(111, 222)<<endl;

	//仿函数调用
	Min2  min2;//定义了一个结构体变量（对象）
	cout << "最小值是：" << min2(111,222) << endl; //对象的运算符成员函数

	cout << "最小值是：" << Min2()(111, 222) << endl; // Min2()构造无名对象 直接调用


	cout << "最小值是：" << Min3()(111, 222) << endl; // Min3()构造无名对象 直接调用


    return 0;
}

