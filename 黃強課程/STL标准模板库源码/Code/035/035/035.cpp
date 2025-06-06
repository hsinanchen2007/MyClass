// 035.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<unordered_set>
using  namespace std;

int main()
{

	// unordered_set 元素值唯一，无序的  集合，内部通过哈希表实现，查找效率比set高
	unordered_set<int> s = { 3,1,2,5,4,3 }; //重复元素无法插入
	

	//插入
	cout<<s.insert(9).second << endl;//无重复，插入成功，返回pair，second为true
	cout << s.insert(9).second << endl;//重复插入失败，返回pair，second为false
	 

	//删除
	s.erase(3);

	//查找,没找到返回end()
	unordered_set<int>::iterator   it = s.find(2);
	if (it != s.end())
	{
		cout <<"找到："<< *it << endl;
	}
	else
	{
		cout << "未找到！" << endl;
	}


	//正向遍历
	for (unordered_set<int>::iterator   it =  s.begin()   ; it  !=  s.end(); it++)
	{
		cout << *it << "     ";
	}
	cout << endl;

    return 0;
}

