#include<iostream>
#include<Windows.h>
using namespace std;
/*
//dll�ĵ�һ�ֵ��÷�ʽ:  .h+.lib+.dll
 //1������ͷ�ļ�������Ӧ����_declspec(dllimport) ���������Ƿ���Ҳû���� ��
#include  "../004/004.h"//extern  "C"  _declspec(dllimport)    int   sum(int  a, int  b); 
//2�� ����.lib�ļ�
#pragma  comment(lib, "../Debug/004.lib") 
//3��������ʱ��.exe�ļ���.dll�ļ�һ�𷢲�
*/

int  main()
{
	//cout << sum(111, 222) << endl; 

	//����dll�ĵڶ��ַ�ʽ:  Win32 API+  .dll 
	//1.����dll
	HMODULE  h=LoadLibrary(L"004.dll");
	//2.��ȡ������ַ
	typedef   int(*PSUM)(int, int); 
	//3.���ú���ָ����ú���
	//PSUM   psum=(PSUM)GetProcAddress(h, "sum");//���ú�����
	PSUM   psum = (PSUM)GetProcAddress(h, (char*)1);//������Ż�ȡ������ַ
	cout << psum(333,444) << endl; 
	//4.�ͷ�dll
	FreeLibrary(h);

	return 0;
}