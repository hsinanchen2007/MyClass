#include<process.h>
#include<windows.h>
#include<stdio.h>

 
 
int  main()
{

	//创建互斥体实现一个程序只允许允许一个实例（进程）
	HANDLE  hMutex   = CreateMutex(NULL, FALSE, L"售票互斥体");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		printf("程序已经运行了，退出！\n");
		getchar();

		CloseHandle(hMutex);
		return  0;
	}

	printf("第一次运行程序！\n");
	getchar();
 
	return 0;
}


 