// 024.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<queue>
#include<iostream>

using namespace std;

int main()
{

	//默认构造函数，队列，先进先出
	queue<int>  q;
	cout << "元素个数:"<<q.size() << endl; 

	//拷贝构造队列
	queue<int>  q2(q);
	cout << "元素个数:" << q2.size() << endl;

	//打印queue内部容器类型,和stack一样，是双端队列deque
	cout <<  typeid(queue<int>::container_type).name()<< endl;


	//入队列
	q.push(1);
	q.push(2);
	q.push(3);

	//队列头元素
	cout << "队列头元素" << q.front() << endl;
	//队列尾元素
	cout << "队列头元素" << q.back() << endl;

	//出队列
	while (!q.empty()) //判断队列是否为空
	{
		cout << "队列头元素"<<q.front() << endl;
		q.pop();//出队列
	}




    return 0;
}

