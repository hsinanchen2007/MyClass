// 008.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

//演示_cdecl  _stdcall    _fastcall  三种调用约定下的函数名称
extern "C" _declspec(dllexport)     int   _fastcall   fun( )
{
	return 0;
}
