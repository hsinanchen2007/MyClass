// 004.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include   "004.h"
extern  "C"  _declspec(dllexport)    int   sum(int  a, int  b)
{
	return a + b;
}
