#include<iostream>
using namespace  std;
#include<windows.h>

#include"../011/001.h"
#pragma comment(lib,"../Debug/011.lib")

//��̬ʹ��dll����
//extern   _declspec(dllimport)  int  b;

int  main()
{

	cout << a << endl;

	//cout << b << endl;

	HMODULE  h = LoadLibrary(L"011.dll");
	//ע�⣬���ﲻ���Ǻ���ָ��,���Ǳ���ָ��
	int  *pB = (int*)GetProcAddress(h, "b"); 
	cout << *pB << endl;

	FreeLibrary(h);


	return 0;
}