// 005.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"

//ָʾ�������ⲿ�ִ��밴C���Է�ʽ����
extern "C"  _declspec(dllexport)  int    sum(int  a, int b)
{
	return a + b;
}