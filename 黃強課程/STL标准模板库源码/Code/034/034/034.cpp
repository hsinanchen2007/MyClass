// 034.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h" 
#include<map>
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

ostream   &   operator<<(ostream   & os, multimap<int, string>::value_type & p)
{
	cout << p.first << "->" << p.second.c_str();

	return os;
}



int main()
{
	//class map  :        public _Tree<_Tmap_traits<_Kty, _Ty, _Pr, _Alloc, false>>
	//false表示key不可以重复
	map<int,string>  mm;

	//class multimap : public _Tree<_Tmap_traits<_Kty, _Ty, _Pr, _Alloc, true>>
	////false表示key可以重复
	multimap<int, string>  mmm;

	 //可以插入  key相同的  键值对pair
	multimap<int, string>  m = { {1,"AAA"} ,{2,"BBB"},{1, "aaa"} };

	m.insert(make_pair(3, "CCC"));
	//可以插入成功，允许重复key,返回指向插入元素的迭代器
	cout<< m.insert(make_pair(3, "CCC")) ->first   <<endl;

	//不支持[]运算符重载，因为我们的key是可以重复的，m[1]不知道返回哪个value
	//m[1];


	//m.erase(1);//删除所有key为1的元素

	//multimap正向遍历
	for (multimap<int, string>::iterator   it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << "->" << it->second.c_str() << "    ";
	}
	cout << endl;


	//查找key为1元素
	multimap<int, string>::iterator   it = m.find(1);
	if (it != m.end())
	{
		cout << "找到:" << it->second.c_str()<<endl;
	}
	else
	{
		cout << "没找到！" << endl;
	}


	//查找所有key为1元素的迭代器范围
	//pair<multimap<int, string>::iterator, multimap<int, string>::iterator>  pa=  m.equal_range(1);
	//for (multimap<int, string>::iterator it = pa.first; it != pa.second; it++)
	auto  pa=  m.equal_range(1);
    for (auto it = pa.first; it != pa.second; it++)
	{
		cout << it->first << "->" << it->second.c_str() << "    ";
	}
	cout << endl;


	//验证multimap<int, string> 迭代器的类型  bidirectional_iterator_tag
	cout << typeid(multimap<int, string>::iterator::iterator_category).name() << endl;


	multimap<int, string>::iterator   it2 = m.begin();
	//it2->first = 111;//不可更改key
	it2->second = "AAAAAA"; //value可以改


	//测试Print
	Print<multimap<int, string>::reverse_iterator>(m.rbegin(), m.rend());


    return 0;
}

