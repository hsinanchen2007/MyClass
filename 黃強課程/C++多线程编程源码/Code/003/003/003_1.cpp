#include<windows.h>
#include<stdio.h>


DWORD    WINAPI   ThreadFun( LPVOID   lpThreadParameter 	);

int  main()
{
	printf("主线程开头！\n");

	//创建线程
	HANDLE  hThread = CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL);
	 
	//无限等待，除非子线程运行结束
	WaitForSingleObject(hThread, INFINITE);

	printf("主线程结尾！\n");

	return 0;
}


DWORD    WINAPI   ThreadFun(LPVOID   lpThreadParameter)
{
	int  n = 0;
	while (++n<=6)
	{
		 
		printf("第%d次打印hello!\n", n );
		Sleep(1000);

		if (n == 3)
		{
			//退出线程，退出码为666，避免使用
			ExitThread(666);
		}

	} 
	return 0;

}