#include<process.h>
#include<windows.h>
#include<stdio.h>

 
 
int  main()
{

	//����������ʵ��һ������ֻ��������һ��ʵ�������̣�
	HANDLE  hMutex   = CreateMutex(NULL, FALSE, L"��Ʊ������");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		printf("�����Ѿ������ˣ��˳���\n");
		getchar();

		CloseHandle(hMutex);
		return  0;
	}

	printf("��һ�����г���\n");
	getchar();
 
	return 0;
}


 