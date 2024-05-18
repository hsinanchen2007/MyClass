#include <WinSock2.h>  
#include <iostream>  
using namespace std;

#pragma comment(lib,"Ws2_32.lib")  

//工作者线程有一个参数，是指向完成端口的句柄
DWORD WINAPI WorkerThread(LPVOID CompletionPortId);

//自定义结构体方便WSARecv操作所需的参数
typedef struct  _MY_WSAOVERLAPPED
{
	WSAOVERLAPPED overlap;
	WSABUF Buffer;
	DWORD NumberOfBytesRecvd;
	DWORD Flags;

	_MY_WSAOVERLAPPED()
	{
		Buffer.buf = new char[64]{ 0 };
		Buffer.len = 64;
		Flags = 0;//设置为0
		NumberOfBytesRecvd = 0;
		overlap.hEvent = NULL;//完成端口中不需要事件，置空
	}
	~_MY_WSAOVERLAPPED()
	{
		delete[]Buffer.buf;
		Buffer.buf = NULL;
		Buffer.len = 0;
	}
} MY_WSAOVERLAPPED, *PMY_WSAOVERLAPPED;


int main()
{

	// 初始化Winsock 2.2
	WSAData wsaData;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		cout << "WSAStartup  error:" << WSAGetLastError() << endl;
		return -1;
	}


	//创建完成端口
	HANDLE   completionPort= CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
	if (completionPort == NULL)
	{
		cout << "CreateIoCompletionPort  error:" << WSAGetLastError() << endl;
		return -1;
	}

	//获取CPU数量，为每个处理器创建一个线程
	SYSTEM_INFO sysInfo;
	::GetSystemInfo(&sysInfo);
	for (int i = 0; i < (int)sysInfo.dwNumberOfProcessors; i++)
	{
		//完成端口作为线程参数传入线程处理函数
		HANDLE   h = CreateThread(NULL, 0, WorkerThread, completionPort, 0, NULL);
		CloseHandle(h);
	}
	cout << "创建了" << sysInfo.dwNumberOfProcessors << "个工作线程！" << endl;


	//创建监听套接字,注意WSA_FLAG_OVERLAPPED参数,  如果使用socket()，默认就是WSA_FLAG_OVERLAPPED
	SOCKET  sListen = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (sListen == INVALID_SOCKET)
	{
		cout << "socket() Error: " << WSAGetLastError() << endl; 
		return  -1;
	}

	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8000);
	sin.sin_addr.S_un.S_addr = htonl(ADDR_ANY);
	//绑定到本机任意地址
	if (SOCKET_ERROR == bind(sListen, (sockaddr*)&sin, sizeof(sin)))
	{
		cout << "bind  error:" << WSAGetLastError() << endl;
		return -1;
	}

	//监听套接字,  Maximum queue length specifiable by listen
	if (listen(sListen, SOMAXCONN) == SOCKET_ERROR)
	{
		cout << " listen() Error:" << WSAGetLastError() << endl;
		return  -1;
	}

	while (true)
	{
		// 接受连接 ,和accept函数类似
		SOCKET  sClient = WSAAccept(sListen, NULL, NULL, NULL, NULL);

		if (sClient == INVALID_SOCKET)
		{
			cout << " accept() Error:" << WSAGetLastError() << endl;
			break;
		}

		cout << sClient << "	进入聊天室！" << endl;
		char tmp[64];
		sprintf(tmp, "欢迎%d进入聊天室！", sClient);
		send(sClient, tmp, strlen(tmp), 0);

		//将接受的套接字sClient绑定到完成端口,一样的函数，这次就不是创建了，而是绑定
		CreateIoCompletionPort((HANDLE)sClient, completionPort, (ULONG_PTR)sClient, 0);


		PMY_WSAOVERLAPPED pOver = new MY_WSAOVERLAPPED;

		//投递WSARecv请求
		int  ret = WSARecv(sClient, &pOver->Buffer, 1,
			&pOver->NumberOfBytesRecvd, &pOver->Flags, &pOver->overlap, NULL);
		if (ret == SOCKET_ERROR)
		{
			int  err = GetLastError();
			if (err == WSA_IO_PENDING)//请求投递成功
			{
			}
			else
			{
				closesocket(sClient);
				delete pOver;
				cout << "WSARecv error" << err << endl; 
			}
		}

	}

	//为了让WorkerThread退出，我们需要约定一个规则，即completionKey为空时退出
	PostQueuedCompletionStatus(completionPort, 0, NULL, NULL);


	//关闭完成端口
	CloseHandle(completionPort);

	//关闭套接字
	closesocket(sListen);

	// 最后应该做一些清除工作
	if (WSACleanup() == SOCKET_ERROR)
	{
		cout << "WSACleanup 出错！" << endl;
	}

}



DWORD WINAPI WorkerThread(LPVOID CompletionPortId)
{
	HANDLE  completionPort = (HANDLE)CompletionPortId;

	DWORD dwByteTransferred;
	SOCKET sClient=NULL;//用于获取参数指针
	PMY_WSAOVERLAPPED  pOver = NULL;

	while (true)
	{
		bool b=GetQueuedCompletionStatus(completionPort, &dwByteTransferred,
			(PULONG_PTR)&sClient, (LPOVERLAPPED*)&pOver, INFINITE);

		//检测，一般completionKey为sClient，不会为NULL，否则退出线程
		if (sClient == NULL)
		{
			return  0;
		}

		//IO操作完成，数据可直接使用
		if (b &&  dwByteTransferred > 0)
		{
			//直接在WSABUF中获取数据
			cout << sClient << "	说: " << pOver->Buffer.buf << endl;

			//清空缓存数据
			ZeroMemory(pOver->Buffer.buf, 64);

			//继续投递WSARecv请求
			//投递WSARecv请求
			int  ret = WSARecv(sClient, &pOver->Buffer, 1,
				&pOver->NumberOfBytesRecvd, &pOver->Flags, &pOver->overlap, NULL);
			if (ret == SOCKET_ERROR)
			{
				int  err = GetLastError();
				if (err == WSA_IO_PENDING)//请求投递成功
				{
				}
				else
				{
					closesocket(sClient);
					delete pOver;
					cout << "WSARecv error" << err << endl;
				}
			}

		}
		else
		{
			cout << sClient << "	离开了！" << endl;
			::closesocket(sClient);
			delete  pOver;//释放结构体 
		    //cout << "GetQueuedCompletionStatus  error: " << WSAGetLastError() << endl;
		}

	}


	return 0;
}