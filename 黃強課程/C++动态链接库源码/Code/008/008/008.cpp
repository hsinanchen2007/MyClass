// 008.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"

//��ʾ_cdecl  _stdcall    _fastcall  ���ֵ���Լ���µĺ�������
extern "C" _declspec(dllexport)     int   _fastcall   fun( )
{
	return 0;
}
