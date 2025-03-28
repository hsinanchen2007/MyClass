// 022.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stack>

#include<iostream>
using namespace  std;

int main()
{

	stack<int> s;//默认构造函数
	cout << "元素个数" << s.size() << endl;

	stack<int> s2(s);//拷贝构造函数
	cout << "元素个数" << s2.size() << endl;

	//打印内部使用的容器
	cout << typeid(stack<int>::container_type).name() << endl;


	//入栈，先进后出 FILO
	s.push(1);
	s.push(2);
	s.push(3);

	cout << "栈的元素个数:" << s.size() << endl;

	////出栈
	//cout <<"栈顶元素："<< s.top() << endl;
	//if (!s.empty())s.pop();//出的是栈顶元素

	//cout << "栈顶元素：" << s.top() << endl;
	//if (!s.empty())s.pop();//出的是栈顶元素

	//cout << "栈顶元素：" << s.top() << endl;
	//if (!s.empty())s.pop();//出的是栈顶元素

	//cout <<"栈的元素个数:"<< s.size() << endl;


	//if (!s.empty()) cout << "栈顶元素：" << s.top() << endl;
	//if (!s.empty())s.pop();//出的是栈顶元素


	//栈只允许取栈顶，不给其它接口访问元素
	//cout << s[0] << endl;//不支持[]

	
	//遍历每一个元素，元素全部出栈
	while (! s.empty())
	{
		cout << "栈顶元素：" << s.top() << endl; //取栈顶元素
		s.pop();//出栈
	}


	 cout << "栈的元素个数:" << s.size() << endl;


    return 0;
}

