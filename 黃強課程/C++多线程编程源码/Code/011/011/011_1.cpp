#include<process.h>
#include<windows.h>
#include<stdio.h>


void    __cdecl   SellThread1(void* param);
void    __cdecl   SellThread2(void* param);

//100张票
int   tickets = 100;


HANDLE  hEvent = INVALID_HANDLE_VALUE;

int  main()
{

	//创建事件，此刻为有信号状态
	//自动重置信号状态,  初始化为有信号状态，线程可以直接获取
	hEvent = CreateEvent(NULL, FALSE, TRUE ,L"事件对象");

	Sleep(1000);
	//主线程休眠3秒之后，将信号量设置为无信号状态
	//ResetEvent(hEvent);

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
		//如果事件对象为有信号状态（没有线程拥有它），则线程可以获取它后继续执行
		//自动重置的事件对象,调用了WaitForSingleObject函数之后，自动重置为无信号
		WaitForSingleObject(hEvent, INFINITE);
		if (tickets > 0)
		{
			Sleep(10);
			//CPU恰好执行到这里，这个时候线程时间片到了，并且此时还剩最后一张票
			printf("%s卖出第%d张票！\n", name, tickets--);
		}
		//SetEvent让事件对象变成有信号状态
		SetEvent(hEvent);

	}


}
void    __cdecl   SellThread2(void* param)
{
	char  *name = (char *)param;


	while (tickets > 0)
	{
		//如果事件对象为有信号状态（没有线程拥有它），则线程可以获取它后继续执行
		//自动重置的事件对象,调用了WaitForSingleObject函数之后，自动重置为无信号
		WaitForSingleObject(hEvent, INFINITE);
		if (tickets > 0)
		{
			Sleep(10);
			//CPU恰好执行到这里，这个时候线程时间片到了，并且此时还剩最后一张票
			printf("%s卖出第%d张票！\n", name, tickets--);
		}
		//SetEvent让事件对象变成有信号状态
		SetEvent(hEvent);
	}


}