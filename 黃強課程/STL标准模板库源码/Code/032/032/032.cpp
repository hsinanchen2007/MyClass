// 032.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h" 
#include<map>
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

//为   map<int, string>元素类型提供 <<运算符重载
ostream  &  operator<<(ostream  &  os, map<int, string>::value_type   &p)
{
	cout << p.first << "->" << p.second.c_str() ;
	return  os;
}


int main()
{
	//map映射 关联容器 ，  每个元素都是 key-value 键值对  pair， 
	//key不能重复，value可以， 有序的
	map<int, string>  m;//构造空的map  
	m.insert(make_pair(3, "CCC"));
	m.insert(make_pair(1, "AAA"));
	m.insert(make_pair(2, "BBB")); 
	 
	//map<int, string>::iterator是双向迭代器 bidirectional_iterator_tag
	cout << typeid(map<int, string>::iterator::iterator_category).name() << endl;

	//双向迭代器，支持  ++  --  *   =    !=   == ，  不支持   [] 、+=n， -=n  +n  -n
	map<int, string>::iterator  it = m.begin();
	// it->first = 111; //map的key值不允许修改, map是按照key排好序的，如果你更改key值，会打乱顺序
	 it->second = "aaa"; //map的value允许修改

	 ++it;
	 cout << it->first << "->" << it->second.c_str() <<endl;

	 --it;
	 cout << "回到开头"<<(it == m.begin()) << endl;
	   
	 //const_iterator 指向的元素内容不可修改
	 map<int, string>::const_iterator  it2 = m.begin();
	// it2->first = 111; //均不可修改
	// it2->second = "aaa";//均不可修改

	 //查看两种iterator的真实类型
	 cout << typeid(map<int, string>::iterator).name() << endl;
	 cout << typeid(map<int, string>::const_iterator).name() << endl;
 
	  
	 //正向遍历
	for (map<int, string>::iterator it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << "->" << it->second.c_str() << "   ";
	}
	cout << endl;
	   
	//反向遍历
	for (map<int, string>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it)
	{
		cout << it->first << "->" << it->second.c_str() << "   ";
	}
	cout << endl;



	//使用Print ，无需知道map的内部结构，通过迭代器就可以遍历map的所有元素

	Print<map<int, string>::iterator>(m.begin(), m.end());


	return 0;
}

