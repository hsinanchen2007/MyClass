// 054.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace  std;

int main()
{
	//STL默认空间配置器allocator

	{
     //定义一个int类型的空间配置器
	allocator<int>  allo;
	//分配一个int的空间,4 Byte
	int  *pA = allo.allocate(1);
	//构造，对于原生类型int来说就是赋初始值
	allo.construct(pA, 111);

	//使用
	cout << *pA << endl;
	*pA = 222;

	//根据元素值获取地址
	const  int  *pB = allo.address(*pA);
	cout << (pA == pB) << endl;

	//最大大小
	cout << allo.max_size() << endl;

	//回收内存
	allo.deallocate(pA, 1);
}


	{
	//定义类A
		class  A 
		{
		public:
			A(int _a) : a(_a) { cout << "调用A的构造函数！" << endl; }
			~A( )  { cout << "调用A的析构函数！" << endl; }
				int  a;
		};
	
	//定义一个A类的空间配置器
	 allocator<A>  allo;

	 //分配一个A的空间
	 A  *pA = allo.allocate(1);

	// pA->a = 333;//分配后空间即可使用

	//调用有参构造对象
	 allo.construct(pA, 222);
	
	 //使用
	 cout << pA->a << endl;

	 //调用析构函数析构对象
	 allo.destroy(pA);

	 //回收内存
	 allo.deallocate(pA,  1);
	
	}


    return 0;
}

