#include<windows.h>
#include<stdio.h>

 
DWORD  WINAPI ThreadFun1(LPVOID  param);
DWORD  WINAPI ThreadFun2(LPVOID  param);

//动态TLS的索引
DWORD  tlsIndex = 0;
 

int  main()
{

	tlsIndex = TlsAlloc();
	if (tlsIndex == TLS_OUT_OF_INDEXES)
	{
		printf("分配TLS索引失败！");
		return 0;
	} 

  //在主线程设置一个值
	TlsSetValue(tlsIndex, "cpp");
	char  *p = (char *)TlsGetValue(tlsIndex);
	printf("主线程打印：%s \n", p);

	HANDLE  hThread1 = CreateThread(NULL, 0, ThreadFun1, NULL, 0, NULL);
	HANDLE  hThread2 = CreateThread(NULL, 0, ThreadFun2, NULL, 0, NULL);

	HANDLE  hArr[] = { hThread1,hThread2 };
	WaitForMultipleObjects(2, hArr, TRUE, INFINITE);

	//释放位置
	TlsFree(tlsIndex);

	return 0;
}


DWORD  WINAPI ThreadFun1(LPVOID  param)
{

   TlsSetValue(tlsIndex, "hello");  
	while (TRUE)
	{
		//每个线程同一个索引位置的值只属于自己，和其他线程没关系
		char  *p = (char *)TlsGetValue(tlsIndex);
		printf("线程A打印：%s \n", p);
		Sleep(1000);
	}

}
DWORD  WINAPI ThreadFun2(LPVOID  param)
{
	TlsSetValue(tlsIndex, "world");

	while (TRUE)
	{
		//每个线程同一个索引位置的值只属于自己，和其他线程没关系
		char  *p = (char *)TlsGetValue(tlsIndex);
		printf("线程B打印：%s \n", p);
		Sleep(1000);
	}
}