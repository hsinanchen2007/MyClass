// 023.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<vector>
#include<list>
#include<forward_list>
#include<array>
#include<stack>

#include<iostream>
using namespace  std;

int main()
{
	//更换stack的内部实现容器为vector,支持push_back ,  pop_back  ,back
	//stack<int,  vector<int>  > s;

	//更换stack的内部实现容器为list,支持push_back ,  pop_back  ,back
	stack<int, list<int>  > s;

	//stack<int, array<int,5>  > s; // array 不可以，没有pop_back

	//stack<int, forward_list<int>  > s; // array 不可以，没有pop_back

	//入栈，先进后出 FILO
	s.push(1);
	s.push(2);
	s.push(3);

	//遍历每一个元素，元素全部出栈
	while (!s.empty())
	{
		cout << "栈顶元素：" << s.top() << endl; //取栈顶元素
		s.pop();//出栈
	}




	return 0;
}

