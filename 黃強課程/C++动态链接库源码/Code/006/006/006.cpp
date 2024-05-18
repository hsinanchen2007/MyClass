// 006.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include<iostream>
using namespace  std;

#define    _DLL_EXPORT    

#include "006.h"

DLL_API  void  fun()
{
	cout << "fun" << endl;
}
