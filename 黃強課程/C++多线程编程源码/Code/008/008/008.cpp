#include<process.h>
#include<windows.h>
#include<stdio.h>
 

CRITICAL_SECTION  cs1;
CRITICAL_SECTION  cs2;


void   ThreadFun1(void  *param);
void   ThreadFun2(void  *param);
//��ʾ��������
int  main()
{
 
	InitializeCriticalSection(&cs1);
	InitializeCriticalSection(&cs2);

	uintptr_t  t1=  _beginthread(ThreadFun1, 0, "A");
	uintptr_t  t2 = _beginthread(ThreadFun2, 0, "B");

	//A��1���򣬵���B��2�������
	//B��2���򣬵���A��1�������
	//�໥�ȴ��У���������

	HANDLE  hArr[] = {  ( HANDLE)t1,   (HANDLE)t2 };
	WaitForMultipleObjects(2, hArr, true, INFINITE);

	return 0;
}
 


void   ThreadFun1(void  *param)
{
	char *name = (char *)param;
	//����1����֮���κ����޷���1����
	EnterCriticalSection(&cs1); 
	printf("%s������1����,��Ϣ3��\n", name);
    Sleep(3000);

	printf("%s�����2����\n", name);
	EnterCriticalSection(&cs2);

	LeaveCriticalSection(&cs2);

	LeaveCriticalSection(&cs1);
}


void   ThreadFun2(void  *param)
{
	char *name = (char *)param;

	//����2����֮���κ����޷���2����
	EnterCriticalSection(&cs2); 
	printf("%s������2����,��Ϣ3��\n", name);
	Sleep(3000);

	printf("%s�����1����\n", name);
	EnterCriticalSection(&cs1);

	LeaveCriticalSection(&cs1);
	LeaveCriticalSection(&cs2);
}