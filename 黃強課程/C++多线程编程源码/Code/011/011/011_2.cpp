#include<process.h>
#include<windows.h>
#include<stdio.h>
 
int  main()
{

	// 利用事件对象实现一个程序只允许运行一个进程
	HANDLE  hEvent   = CreateEvent(NULL, FALSE, TRUE, L"事件对象");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		printf("程序已经运行了，退出！！\n");
		getchar();

		CloseHandle(hEvent);
		return 0;
	}

	printf("程序第一次运行！！\n");

	getchar();

	 


	return 0;
}
 