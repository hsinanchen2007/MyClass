// 014.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//����һ��MFC�����������
_declspec(dllexport)    CArray<int,int >   arr;

//�ӿ��к���MFC��
_declspec(dllexport)  CString  GetStr()
{
	return   CString("hello");
}