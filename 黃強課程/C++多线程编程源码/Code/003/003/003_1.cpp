#include<windows.h>
#include<stdio.h>


DWORD    WINAPI   ThreadFun( LPVOID   lpThreadParameter 	);

int  main()
{
	printf("���߳̿�ͷ��\n");

	//�����߳�
	HANDLE  hThread = CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL);
	 
	//���޵ȴ����������߳����н���
	WaitForSingleObject(hThread, INFINITE);

	printf("���߳̽�β��\n");

	return 0;
}


DWORD    WINAPI   ThreadFun(LPVOID   lpThreadParameter)
{
	int  n = 0;
	while (++n<=6)
	{
		 
		printf("��%d�δ�ӡhello!\n", n );
		Sleep(1000);

		if (n == 3)
		{
			//�˳��̣߳��˳���Ϊ666������ʹ��
			ExitThread(666);
		}

	} 
	return 0;

}