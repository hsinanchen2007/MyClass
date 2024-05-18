#include<windows.h>
#include<stdio.h>

DWORD  WINAPI  ThreadFun1(LPVOID  param);
DWORD  WINAPI  ThreadFun2(LPVOID  param);

//自定义消息(必须是自定义消息以上的数值)
#define  MY_MSG     WM_USER+1


int  main()
{

	DWORD  threadID = 0;

	//获取第一个线程的ID，方便第二个线程给第一个线程发消息
	HANDLE  hThread1 = CreateThread(NULL, 0, ThreadFun1, NULL, 0, &threadID);
	HANDLE  hThread2 = CreateThread(NULL, 0, ThreadFun2,  (LPVOID)threadID, 0, NULL);

	HANDLE  hArr[] = {hThread1, hThread2 };
	WaitForMultipleObjects(2, hArr, TRUE, INFINITE);


	return 0;
}


DWORD  WINAPI  ThreadFun1(LPVOID  param)
{
	//接收第二个线程发来的消息
	MSG   msg;
	 

	/*while (GetMessage(&msg, NULL, 0, 0))//如果有消息，继续，否则阻塞
	{
		switch( msg.message )
		{
		    case  MY_MSG: 
				printf("收到消息: %d\n",(int) msg.wParam);
			 break;
		}
	}  
	//因为WM_QUIT消息会让GetMessage返回false从而退出循环
	printf("收到WM_QUIT消息,退出！\n");
	*/


	//PeekMessage的用法
	while (TRUE)
	{
		//马上就返回，不阻塞线程
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			switch (msg.message)
			{
			case  MY_MSG:
				printf("收到消息: %d\n", (int)msg.wParam);
				break;
			case  WM_QUIT:
				printf("收到WM_QUIT消息,退出！\n");
				return 0;
				break;
			}
		}
	}
	 



	return 0;
}


DWORD  WINAPI  ThreadFun2(LPVOID  param)
{
	//给第一个线程发消息
	DWORD  threadId = (DWORD)param;
	int  N = 1;
	while (TRUE)
	{
		if (N <= 10)
		{ 
			PostThreadMessage(threadId, MY_MSG, (WPARAM)N++, NULL);
		}
		else
		{
			//让第一个线程退出消息循环
			PostThreadMessage(threadId, WM_QUIT, NULL, NULL);
			break;
		}


		Sleep(1000);
	}

	return 0;
}