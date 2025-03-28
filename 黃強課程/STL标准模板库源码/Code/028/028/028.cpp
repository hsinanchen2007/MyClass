// 028.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<set>
#include<vector>
#include<iostream>

using namespace  std;

int main()
{
	//set 的特点， 值必须唯一， 有序

	set<int> s;//构造空的集合,默认less 升序
	cout << "元素个数" << s.size() << endl;

	 set<int>  s2 = {3,2,5,1,4 ,3};//初始化列表
	//set<int, greater<int>>  s2 = {3,2,5,1,4 ,3};//初始化列表,降序
	cout << "元素个数" << s2.size() << endl;

	set<int>  s3(s2.begin(),s2.end()); //拷贝迭代器范围内的元素
	cout << "元素个数" << s3.size() << endl;


	//插入元素 ,成功后返回值的成员second为1，失败为0
	//cout << typeid(s2.insert(9)).name() << endl; 
	cout<< s2.insert(9).second <<endl;

	//重复插入元素
	cout << s2.insert(9).second << endl;
	 
	vector<int> v = {6,7,8,9};
	s2.insert(v.begin(), v.end());//插入其它容器中元素的值

	 
	for (set<int>::iterator   it = s2.begin(); it!=s2.end(); it++)
	{
		cout << *it << "   ";
	}
	cout << endl;


	//删除值为6的元素
	s2.erase(6); 

	//删除迭代器指向的元素
	s2.erase(s2.begin());

	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << "   ";
	}
	cout << endl;

	//删除迭代器区间
	set<int>::iterator it = s2.begin();
	it++;	it++;	it++;
	s2.erase(s2.begin(), it);

	//s2.clear();//清空集合元素

	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << "   ";
	}
	cout << endl;

	//查找集合中的元素 ,找到返回指向该元素的迭代器，否则返回end()
	set<int>::iterator it2 = s2.find(99);
	if (it2 != s2.end())
	{
		cout << "找到:" <<*it2<< endl;
	}
	else
	{
		cout << "未找到！" << endl;
	}



    return 0;
}

