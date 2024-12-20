// 013.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>

#include<deque>

using namespace  std;


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
	deque<int> d2(5);//指定元素个数，默认值为类型默认值
	cout << "元素个数" << d2.size() << "   " << d2[0] << endl;

	//像数组一样的访问元素（内存空间并不是连续的）
	d2[0] = 1;
	d2[1] = 2;
	d2[2] = 3;
	d2.at(3) = 4;
	d2.at(4) = 5;
	for (size_t i = 0; i < d2.size(); i++)
	{
		cout << d2[i] << "		";
	}
	cout << endl;
 
	//deque<int>::iterator是随机访问迭代器
	cout << typeid( deque<int>::iterator::iterator_category ).name() << endl;

	//支持++ 、--、+=n、 -=n、[]、* 、+n、-n
	
	deque<int>::iterator  it = d2.begin();//获取指向容器的第一个元素的迭代器
	cout << "begin返回的迭代器指向的元素："<<*it << endl;

	*it = 111;//deque<int>::iterator可以改变迭代器指向的元素值

	it++;//下一个元素，it自身改变
	cout <<"++后:"<< *it << endl;

	it += 2;//往后移2个位置，it自身改变，指向第4个元素
	cout << "+=2后:" << *it << endl;

	cout << "-3后:" << *(it-3) << endl; //  it-3代表it位置的前3个位置，it自身不变

	cout << "[1]后:" << it[1] << endl; //指向最后一个

	it = d2.begin();//置为开头
	cout << "[i]后:" << it[1] << endl; //指向第二个


	//const_iterator只读的迭代器
	deque<int>::const_iterator   it2 = d2.cbegin();
	//*it2 = 11111; //无法改变元素的值，只能读取，类似于 const int  *


	//使用迭代器正向遍历
	for (deque<int>::iterator it = d2.begin(); it !=  d2.end(); ++it)
	{
		cout << *it << "		";
	}
	cout << endl;

	//使用反向迭代器反向向遍历
	for (deque<int>::reverse_iterator it = d2.rbegin(); it != d2.rend(); ++it)
	{
		cout << *it << "		";
	}
	cout << endl;


	//测试自己写的算法(无需知道deque容器的内存结构，具有通用性)
	Print<deque<int>::iterator>(d2.begin(), d2.end());
	Print(d2.rbegin(), d2.rend());//自动推导 

	return 0;
}

