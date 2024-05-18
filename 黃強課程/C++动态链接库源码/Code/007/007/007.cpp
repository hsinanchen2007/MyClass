// 007.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

//利用.def文件导出
int   fun()
{
	return 110;
}

int   Min(int a, int b)
{
	return  a < b ? a : b;
}

int  Max(int  a, int b)
{
	return  a > b ? a : b;
}



