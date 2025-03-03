// 012.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>

#include<deque>

using namespace  std;

int main()
{
	//空的双端队列
	deque<int> d;
	cout << "元素个数" << d.size() << endl;

	deque<int> d2(5);//指定元素个数，默认值为类型默认值
	cout << "元素个数" << d2.size() <<"   "<<d2[0]<< endl;

	deque<int> d3(5,111);//指定元素个数，每一个指定元素值111
	cout << "元素个数" << d3.size() << "   " << d3[4] << endl;

	deque<int>  d4(d3);//拷贝构造
	cout << "元素个数" << d4.size() << "   " << d4[3] << endl;


	//像数组一样的访问元素（内存空间并不是连续的）
	d2[0] = 1;
	d2[1] = 2;
	d2[2] = 3;
	d2.at(3) = 4;

	for (size_t i = 0; i < d2.size(); i++)
	{
		cout << d2[i] << "		";
	}
	cout << endl;


	//验证deque的内存空间不是连续的
	{
	    
		deque<int>  d;

		for (size_t i = 0; i < 20; i++)
		{
			d.push_back(i);
			cout << "元素" << d[i] << " " << &d[i] << '\t';

			if ((i + 1) % 4 == 0)cout << endl;
		} 
		cout << endl; 
	
	
	}



    return 0;
}

