#include<process.h>
#include<windows.h>
#include<stdio.h>
 

CRITICAL_SECTION  cs1;
CRITICAL_SECTION  cs2;


void   ThreadFun1(void  *param);
void   ThreadFun2(void  *param);
//演示死锁发生
int  main()
{
 
	InitializeCriticalSection(&cs1);
	InitializeCriticalSection(&cs2);

	uintptr_t  t1=  _beginthread(ThreadFun1, 0, "A");
	uintptr_t  t2 = _beginthread(ThreadFun2, 0, "B");

	//A在1区域，等着B从2区域出来
	//B在2区域，等着A从1区域出来
	//相互等待中，发生死锁

	HANDLE  hArr[] = {  ( HANDLE)t1,   (HANDLE)t2 };
	WaitForMultipleObjects(2, hArr, true, INFINITE);

	return 0;
}
 


void   ThreadFun1(void  *param)
{
	char *name = (char *)param;
	//进入1区域之后，任何人无法进1区域
	EnterCriticalSection(&cs1); 
	printf("%s进入了1区域,休息3秒\n", name);
    Sleep(3000);

	printf("%s想进入2区域\n", name);
	EnterCriticalSection(&cs2);

	LeaveCriticalSection(&cs2);

	LeaveCriticalSection(&cs1);
}


void   ThreadFun2(void  *param)
{
	char *name = (char *)param;

	//进入2区域之后，任何人无法进2区域
	EnterCriticalSection(&cs2); 
	printf("%s进入了2区域,休息3秒\n", name);
	Sleep(3000);

	printf("%s想进入1区域\n", name);
	EnterCriticalSection(&cs1);

	LeaveCriticalSection(&cs1);
	LeaveCriticalSection(&cs2);
}