// 003.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include"003.h"

//����������ʹ��dllexport
extern "C"  _declspec(dllexport)    int  sum(int a, int  b)
{
	return  a + b;
}

