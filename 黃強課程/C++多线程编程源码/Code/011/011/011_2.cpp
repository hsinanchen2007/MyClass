#include<process.h>
#include<windows.h>
#include<stdio.h>
 
int  main()
{

	// �����¼�����ʵ��һ������ֻ��������һ������
	HANDLE  hEvent   = CreateEvent(NULL, FALSE, TRUE, L"�¼�����");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		printf("�����Ѿ������ˣ��˳�����\n");
		getchar();

		CloseHandle(hEvent);
		return 0;
	}

	printf("�����һ�����У���\n");

	getchar();

	 


	return 0;
}
 