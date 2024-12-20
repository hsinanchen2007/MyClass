// 037.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<unordered_map>
using namespace  std;

int main()
{
	//  存储键值对， key值唯一， 无序
	unordered_map<int, string>  m = { {1,"AAA"}, {3,"CCC"},{2,"BBB"} , {1,"aaa"} };


	//插入元素,返回结果是pair, first指向插入元素的迭代器  ， second指示是否插入成功
   cout << "第一次插入："<< m.insert(make_pair(4, "DDD")) .second << endl;  
	cout<<"第二次插入："<<m.insert(make_pair(4, "ddd")).second <<endl ; //重复插入失败

	//[]运算 
	m[5] = "EEE";  //如果key不存在，就是插入  5->“EEE”
	m[5] = "eee";  //如果key存在，就是修改value为eee
	string  v6= m[6]; //注意：访问key为6的元素，竟然也是插入，value为类型默认值

	for (unordered_map<int, string>::iterator   it = m.begin(); it!= m.end(); it++)
	{
		cout << it->first << "->" << it->second.c_str() << "    ";
	}
	cout << endl;

	//unordered_map查找 ，效率 比map高 , 没找到返回 end()
	unordered_map<int, string>::iterator  it=m.find(55);
	if (it != m.end())
	{
		cout << "找到了" << it->second.c_str() << endl;
	}
	else
	{
       cout << "没找到!"<< endl;
	}	


	//使用[] 来查找，前提是你必须知道key是否存在，还是需要使用find


    return 0;
}

