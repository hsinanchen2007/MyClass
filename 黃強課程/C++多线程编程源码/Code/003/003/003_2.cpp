#include<windows.h>
#include<stdio.h>


DWORD    WINAPI   ThreadFun(LPVOID   lpThreadParameter);

int  main()
{
	printf("���߳̿�ͷ��\n");

	//�����߳�
	HANDLE  hThread = CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL);

	DWORD  code;
	GetExitCodeThread(hThread, &code);
	if (code == STILL_ACTIVE)//����߳�û�н���������STILL_ACTIVE
	{
		printf("���߳�û���˳���\n");
	}

	//�ȴ�3�룬��ʱ�᷵��
	DWORD  ret=WaitForSingleObject(hThread, 3000);
	if (ret == WAIT_TIMEOUT)
	{
		printf("WaitForSingleObject�ȴ����߳��˳���ʱ��\n");
	}

	//ǿ����ֹ�̡߳�����ʹ��
	TerminateThread(hThread, 888);


	//���޵ȴ����������߳����н���
	WaitForSingleObject(hThread, INFINITE);

	 
	GetExitCodeThread(hThread, &code);
	printf("���߳��˳���%d��\n",code); 



	printf("���߳̽�β��\n");

	return 0;
}


DWORD    WINAPI   ThreadFun(LPVOID   lpThreadParameter)
{
	int  n = 0;
	while (++n <= 6)
	{

		printf("��%d�δ�ӡhello!\n", n);
		Sleep(1000);  

	}
	return 0;

}