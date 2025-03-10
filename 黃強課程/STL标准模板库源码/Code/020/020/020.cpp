// 020.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<forward_list>
#include<iostream>
using namespace std;


int main()
{
	forward_list<int>  l; 
 
	/* 温习一下单链表的插入
	pNew->next =  pHead ->next;//新节点的下一个指向插入前的第一个节点
	pHead ->next= pNew;//将头指针指向新节点 
	*/
	l.push_front(111);//从头部插入元素
	l.push_front(222);//从头部插入元素
	l.push_front(333);//从头部插入元素
	/*
	   为什么没有insert_before() ？
		pInsert ->next;
		你无法知道当前节点的前一个节点的地址，所以，你就无法将前一个的pLast->next=pNew
		
		为什么insert_after()可以？
		pNew->next= pInsert->next;
		pInsert->next = pNew;
	*/
	l.insert_after(l.begin(), 444);//在某个迭代器后面插入 

	for (forward_list<int>::iterator it= l.begin()  ;  it !=  l.end(); it++)
	{
		cout << *it << "    ";
	}
	cout << endl;

	//访问头结点
	cout <<"front():  "<< l.front() << endl; 

	
	/* 温习一下单链表的删除
	pHead ->next= pDelete->next;//将头指针指向删除节点的下一个
    delete pDelete；//删除当前节点
	*/
	l.pop_front();//删除头结点


	/*
	为什么没有erase_before(),还是因为，你无法知道pDelete的前一个，
	你就无法将前一个的pLast->next= pDelete->next;

	为什么erase_after()可以?
	pTemp= pDelete->next;
	pDelete->next= pDelete->next->next;
	delete pTemp;
	*/
	l.erase_after(l.begin());//删除迭代器节点的下一个


	l.erase_after(l.begin(),l.end());//删除迭代器区间

	l.clear();//删除所有元素


	for (forward_list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << "    ";
	}
	cout << endl;

	return 0;
}

