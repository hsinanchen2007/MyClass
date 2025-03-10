// 010.cpp: 定义控制台应用程序的入口点。
// 
#include "stdafx.h"

#include<iostream>

#include<vector>//动态数组
using namespace std;


template<class T>
void   Print(T  begin, T  end)
{
	//此处编写代码
	for (T p = begin; p != end; ++p)
	{
		cout << *p << "		";
	}
	cout << endl;
}


int main()
{
	vector<int>  v(5);//构造一个空间大小为5，并且元素为5个（有默认值）的vector

	//像数组一样的访问vector
	v[0] = 1;//vector重载了[]运算符
	v[1] = 2;
	v[2] = 3;
	v.at(3) = 4;
	v.at(4) = 5;

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << "	";
	}
	cout << endl;


	{
	//验证vector的迭代器是随机访问迭代器（支持++  、-- 、 +n、  +=n 、-=n 、 -n 、 *、[]   ）
	//random_access_iterator
	cout << typeid(vector<int>::iterator::iterator_category).name() << endl;

	vector<int>::iterator  it = v.begin();//begin返回v的第一个元素的迭代器
	cout << "v开头的迭代器指向的元素值：" << *it << endl;

	++it;//it的值改变
	cout << "v第二个的元素值：" << *it << endl;

	cout << "v第四个的元素值：" << *(it + 2) << endl;//此刻这里的it还是指向第二个，没变

	it -= 1;//it的值改变
	cout << "v第一个的元素值：" << *it << endl;

	cout << "v第五个的元素值：" << it[4] << endl;//这里的it没变
}
	//可以改变指向元素的值
	vector<int>::iterator  it = v.begin();
	*it = 111;

	//使用迭代器遍历元素
	for (vector<int>::iterator  it = v.begin() ;   it!=v.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	//常迭代器  指向的元素值不可改变,  类似  const int  *p; 
	vector<int>::const_iterator   it2 = v.cbegin();
	//*it2 = 111;


	//反向迭代器
	for (vector<int>::reverse_iterator  it3 = v.rbegin(); it3 != v.rend(); it3++)
	{
		cout << *it3 << "	";
	}
	cout << endl;



	//测试我们自己实现的Print算法,迭代器架起了 算法与容器之间的桥梁
	Print<vector<int>::iterator>(v.begin(), v.end());
	Print(v.begin(), v.end());
	Print<vector<int>::reverse_iterator>(v.rbegin(), v.rend());


	return 0;
}



