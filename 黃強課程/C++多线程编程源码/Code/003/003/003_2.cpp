#include<windows.h>
#include<stdio.h>


DWORD    WINAPI   ThreadFun(LPVOID   lpThreadParameter);

int  main()
{
	printf("主线程开头！\n");

	//创建线程
	HANDLE  hThread = CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL);

	DWORD  code;
	GetExitCodeThread(hThread, &code);
	if (code == STILL_ACTIVE)//如果线程没有结束，返回STILL_ACTIVE
	{
		printf("子线程没有退出！\n");
	}

	//等待3秒，超时会返回
	DWORD  ret=WaitForSingleObject(hThread, 3000);
	if (ret == WAIT_TIMEOUT)
	{
		printf("WaitForSingleObject等待子线程退出超时！\n");
	}

	//强制终止线程、避免使用
	TerminateThread(hThread, 888);


	//无限等待，除非子线程运行结束
	WaitForSingleObject(hThread, INFINITE);

	 
	GetExitCodeThread(hThread, &code);
	printf("子线程退出码%d！\n",code); 



	printf("主线程结尾！\n");

	return 0;
}


DWORD    WINAPI   ThreadFun(LPVOID   lpThreadParameter)
{
	int  n = 0;
	while (++n <= 6)
	{

		printf("第%d次打印hello!\n", n);
		Sleep(1000);  

	}
	return 0;

}