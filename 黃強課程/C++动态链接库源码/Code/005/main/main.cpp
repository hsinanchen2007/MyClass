#include<iostream>
#include<windows.h>
using namespace  std;

//extern  �ؼ��֣���ʾaaa���������ļ����Ѿ�����
//extern  int  aaa;

//��C++��ʹ��C���Եĺ���
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


   //��C++��ʹ��C���Եĺ���
   fun();


	return  0;
}