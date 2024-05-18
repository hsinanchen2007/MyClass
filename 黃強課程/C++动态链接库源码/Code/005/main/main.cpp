#include<iostream>
#include<windows.h>
using namespace  std;

//extern  关键字，表示aaa在其他的文件中已经定义
//extern  int  aaa;

//在C++中使用C语言的函数
#ifdef  __cplusplus
extern  "C"
{
#endif
	 
#include"001.h"

#ifdef  __cplusplus
}
#endif


int  main()
{
	//cout << aaa << endl;

	HMODULE h = LoadLibrary(L"005.dll");
	typedef int(*PSUM)(int ,int);
	PSUM  psum = (PSUM)GetProcAddress(h, "sum");
   cout << psum(444, 555)<<endl;
   FreeLibrary(h);


   //在C++中使用C语言的函数
   fun();


	return  0;
}