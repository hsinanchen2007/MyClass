// 024.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<queue>
#include<list>
#include<array>
#include<forward_list>
#include<iostream>

using namespace std;

int main()
{ 

	//队列，先进先出
	 queue<int, list<int>>  q;  //list可以，支持 push_back, pop_front,font,back

	//queue<int, vector<int>>  q;//vector不可以，不支持 pop_front

	 //queue<int, forward_list<int>>  q;//forward_list不可以，不支持 push_back

	 //queue<int, array<int,5>>  q;//array不可以，不支持 pop_front,push_back
	  

	//入队列
	q.push(1);
	q.push(2);
	q.push(3);

	//出队列
	while (!q.empty()) //判断队列是否为空
	{
		cout << "队列头元素" << q.front() << endl;
		q.pop();//出队列
	}



	return 0;
}

