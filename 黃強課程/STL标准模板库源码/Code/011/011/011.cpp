// 011.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"

#include<iostream>
#include<vector>
using namespace  std;


int main()
{
	vector<int >   v;//定义一个空的动态数组
	cout << "容量:" << v.capacity() << "		元素个数:" << v.size() << endl;

	//往尾部插入元素   //    1
	v.push_back(1);
	cout << "容量:" << v.capacity() << "		元素个数:" << v.size() << endl;
	 
	v.push_back(2);     //      1  2 
	cout << "容量:" << v.capacity() << "		元素个数:" << v.size() << endl;

	//向某一个迭代器指向的位置插入
	v.insert(v.begin(), 3);//    3  1   2
	cout << "容量:" << v.capacity() << "		元素个数:" << v.size() << endl;


	//向某一个迭代器指向的位置插入2个值为4的元素
	v.insert(v.end()-1 ,  2, 4);//    3  1      4  4  2
	cout << "容量:" << v.capacity() << "		元素个数:" << v.size() << endl;


	//使用迭代器遍历
	for (vector<int >::const_iterator   it =  v.cbegin();   it!=  v.cend(); it++)
	{
		cout << *it << "		";
	}
	cout << endl;


	//访问第一个元素
	cout <<"front		" <<v.front() << endl;
	//访问最后一个元素
	cout << "back		" << v.back() << endl;
	//访问某一个下标的元素
	cout << "at			" << v.at(3) << endl;

	//删除最后一个元素
	v.pop_back();
	cout << "容量:" << v.capacity() << "		元素个数:" << v.size() << endl;

	//删除开头的元素
	v.erase(v.begin());
	cout << "容量:" << v.capacity() << "		元素个数:" << v.size() << endl;


	//删除结尾的元素, end()指向最后一个元素的下一个
	v.erase(v.end()-1);
	cout << "容量:" << v.capacity() << "		元素个数:" << v.size() << endl;


	//使用迭代器遍历
	for (vector<int >::const_iterator it = v.cbegin(); it != v.cend(); it++)
	{
		cout << *it << "		";
	}
	cout << endl;


	//删除所有元素，不会清除容量
	v.clear();
	cout << "容量:" << v.capacity() << "		元素个数:" << v.size() << endl;




	/*
	当size和capacity相等时继续添加数据，否则vector会扩容，
	每次扩容都是增加当前空间的1/2(第一次除外);
	*/
	{
		vector<int>  v;

		cout << "------------------------capacity容量随元素个数size增加的规律----------------------------" << endl;
		for (int i = 0; i < 50; i++)
		{
			v.push_back(i);
			cout << "v的容量：" << v.capacity() << "  元素个数:" << v.size() << endl;
		}
	}




    return 0;
}

