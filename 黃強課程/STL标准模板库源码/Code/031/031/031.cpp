// 031.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<map>
#include<iostream>

using namespace  std;

int main()
{
	//map映射 关联容器 ，  每个元素都是 key-value 键值对  pair， 
	//key不能重复，value可以， 有序的
    map<int, string>  m;//构造空的map 


	//插入pair
	pair<int, string>  p1(2, "BBB");
	m.insert(p1);
	 
	m.insert(pair<int, string>(1, "AAA"));

	//可以通过insert返回值的 成员.second查看是否插入成功，true成功，false是失败
	m.insert( make_pair<int, string>(2, "bbb")); //插入重复的key, 插入失败


	m.insert(make_pair(3, "CCC")); 


	// 插入其它容器中迭代器范围中的元素
	vector<pair<int, string>>  v = { {3,"ccc"}, {5, "EEE"},{ 4,"DDD" },{6, "FFF"} };
	m.insert(v.begin(), v.end());

	//[key]= value 
	m[7] = "GGG"; //对于不存在的key， 插入，相当于 (7,"GGG") 
	m[8];  //对于不存在的key，插入，相当于 ( 8,"")
	m[2] = "bbb";// 已经存在的key，相当于是修改元素的value


	for (map<int, string>::iterator  it = m.begin(); it!= m.end(); ++it)
	{
		cout << it->first << "->" << it->second.c_str() << "   ";
	}
	cout << endl;

	//查找key为3的元素，成功返回迭代器，失败返回end()
	{
		map<int, string>::iterator  it = m.find(33);
		if (it != m.end())
		{
			cout << "找到：" << it->first << "->" << it->second.c_str() << endl;
		}
		else
		{
			cout << "未找到!" << endl;
		}
	}

	//[key] 如果key存在，直接返回value
	//陷阱 ,如果key不存在，他会自动插入key，value为默认值再返回
	cout << "[key] "<< m[33].c_str() << endl;
	 
	for (map<int, string>::iterator it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << "->" << it->second.c_str() << "   ";
	}
	cout << endl;


	//删除key为3的元素
	m.erase(3); 

	//删除某个迭代器指向的元素
	m.erase(m.begin());

	//删除迭代器区间[)的元素
	map<int, string>::iterator it = m.begin();
	++it; ++it; ++it; //往后移动
	m.erase(m.begin(), it); 


	//删除所有元素
	m.clear();

	for (map<int, string>::iterator it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << "->" << it->second.c_str() << "   ";
	}
	cout << endl;

	return 0;
}

