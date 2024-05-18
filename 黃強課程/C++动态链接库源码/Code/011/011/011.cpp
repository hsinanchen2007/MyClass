// 011.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

#define  DLL_EXPORT
#include"001.h"

//利用_declspec导出
DLL_API    int   a = 678;

//利用.def导出
int   b = 789;