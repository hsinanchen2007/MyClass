#include<process.h>
#include<windows.h>
#include<stdio.h>


void    __cdecl   SellThread1(void* param);
void    __cdecl   SellThread2(void* param);

//100张票
int   tickets = 100;
 

HANDLE  hMutex = INVALID_HANDLE_VALUE;

int  main()
{ 

	//创建互斥体，此刻为有信号状态
	hMutex = CreateMutex(NULL, FALSE, L"售票互斥体");
	 

	printf("开始卖票了！\n");

	//创建两个售票窗口 
	uintptr_t   t1 = _beginthread(SellThread1, 0, "售口窗口A");
	uintptr_t   t2 = _beginthread(SellThread2, 0, "售口窗口B");

	//无限等待两个线程全部执行完毕
	HANDLE  hArr[] = { (HANDLE)t1,  (HANDLE)t2 };
	WaitForMultipleObjects(2, hArr, true, INFINITE);

	printf("卖票结束！\n");
	 

	return 0;
}


void    __cdecl   SellThread1(void* param)
{
	char  *name = (char *)param;

	while (tickets>0)
	{
		//如果这个互斥体为有信号状态（没有线程拥有它），则线程获取它后继续执行
		WaitForSingleObject(hMutex, INFINITE);
		 if (tickets > 0)
		{
			Sleep(10);
			//CPU恰好执行到这里，这个时候线程时间片到了，并且此时还剩最后一张票
			printf("%s卖出第%d张票！\n", name, tickets--);
		} 
		 //释放对互斥体的拥有权，它变成有信号状态
		 ReleaseMutex(hMutex);

	}


}
void    __cdecl   SellThread2(void* param)
{
	char  *name = (char *)param;


	while (tickets > 0)
	{
		//如果这个互斥体为有信号状态（没有线程拥有它），则线程获取它后继续执行
		WaitForSingleObject(hMutex, INFINITE);
        	if (tickets > 0)
			{
				Sleep(10);
				//CPU恰好执行到这里，这个时候线程时间片到了，并且此时还剩最后一张票
				printf("%s卖出第%d张票！\n", name, tickets--);
			}
		 //释放对互斥体的拥有权，它变成有信号状态
		 ReleaseMutex(hMutex);
	}


}