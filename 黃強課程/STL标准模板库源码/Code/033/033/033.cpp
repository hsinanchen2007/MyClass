// 033.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<set>
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
	//class set :	       public _Tree<_Tset_traits<_Kty, _Pr, _Alloc, false>>
	//为false则不允许key重复
	set<int>  ss;
	
	//class multiset : public _Tree<_Tset_traits<_Kty, _Pr, _Alloc, true>>
	//为true允许你可以有多个相等的key
	multiset<int>  ms;

	//二者的唯一区别：  元素值是否重复
	 
	multiset<int>  s = {3,1,2,5,4,3}; //两个3都可以插入 

	s.insert(9);
	cout<<"返回迭代器"<< *s.insert(9)<<endl;//一定可以插入成功，返回新插入元素的迭代器


	s.erase(3);//删除所有元素值为3的元素


	for (multiset<int>::iterator  it = s.begin(); it!=s.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	//这个只能找到一个元素值为9的迭代器
	multiset<int>::iterator  it= s.find(9);
	if (it != s.end())
	{
		cout << "找到了" << *it << endl;
	}
	else
	{
		cout << "没找到！" << endl;
	}

	//找到所有值为9的迭代器
	//pair<multiset<int>::iterator, multiset<int>::iterator>  pa=s.equal_range(9);
	//for (multiset<int>::iterator it= pa.first;  it != pa.second  ; it++)
	cout << typeid(s.equal_range(9)).name() << endl;
	 auto  pa=s.equal_range(9);//让它自动识别，防止些一大串
	 for (auto it= pa.first;  it != pa.second  ; it++)
	{
		cout << *it << "		";
	}
	cout << endl;


	//multiset<int>::iterator是双向迭代器   bidirectional_iterator_tag
	cout << typeid(multiset<int>::iterator::iterator_category).name() << endl;



	//测试Print
	Print<multiset<int>::reverse_iterator>(s.rbegin(), s.rend());



    return 0;
}

