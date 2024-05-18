// 014.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//导出一个MFC的数组类变量
_declspec(dllexport)    CArray<int,int >   arr;

//接口中含有MFC类
_declspec(dllexport)  CString  GetStr()
{
	return   CString("hello");
}