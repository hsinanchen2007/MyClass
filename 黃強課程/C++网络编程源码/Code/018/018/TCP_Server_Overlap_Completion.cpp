#include <WinSock2.h>  
#include <iostream>  
using namespace std;

#pragma comment(lib,"Ws2_32.lib")  


//我建议，大家封装一个结构体，把他们作为成员，方便管理
//自定义结构体方便WSARecv操作所需的参数
typedef struct  _MY_WSAOVERLAPPED
{
WSAOVERLAPPED overlap;
WSABUF Buffer;
DWORD NumberOfBytesRecvd;
DWORD Flags;
SOCKET  socket;

_MY_WSAOVERLAPPED()
{
Buffer.buf = new char[64]{0};
Buffer.len = 64;
Flags = 0;//设置为0
}
~_MY_WSAOVERLAPPED()
{
delete []Buffer.buf ;
Buffer.buf = NULL;
Buffer.len =0;
}

} MY_WSAOVERLAPPED ,*PMY_WSAOVERLAPPED;

//完成例程函数，IO操作完成后调用
void CALLBACK completionRoutine(DWORD dwError, DWORD cbTransferred,
	LPWSAOVERLAPPED lpOverlapped, DWORD dwFlags);

int main()
{
	// 初始化Winsock 2.2
	WSAData wsaData;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		cout << "WSAStartup  error:" << WSAGetLastError() << endl;
		return -1;
	}

	//创建监听套接字
	SOCKET  sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sListen == INVALID_SOCKET)
	{
		cout << "socket() Error: " << WSAGetLastError() << endl; 	
		return  0;
	}

	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8000);
	sin.sin_addr.S_un.S_addr = htonl(ADDR_ANY);
	//绑定到本机任意地址
	if (SOCKET_ERROR == bind(sListen, (sockaddr*)&sin, sizeof(sin)))
	{
		cout << "bind  error:" << WSAGetLastError() << endl;
		return -0;
	}

	//监听套接字
	if (listen(sListen, 5) == SOCKET_ERROR)
	{
		cout << " listen() Error:" << WSAGetLastError() << endl;
		return  0;
	}

	while (true)
	{
		// 接受连接  
		SOCKET  sClient = accept(sListen, NULL, NULL); 
		if (sClient == INVALID_SOCKET)
		{
			cout << " accept() Error:" << WSAGetLastError() << endl;
			continue;
		}

		cout << sClient << "	进入聊天室！" << endl;
		char tmp[64];
		sprintf(tmp, "欢迎%d进入聊天室！", sClient);
		send(sClient, tmp, strlen(tmp), 0);

		//完成例程的代码编写
		PMY_WSAOVERLAPPED  pOver = new MY_WSAOVERLAPPED;
		pOver->socket = sClient;


		//投递WSARecv请求了，告诉重叠IO想接收数据
		int  ret = WSARecv(sClient, &pOver->Buffer, 1,
			&pOver->NumberOfBytesRecvd, &pOver->Flags,&pOver->overlap,completionRoutine);

			if (ret == SOCKET_ERROR)
			{
				int err = WSAGetLastError();
				if (err == WSA_IO_PENDING)//投递成功了，IO操作将在稍后完成
				{

				}
				else
				{
					//做清理工作
					cout << "WSARecv  error" << GetLastError() << endl;
					closesocket(sClient);
					delete  pOver;
				}
			}


	}



	//关闭套接字
	closesocket(sListen);

	// 最后应该做一些清除工作
	if (WSACleanup() == SOCKET_ERROR)
	{
		cout << "WSACleanup 出错！" << endl;
	}

}


//可以在msdn中查看WSARecv中最后一个函数也就是完成例程completionRoutine的原型  
void CALLBACK completionRoutine(DWORD dwError, DWORD cbTransferred, 
	LPWSAOVERLAPPED lpOverlapped, DWORD dwFlags)
{
     // WSAOVERLAPPED  *pOver = lpOverlapped;
	//操作技巧：  overlap是第一个成员，所以首地址与MY_WSAOVERLAPPED的首地址一样 
	//这样的好处是可以访问自定义结构的成员
	PMY_WSAOVERLAPPED  pOver = (PMY_WSAOVERLAPPED)lpOverlapped;


	//IO已经完成
	if (dwError == 0 && cbTransferred > 0)
	{
		cout << pOver->socket << "		说:" << pOver->Buffer.buf << endl;
		ZeroMemory(pOver->Buffer.buf, 64);

		//继续投递WSARecv请求，完成不断的接收
		int  ret = WSARecv(pOver->socket, &pOver->Buffer, 1,
			&pOver->NumberOfBytesRecvd, &pOver->Flags, &pOver->overlap, completionRoutine);

		if (ret == SOCKET_ERROR)
		{
			int err = WSAGetLastError();
			if (err == WSA_IO_PENDING)//投递成功了，IO操作将在稍后完成
			{

			}
			else
			{
				//做清理工作
				cout << "WSARecv  error" << GetLastError() << endl;
				closesocket(pOver->socket);
				delete  pOver;
			}
		}

	}
	else
	{
		cout << pOver->socket << "离开了！" << endl;
		closesocket(pOver->socket);
		delete pOver;
	}
	
}