#include<windows.h>
#include<stdio.h>


DWORD    WINAPI   ThreadFun(LPVOID   lpThreadParameter);

int  main()
{
	printf("���߳̿�ʼ��\n");

	//�����߳�
	HANDLE  hThread1 = CreateThread(NULL, 0, ThreadFun,(LPVOID) "A", 0, NULL);
	HANDLE  hThread2 = CreateThread(NULL, 0, ThreadFun, (LPVOID) "B", 0, NULL);
	HANDLE  hThread3 = CreateThread(NULL, 0, ThreadFun, (LPVOID) "C", 0, NULL);

	HANDLE  handleArr[] = { hThread1 ,hThread2 ,hThread3};

 
	//���޵ȴ������߳̽���
	//DWORD  ret =  WaitForMultipleObjects(3,handleArr,true,INFINITE) ;
	// printf("ret== %d\n" ,ret== WAIT_OBJECT_0);

	//�ȴ�����һ���߳̽����ͷ�����������
	//DWORD  ret = WaitForMultipleObjects(3, handleArr, false, INFINITE);
	//printf("ret== %d\n", ret);

	//���õȴ���ʱʱ��1��
	DWORD  ret = WaitForMultipleObjects(3, handleArr, false, 1000);
	printf("ret== %d\n", ret== WAIT_TIMEOUT);
	   
	printf("���߳̽�β��\n");

	return 0;
}


DWORD    WINAPI   ThreadFun(LPVOID   lpThreadParameter)
{

	char  * name = (char *)lpThreadParameter;
	
	if (strcmp(name, "A") == 0)
	{
		Sleep(10000);
	}
	else if (strcmp(name, "C") == 0)
	{
		Sleep(3000);
	}
	else
	{
		Sleep(8000);
	}

	printf("%s�߳̽���!\n", name);
	 
	return 0;

}