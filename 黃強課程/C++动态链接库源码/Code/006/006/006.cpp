// 006.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include<iostream>
using namespace  std;

#define    _DLL_EXPORT    

#include "006.h"

DLL_API  void  fun()
{
	cout << "fun" << endl;
}
