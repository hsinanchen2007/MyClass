#include<iostream>
using namespace  std;
#include<windows.h>

#include"../011/001.h"
#pragma comment(lib,"../Debug/011.lib")

//静态使用dll变量
//extern   _declspec(dllimport)  int  b;

int  main()
{

	cout << a << endl;

	//cout << b << endl;

	HMODULE  h = LoadLibrary(L"011.dll");
	//注意，这里不再是函数指针,而是变量指针
	int  *pB = (int*)GetProcAddress(h, "b"); 
	cout << *pB << endl;

	FreeLibrary(h);


	return 0;
}