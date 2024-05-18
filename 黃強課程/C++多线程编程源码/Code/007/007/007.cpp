#include<process.h>
#include<windows.h>
#include<stdio.h>


void    __cdecl   SellThread1(void* param);
void    __cdecl   SellThread2(void* param);

//100张票
int   tickets = 100;

//1. 临界区结构
CRITICAL_SECTION    Section;


int  main()
{
	//2.初始化临界区
	InitializeCriticalSection(&Section); 


	printf("开始卖票了！\n");

	//创建两个售票窗口 
	uintptr_t   t1 = _beginthread(SellThread1, 0, "售口窗口A");
	uintptr_t   t2 = _beginthread(SellThread2, 0, "售口窗口B");

	//无限等待两个线程全部执行完毕
	HANDLE  hArr[] = { (HANDLE)t1,  (HANDLE)t2 };
	WaitForMultipleObjects(2, hArr, true, INFINITE);
	 
	printf("卖票结束！\n");

	//5.删除临界区资源
	DeleteCriticalSection(&Section);

	return 0;
}


void    __cdecl   SellThread1(void* param)
{
	char  *name = (char *)param;
	  
	while (tickets>0)
	{
		//3.进入临界区，禁止其他线程访问
		EnterCriticalSection(&Section);
		if (tickets > 0)
		{
			Sleep(10);
			//CPU恰好执行到这里，这个时候线程时间片到了，并且此时还剩最后一张票
			printf("%s卖出第%d张票！\n", name, tickets--);
		}
		//4.离开临界区
		LeaveCriticalSection(&Section);
	}


}
void    __cdecl   SellThread2(void* param)
{
	char  *name = (char *)param;

	 
	while (tickets > 0)
	{
		//进入临界区，禁止其他线程访问
		//EnterCriticalSection(&Section);

		//尝试进入临界区，不会阻塞线程
		if (TryEnterCriticalSection(&Section))
		{
			if (tickets > 0)
			{
				Sleep(10);
				//CPU恰好执行到这里，这个时候线程时间片到了，并且此时还剩最后一张票
				printf("%s卖出第%d张票！\n", name, tickets--);
			}
			//离开临界区
			LeaveCriticalSection(&Section);
		}
	}


}