// 011.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"

#define  DLL_EXPORT
#include"001.h"

//����_declspec����
DLL_API    int   a = 678;

//����.def����
int   b = 789;