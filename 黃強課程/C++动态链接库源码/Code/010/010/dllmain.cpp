// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include<iostream>
using namespace std;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{

	cout <<"实例句柄"<< hModule << "   原因 "<< ul_reason_for_call << "     链接方式" << lpReserved << endl;

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH://加载dll时
		cout << "DLL_PROCESS_ATTACH" << endl;
		break;
	case DLL_THREAD_ATTACH://创建线程
		cout << "DLL_THREAD_ATTACH" << endl;
		break;
	case DLL_THREAD_DETACH://线程结束
		cout << "DLL_THREAD_DETACH" << endl;
		break;
	case DLL_PROCESS_DETACH://释放dll时
		cout << "DLL_PROCESS_DETACH" << endl;
		break;
	}
	return TRUE;
}

