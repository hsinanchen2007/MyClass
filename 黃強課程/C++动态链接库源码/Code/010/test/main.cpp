#include<iostream>
#include<windows.h>
using namespace  std;

//¾²Ì¬µ÷ÓÃdll
#include "../010/010.h"
#pragma comment(lib, "../Debug/010.lib")


DWORD  WINAPI ThreadFun(
	LPVOID lpThreadParameter
	)
{
	Sleep(10);

	return 0;
}


int  main()
{
	/*typedef  void(*PFUN)();
	HMODULE  h = LoadLibrary(L"010.dll");
	PFUN  fun = (PFUN)GetProcAddress(h, "?fun@@YAXXZ");
	 */
	cout << "--------main()---------" << endl;

	fun();

	//FreeLibrary(h);

	cout << "--------end-main()---------" << endl;
	 
	CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL);

	getchar();


	return 0;
}