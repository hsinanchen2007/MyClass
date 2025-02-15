// 015.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<list>

using namespace std;

int main()
{

	list<int> l;//空的双向链表
	cout << "元素个数:" << l.size() << endl;

	list<int> l2(5);//初始化5个元素，默认值为类型的默认值
	cout << "元素个数:" << l2.size() <<"  "<<  * (l2.begin() )<< endl;

	list<int> l3(5,111);//初始化5个元素，每个元素初始值为111
	cout << "元素个数:" << l3.size() << "  " << *(l3.begin()) << endl;

	list<int> l4( l3 );//拷贝构造
	cout << "元素个数:" << l4.size() << "  " << *(l4.begin()) << endl;

	//不支持[]运算符，因为效率低
	//cout << l4[0] << endl;


	//验证了list容器的内存空间是不连续的
	for (list<int>::iterator   it = l3.begin(); it !=l3.end(); it++)
	{
		cout << &(*it) << "   ";
	}
	cout << endl;


    return 0;
}

