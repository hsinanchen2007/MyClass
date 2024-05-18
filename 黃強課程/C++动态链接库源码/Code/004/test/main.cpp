#include<iostream>
#include<Windows.h>
using namespace std;
/*
//dll的第一种调用方式:  .h+.lib+.dll
 //1、包含头文件（这里应该用_declspec(dllimport) 、但是我们发现也没报错 ）
#include  "../004/004.h"//extern  "C"  _declspec(dllimport)    int   sum(int  a, int  b); 
//2、 包含.lib文件
#pragma  comment(lib, "../Debug/004.lib") 
//3、发布的时候、.exe文件和.dll文件一起发布
*/

int  main()
{
	//cout << sum(111, 222) << endl; 

	//调用dll的第二种方式:  Win32 API+  .dll 
	//1.加载dll
	HMODULE  h=LoadLibrary(L"004.dll");
	//2.获取函数地址
	typedef   int(*PSUM)(int, int); 
	//3.利用函数指针调用函数
	//PSUM   psum=(PSUM)GetProcAddress(h, "sum");//利用函数名
	PSUM   psum = (PSUM)GetProcAddress(h, (char*)1);//利用序号获取函数地址
	cout << psum(333,444) << endl; 
	//4.释放dll
	FreeLibrary(h);

	return 0;
}