// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include<iostream>
using namespace std;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{

	cout <<"ʵ�����"<< hModule << "   ԭ�� "<< ul_reason_for_call << "     ���ӷ�ʽ" << lpReserved << endl;

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH://����dllʱ
		cout << "DLL_PROCESS_ATTACH" << endl;
		break;
	case DLL_THREAD_ATTACH://�����߳�
		cout << "DLL_THREAD_ATTACH" << endl;
		break;
	case DLL_THREAD_DETACH://�߳̽���
		cout << "DLL_THREAD_DETACH" << endl;
		break;
	case DLL_PROCESS_DETACH://�ͷ�dllʱ
		cout << "DLL_PROCESS_DETACH" << endl;
		break;
	}
	return TRUE;
}

