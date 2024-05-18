#include <process.h>
#include <stdio.h>
#include<windows.h>

void   ThreadFun(void*  param);

int main()
{
	printf("主线程开始！\n");

   //推荐使用C++运行期库函数_beginthread
  HANDLE  hThread=  (HANDLE)	_beginthread(ThreadFun, 0, "hello");

  WaitForSingleObject(hThread, INFINITE);

  printf("主线程结束！\n");
}



void   ThreadFun(void*  param)
{

	char *p = (char *)param;

	int  n = 0;
	while (++n <= 6)
	{
		Sleep(1000);
		printf("第%d次打印%s\n" , n,  p  );

		//结束_beginthread创建的线程，别用ExitThread退出。
		if (n == 3) _endthread();

	}

	printf("子线程结束！\n");
}