// 030.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<map>
#include<iostream>

using namespace  std;

int main()
{
	//map映射 ，  每个元素都是 key-value 键值对，  key不能重复，value可以，有序的

	map<int, string>  m;//构造空的map
	cout <<"元素个数："<< m.size() << endl;

	//初始化列表构造map
	map<int, string>  m2 = { {3,"CCC"} ,  {1,"AAA"} ,  {2,"BBB"} };
	cout << "元素个数：" << m2.size() << endl;

	//拷贝构造
	map<int, string>  m3(m2);
	cout << "元素个数：" << m3.size() << endl;

	//验证map容器中的元素类型   pair<int, string>
	cout << typeid(map<int, string>::value_type).name() << endl;


	//一对值  pair 类模板
	pair<int, float>  p1;
	p1.first = 1;
	p1.second = 2.34f;


	pair<int, float>  p2(2, 3.45f); //有参构造
	cout << "first: " << p2.first << "     second:" << p2.second<< endl;

	//使用make_pair函数构造pair
	pair<short, char>  p3 = make_pair<short, char>(3, 'A');
	//pair<short, char>  p3 = make_pair(3, 'A');//自动推导
	cout << "first: " << p3.first << "     second:" << p3.second << endl;


	map<int, string>  m4 = {   pair<int, string>( 3,"CCC" )   ,  make_pair( 2,"BBB"),  make_pair(1,"AAA"), };
	cout << "元素个数：" << m4.size() << endl;

    return 0;
}

