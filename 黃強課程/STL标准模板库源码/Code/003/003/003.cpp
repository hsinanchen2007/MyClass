
#include "stdafx.h"
#include<iostream>
using namespace  std;


/* 思考题一
现在有一个数组  int  arr[5] = { 1,2,3,4,5 };
void   Print(int  *begin, int  *end)
{
//此处编写代码
}
让 Print(arr, arr + 5);  实现打印所有元素？
*/


/*
void   Print(int  *begin, int  *end)
{
	//此处编写代码
	for (int *p = begin; p != end; ++p)//利用指针的++，依次访问每个元素
	{
		cout << *p << "		";
	}
	cout << endl;
}
*/

/*  思考题二

现在有一个链表，有5个Node节点：

struct   Node
{
int  data;
Node*  next;
};

void   Print(Node *begin, Node *end)
{
//此处编写代码
}

让 Print(pHead,  pTail );  实现打印所有元素？


*/

struct   Node
{
	int  data;
	Node*  next; 
};

ostream & operator <<(ostream&  o,const  Node &node)
{
	o << node.data;
	return   o;
}




/*
void   Print(Node *begin, Node *end)
{
	//此处编写代码
	for (Node *p    =begin;  p!= end ;  p=p->next) //指向下一个节点
	{
		cout << (*p).data << "		"; 
	}
	cout << endl;
}
*/



//思考题三
//写出一个通用的Print 函数模板
template<class T>
void   Print(T  begin, T  end)
{
	//此处编写代码
	for (T  p = begin; p != end; ++p)
	{
		cout << *p << "		";
	}
	cout << endl;
}


//虽然数组不需要迭代器，因为指针就是一种特殊的迭代器
//也可以设计一个数组迭代器
class  ArrayIterator
{
public:
	ArrayIterator(int *p) : _p(p) {}
	ArrayIterator  &  operator++()
	{ 
		++_p;//指针就是++指向下一个
		return  *this ;
	}

	bool   operator!=(const ArrayIterator & it)
	{
		return  _p != it._p;
	}

	int&   operator*()
	{
		return   *_p;
	}
	//private: 
	int * _p;
};




//考虑设计一个中间类，让它支持operator ++，实际实现是链表的p=p->next
//链表迭代器
class  ListIterator
{
public:
	ListIterator(Node *p) : _p(p) {} 
	ListIterator  &  operator++()
	{
		//链表的真正操作
		_p = _p->next;
		return  *this;
	}

	bool   operator!=(const ListIterator & it)
	{
		return  _p != it._p;
	}

	Node&   operator*( )
	{
		return   *_p;
	}
//private: 
	Node * _p; 
};
  

int main()
{
	//题目一测试
	int  arr[5] = { 1,2,3,4,5 };
	Print(arr, arr + 5); //arr + 5是指向 最后一个元素下一个的位置
	
	//Print<int *>(arr, arr + 5);//调用模板函数

	//使用数组迭代器
	{
		ArrayIterator  begin(arr);
		ArrayIterator  end(arr + 5);
		Print(begin, end);
	}



	 //题目二测试
	Node  n1;
	n1.data = 11;
	Node  n2;
	n2.data =22;
	Node  n3;
	n3.data = 33;
	Node  n4;
	n4.data = 44;
	Node  n5;
	n5.data = 55;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = NULL;

	//Print(&n1, n5.next); //错误，因为链表不是连续的，不能++



	//使用链表迭代器
	{
		ListIterator begin(&n1);
		ListIterator end(n5.next);
		Print(begin, end);
	}


    return 0;
}

