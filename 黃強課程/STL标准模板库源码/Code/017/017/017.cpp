// 017.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<list>
#include<iostream>
using namespace  std;


int main()
{

	list<int>  l;

	//头部插入一个节点（list容器肯定知道头部的位置）
	l.push_front(111);

	//尾部插入一个节点（list容器肯定知道尾部的位置）
	l.push_back(444);
	l.push_back(555);

	//在某个迭代器的位置之前插入
	l.insert(l.begin(), 222);

	//在某个迭代器的位置之前插入n个相同值元素
	l.insert(l.begin(), 3,333);


	//访问链表第一个元素
	l.front() = 1;
	cout <<"第一个元素:"<< l.front() << endl; 

	//访问链表最后一个元素
	cout << "最后一个元素:" << l.back() << endl;

	for (list<int>::iterator it = l.begin();  it!= l.end(); it++)
	{
		cout << *it << "	   ";
	}
	cout << endl;

	//删除链表头的元素
	l.pop_front();

	//删除链表尾的元素
	l.pop_back();

	//删除某个迭代器指向的元素
	l.erase(l.begin());
	 
	 //删除一段迭代器区间
	l.erase(l.begin(),l.end());

	//清空链表
	l.clear();

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << "	   ";
	}
	cout << endl;


    return 0;
}

