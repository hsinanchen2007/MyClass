// 018.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<forward_list>
#include<iostream>
using namespace std;

int main()
{
	forward_list<int>  l;//构造空的单向链表
	//不提供size()的成员方法，使用算法distance()获取
	cout << l.max_size() << endl;//最大的元素个数

	forward_list<int>  l2(5);//构造5个元素的单向链表，值为类型的默认值
	cout << "第一个元素值："<<  *l2.begin() << endl;//最大的元素个数

	forward_list<int>  l3(5,111);//构造5个元素的单向链表，每个元素值为111
	cout << "第一个元素值：" << *l3.begin() << endl;//最大的元素个数

	forward_list<int>  l4(l3);//拷贝构造 
	cout << "第一个元素值：" << *l4.begin() << endl;//最大的元素个数


	//验证forward_list的内存结构(不连续)
	for (forward_list<int>::iterator it = l3.begin(); it != l3.end(); ++it)
	{
		cout << &(*it) << "    ";
	}
	cout << endl;




    return 0;
}

