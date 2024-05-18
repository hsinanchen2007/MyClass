// 005.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

//指示编译器这部分代码按C语言方式编译
extern "C"  _declspec(dllexport)  int    sum(int  a, int b)
{
	return a + b;
}