// 019.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<forward_list>
#include<iostream>
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
    forward_list<int>  l3(5, 111);//构造5个元素的单向链表，每个元素值为111
	cout << "第一个元素值：" << *l3.begin() << endl;//最大的元素个数
	 
	//验证迭代器类别,forward  iterator 前向迭代器
	cout << typeid(forward_list<int>::iterator::iterator_category).name() << endl;

	//前向迭代器 比 双向迭代器 功能更少一些，支持++、= 、！= 、 == 、 * ，不支持 -- 

    // 支持++    *   =
	forward_list<int>::iterator  it = l3.begin();
   
	*(++it) = 222;
	*(++it) = 333;
	*(++it) = 444;
	*(++it) = 555; //指向最后一个

	++it;//指向最后一个的下一个
	cout << "是否指向最后一个的下一个" << (it == l3.end()) << endl;

	//--it;//不可以--，因为是单向的


	//const_iterator指向的元素不可赋值
	forward_list<int>::const_iterator  it2 = l3.cbegin();
	//*it2 = 1;//const_iterator指向的元素不可赋值
	 

	 //正向遍历forward_list 
	for (forward_list<int>::iterator it = l3.begin(); it != l3.end(); ++it)
	{
		cout << *it << "    ";
	}
	cout << endl;

	//没有反向的迭代器，不支持，因为是单向链表
	//forward_list<int>::reverse_iterator


	//验证Print ,迭代器带来的好处，让算法无需知道容器的细节
	Print<forward_list<int>::iterator>(l3.begin(), l3.end());


	return 0;
}

