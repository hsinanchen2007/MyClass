// 014.cpp: 定义控制台应用程序的入口点。
// 

#include "stdafx.h"

#include<iostream>

#include<deque>

using namespace  std;


int main()
{
	deque<int>  d;

	d.push_back(1);//从尾部插入元素
	d.push_front(2);//从头部插入元素（vector没有此方法）
	d.insert(d.begin(), 3);//在迭代器位置插入
	d.insert(d.end(), 2, 4);//在迭代器位置插入2个元素值为4

	for ( int  i = 0; i < d.size(); i++)
	{
		cout <<d[i]<< "		";
	}
	cout << endl;

	//访问元素
	//d.at(0) = 111;
	//d[4] = 555;
	cout << d.front() << endl;//返回第一个元素
	cout << d.back() << endl;//返回第一个元素


	//删除元素
	d.pop_back();//从尾部删除
	d.pop_front();//从头部删除（vector不提供）

	d.erase(d.begin());//删除某个迭代器指向的元素

	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << "		";
	}
	cout << endl;

	d.clear();//全部清空

	cout << "元素个数："<<d.size() << endl;

	return 0;
}


