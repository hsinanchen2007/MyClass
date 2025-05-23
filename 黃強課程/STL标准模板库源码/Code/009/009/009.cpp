// 009.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>

#include<vector>//动态数组
using namespace std;

int main()
{
	vector<int>  v1;//构造一个空的vector
	cout << "容量为："<<v1.capacity() << "     元素个数: " << v1.size() << endl;

	vector<int>  v2(5);//构造一个空间大小为5，并且元素为5个（有默认值）的vector
	cout << "容量为：" << v2.capacity() << "     元素个数: " << v2.size() <<"	   v2[0]:"<<v2[0]<< endl;

	vector<int>  v3(5,111);//构造一个空间大小为5，并且元素为5个（每个元素初始值为111）的vector
	cout << "容量为：" << v3.capacity() << "     元素个数: " << v3.size() << "	   v3[0]:" << v3[0] << endl;

	vector<int>  v4(v3);//拷贝构造vector
	cout << "容量为：" << v4.capacity() << "     元素个数: " << v4.size() << "	   v4[0]:" << v4[0] << endl;


	//像数组一样的访问vector
	v2[0] = 1;//vector重载了[]运算符
	v2[1] = 2;
	v2[2] = 3;
	v2.at(3) = 4;
	v2.at(4) = 5;

	for (size_t i = 0; i < v2.size(); i++)
	{
		//cout << v2[i] << "	";
		//cout << v2.at(i)<< "	";
	     cout << &v2[i] << "	";//输出地址，说明存储空间是连续的
	}
	cout << endl;





    return 0;
}

