#include<windows.h>
#include<stdio.h>
 
 

int  main()
{
	//利用Semaphore实现程序只允许一个进程运行
	HANDLE  hSemaphore = CreateSemaphore(NULL, 3, 3, L"停车位");
	  if(GetLastError()== ERROR_ALREADY_EXISTS)
	  {
		  printf("程序已经允许，请不要开启多个进程！");
		  getchar();
		  CloseHandle(hSemaphore);
		  return  0;
      }

	  printf("程序第一次启动！"); 
	  getchar();

	return 0;
}
 