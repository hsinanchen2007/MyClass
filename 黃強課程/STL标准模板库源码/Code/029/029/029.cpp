// 029.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<set> 
#include<iostream>

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
	//set 的特点， 值必须唯一， 有序 
	set<int>  s2 = { 3,2,5,1,4 ,3 };//初始化列表
	 
	//输出set迭代器的类别: bidirectional_iterator_tag 双向迭代器
	cout << typeid(set<int>::iterator::iterator_category).name() << endl;

    //双向迭代器，支持++ --   *   !=  ==  =  不支持  []  +=n  -=n  +n  -n
	set<int>::iterator it = s2.begin();//获取第一个元素
	cout <<"第一个元素"<< *it << endl;

	 // *it = 111;  //不可更改，说明set中元素值不可改变
	//符合逻辑，因为set中每个元素都已经根据值排列好了大小，此刻你若更改值，顺序无法保证

	++it;
	cout << "第二个元素" << *it << endl;

	--it;
	cout <<"是否指向开头"<<  (it  ==  s2.begin())<< endl;

	//常迭代器，不可更改指向的元素的内容
	set<int>::const_iterator it2 = s2.cbegin();//获取第一个元素
	 // *it2 = 111;  //不可更改set元素中的值

	//验证下， set<int>::iterator 与 set<int>::const_iterator 是一样的
	cout << typeid(set<int>::iterator ).name() << endl;
	cout << typeid(set<int>::const_iterator).name() << endl;
	


	//正向遍历
	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << "   ";
	}
	cout << endl;

	//反向遍历
	for (set<int>::reverse_iterator it = s2.rbegin(); it != s2.rend(); it++)
	{
		cout << *it << "   ";
	}
	cout << endl;


	//测试自定义的Print算法(迭代器，算法无需关心容器的内存结构)
	Print<set<int>::iterator>(s2.begin(), s2.end());
	return 0;
}

