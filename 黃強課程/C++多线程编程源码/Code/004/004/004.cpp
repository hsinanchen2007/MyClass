#include <process.h>
#include <stdio.h>
#include<windows.h>

void   ThreadFun(void*  param);

int main()
{
	printf("���߳̿�ʼ��\n");

   //�Ƽ�ʹ��C++�����ڿ⺯��_beginthread
  HANDLE  hThread=  (HANDLE)	_beginthread(ThreadFun, 0, "hello");

  WaitForSingleObject(hThread, INFINITE);

  printf("���߳̽�����\n");
}



void   ThreadFun(void*  param)
{

	char *p = (char *)param;

	int  n = 0;
	while (++n <= 6)
	{
		Sleep(1000);
		printf("��%d�δ�ӡ%s\n" , n,  p  );

		//����_beginthread�������̣߳�����ExitThread�˳���
		if (n == 3) _endthread();

	}

	printf("���߳̽�����\n");
}