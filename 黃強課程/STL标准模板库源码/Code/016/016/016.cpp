// 016.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<list>

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
	list<int> l3(5, 111);//初始化5个元素，每个元素初始值为111
	cout << "元素个数:" << l3.size() << "  " << *(l3.begin()) << endl;


	//验证list容器的迭代器类型（5种之一）
	//双向迭代器bidirectional_iterator_tag
	cout << typeid(list<int>::iterator::iterator_category).name() << endl;

	//双向迭代器比随机访问迭代器弱一些，支持  ++  --   !=  ==  =  *   不支持[]  +n -n  +=n  -=n
	list<int>::iterator  it = l3.begin(); //指向容器l3的第一个元素
	cout << *it << endl;

	*(++it) =  222;
	*(++it) = 333;
	*(++it) = 444;
	*(++it) = 555;

	++it;//指向最后一个元素的下一个

	cout <<"迭代器指向末尾的下一个"<< (it == l3.end() )<< endl;

	--it;//指向最后一个元素
	cout << *it << endl;


	//it += 3;//不支持
	//it + 3;//不支持
	//it[0];//不支持


	//const_iterator常迭代器，类似于 const  int  *
	list<int>::const_iterator  it2 = l3.cbegin();
	//*it2 = 1;//不能修改常迭代器指向的内容


	//正向遍历
	for (list<int>::iterator it = l3.begin(); it != l3.end(); it++)
	{
		cout <<  *it << "   ";
	}
	cout << endl;


	//反向遍历
	for (list<int>::reverse_iterator it = l3.rbegin(); it != l3.rend(); it++)
	{
		cout << *it << "   ";
	}
	cout << endl;


	//测试自己的算法(迭代器带来的好处，算法无需关系容器的具体内存结构，就可以遍历)
	Print<list<int>::iterator>(l3.begin(), l3.end());
	Print(l3.crbegin(), l3.crend());//自己推到迭代器类型

	return 0;
}

