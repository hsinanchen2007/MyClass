// 004.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include   "004.h"
extern  "C"  _declspec(dllexport)    int   sum(int  a, int  b)
{
	return a + b;
}
