// 053.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace  std;


int   fun(int a) { return a; }
typedef  int( *PFUN)(int a); //函数指针类型
PFUN   pfun=fun; //函数指针遍历

struct  FUNO
{
	void  operator ()(int a)
	{ 	} 
};

int main()
{

	//判断一个类型是否为空
	cout << "void是否为void类型:"<<is_void<void>::value << endl;
	cout << "int是否为void类型:" << is_void<int>::value << endl;
	cout << "void *是否为void类型:" << is_void<void *>::value << endl;


	//判断一个类型是否是指针类型
	cout << "int *是否为指针类型:" << is_pointer<int *>::value << endl;
	cout << "int**是否为指针类型:" << is_pointer<int **>::value << endl;
	cout << "void*是否为指针类型:" << is_pointer<void*>::value << endl;
	cout << "void (*)(int ,int )为指针类型:" << is_pointer<void (*)(int ,int )>::value << endl;

	//判断一个类型是否是函数类型,  decltype返回变量的类型
	cout << "decltype(fun)是否为函数类型:" << is_function<  decltype(fun)  >::value << endl;
	cout << "PFUN是否为函数类型:" << is_function<   PFUN  >::value << endl;
	cout << "decltype(pfun)  是否为函数类型:" << is_function<    decltype(pfun)  >::value << endl;
	cout << "FUNO 是否为函数类型:" << is_function<  FUNO >::value << endl;


	//判断一个类型是否是数组类型  
	cout << " int [3] 是否为数组类型:" << is_array<  int [3]  >::value << endl;
	cout << " int [3] [4]是否为数组类型:" << is_array<  int[3][4]  >::value << endl;
	cout << "array<int ,3>是否为数组类型:" << is_function<  array<int ,3>  >::value << endl;
 
	//判断一个类型是否是另一个类型的基类  
	class  A {};
	class  B:A {}; 
	class  C:B {};
	cout << "int是否为int的基类:" << is_base_of<  int ,int >::value << endl;
	cout << "A是否为A的基类:" << is_base_of<A, A >::value << endl;
	cout << "A是否为B的基类:" << is_base_of<A, B >::value << endl;
	cout << "A是否为C的基类:" << is_base_of<A, C >::value << endl;

	//判断一个类型是否是为对象类型
	//对象类型是与其关联的存储类型，包括除函数，引用和void之外的所有类型。
	cout << "int是否为对象类型" << is_object<  int >::value << endl;
	cout << "string是否为对象类型" << is_object<  string >::value << endl;
    cout << "int(*)(int)是否为对象类型" << is_object<  int(*)(int)>::value << endl;
	cout << "int * 是否为对象类型" << is_object<  int*   >::value << endl;
	cout << "int & 是否为对象类型" << is_object<  int& >::value << endl;
	cout << "void 是否为对象类型" << is_object<  void >::value << endl;



    return 0;
}

