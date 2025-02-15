// 038.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<unordered_map>
using namespace  std;

//用于<< 输出  pair<int  const , string>类型的对象
//ostream  &   operator  << (ostream  &  os, unordered_map<int, string>::value_type &p)
ostream  &   operator  << (ostream  &  os, pair<int  const , string>  &p)
{
	os << p.first << "->" << p.second.c_str();
	return os;
}

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
	//  存储键值对， key值唯一， 无序
	unordered_map<int, string>  m = { { 1,"AAA" },{ 3,"CCC" },{ 2,"BBB" } ,{ 1,"aaa" } };

	//迭代器的类别   :bidirectional_iterator_tag
	cout << typeid(unordered_map<int, string>::iterator::iterator_category).name() << endl;

	unordered_map<int, string>::iterator  it = m.begin();
	//it->first = 111;//无法修改unordered_map 的key值， 因为元素的位置是由key决定的，
	//如果你改了key值， 得到的哈希值与存储的位置不符合，乱套了
	it->second = "aaa"; //value值可以改

	unordered_map<int, string>::const_iterator  it2 = m.cbegin();
	//it2->first = 111;//无法修改unordered_map 的key值
	//it2->second = "aaa"; // const_iterator指向的元素内容不可修改

	//查看两种迭代器的类型
	cout << typeid(unordered_map<int, string>::iterator).name() << endl;
	cout << typeid(unordered_map<int, string>::const_iterator).name() << endl;


	//遍历
	for (unordered_map<int, string>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << "->" << it->second.c_str() << "    ";
	}
	cout << endl;
  

	//测试Print
	Print<unordered_map<int, string>::iterator>(m.begin(), m.end());

	//打印unordered_map<int, string> 元素类型  ，就是 *it得到的元素类型
	cout << typeid(unordered_map<int, string>::value_type).name() << endl;



	return 0;
}

