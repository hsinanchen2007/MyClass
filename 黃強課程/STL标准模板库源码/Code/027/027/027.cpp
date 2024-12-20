// 026.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<deque>
#include<queue>
#include<array>
#include<forward_list>
#include<list>
using namespace  std;

int main()
{
	//优先队列，默认less<>
	//priority_queue<int> q;  

//	priority_queue<int, vector<int>, greater<int>> q; //低优先级先出队列
	 
    priority_queue<int, deque<int>> q;//deque可以，支持push_back  pop_back  front 

	//	priority_queue<int, list<int>> q; //推导出现问题

	// priority_queue<int, array<int,5>> q;// 不支持pop_back

	//priority_queue<int, forward_list<int>> q; //不支持pop_back

	//入优先队列 ，默认less，优先级高的先出队列
	q.push(9);
	q.push(1);
	q.push(4);
	q.push(3);

	while (!q.empty())//判断队列是否为空
	{
		cout << "栈顶元素" << q.top() << endl;//这里top返回队列头元素
		q.pop();//出队列
	}

	return 0;
}

