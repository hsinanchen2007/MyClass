// 026.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

#include<queue>

using namespace  std;

int main()
{
	//优先队列，默认less<>
	//priority_queue<int> q;  

	priority_queue<int, vector<int>, greater<int>> q; //低优先级先出队列
	cout << "元素个数" << q.size() << endl;

	//priority_queue<int> q2(q);
	//cout << "元素个数" << q2.size() << endl;

	//优先队列内部使用的容器
	cout <<typeid( priority_queue<int>::container_type).name() << endl;

	//优先队列优先级使用的比较仿函数，less代表高优先级先出队列
	cout << typeid(priority_queue<int>::value_compare).name() << endl;


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

