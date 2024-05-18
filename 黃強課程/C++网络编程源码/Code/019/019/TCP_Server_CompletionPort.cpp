#include <WinSock2.h>  
#include <iostream>  
using namespace std;

#pragma comment(lib,"Ws2_32.lib")  

//�������߳���һ����������ָ����ɶ˿ڵľ��
DWORD WINAPI WorkerThread(LPVOID CompletionPortId);

//�Զ���ṹ�巽��WSARecv��������Ĳ���
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
		Flags = 0;//����Ϊ0
		NumberOfBytesRecvd = 0;
		overlap.hEvent = NULL;//��ɶ˿��в���Ҫ�¼����ÿ�
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

	// ��ʼ��Winsock 2.2
	WSAData wsaData;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		cout << "WSAStartup  error:" << WSAGetLastError() << endl;
		return -1;
	}


	//������ɶ˿�
	HANDLE   completionPort= CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
	if (completionPort == NULL)
	{
		cout << "CreateIoCompletionPort  error:" << WSAGetLastError() << endl;
		return -1;
	}

	//��ȡCPU������Ϊÿ������������һ���߳�
	SYSTEM_INFO sysInfo;
	::GetSystemInfo(&sysInfo);
	for (int i = 0; i < (int)sysInfo.dwNumberOfProcessors; i++)
	{
		//��ɶ˿���Ϊ�̲߳��������̴߳�����
		HANDLE   h = CreateThread(NULL, 0, WorkerThread, completionPort, 0, NULL);
		CloseHandle(h);
	}
	cout << "������" << sysInfo.dwNumberOfProcessors << "�������̣߳�" << endl;


	//���������׽���,ע��WSA_FLAG_OVERLAPPED����,  ���ʹ��socket()��Ĭ�Ͼ���WSA_FLAG_OVERLAPPED
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
	//�󶨵����������ַ
	if (SOCKET_ERROR == bind(sListen, (sockaddr*)&sin, sizeof(sin)))
	{
		cout << "bind  error:" << WSAGetLastError() << endl;
		return -1;
	}

	//�����׽���,  Maximum queue length specifiable by listen
	if (listen(sListen, SOMAXCONN) == SOCKET_ERROR)
	{
		cout << " listen() Error:" << WSAGetLastError() << endl;
		return  -1;
	}

	while (true)
	{
		// �������� ,��accept��������
		SOCKET  sClient = WSAAccept(sListen, NULL, NULL, NULL, NULL);

		if (sClient == INVALID_SOCKET)
		{
			cout << " accept() Error:" << WSAGetLastError() << endl;
			break;
		}

		cout << sClient << "	���������ң�" << endl;
		char tmp[64];
		sprintf(tmp, "��ӭ%d���������ң�", sClient);
		send(sClient, tmp, strlen(tmp), 0);

		//�����ܵ��׽���sClient�󶨵���ɶ˿�,һ���ĺ�������ξͲ��Ǵ����ˣ����ǰ�
		CreateIoCompletionPort((HANDLE)sClient, completionPort, (ULONG_PTR)sClient, 0);


		PMY_WSAOVERLAPPED pOver = new MY_WSAOVERLAPPED;

		//Ͷ��WSARecv����
		int  ret = WSARecv(sClient, &pOver->Buffer, 1,
			&pOver->NumberOfBytesRecvd, &pOver->Flags, &pOver->overlap, NULL);
		if (ret == SOCKET_ERROR)
		{
			int  err = GetLastError();
			if (err == WSA_IO_PENDING)//����Ͷ�ݳɹ�
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

	//Ϊ����WorkerThread�˳���������ҪԼ��һ�����򣬼�completionKeyΪ��ʱ�˳�
	PostQueuedCompletionStatus(completionPort, 0, NULL, NULL);


	//�ر���ɶ˿�
	CloseHandle(completionPort);

	//�ر��׽���
	closesocket(sListen);

	// ���Ӧ����һЩ�������
	if (WSACleanup() == SOCKET_ERROR)
	{
		cout << "WSACleanup ����" << endl;
	}

}



DWORD WINAPI WorkerThread(LPVOID CompletionPortId)
{
	HANDLE  completionPort = (HANDLE)CompletionPortId;

	DWORD dwByteTransferred;
	SOCKET sClient=NULL;//���ڻ�ȡ����ָ��
	PMY_WSAOVERLAPPED  pOver = NULL;

	while (true)
	{
		bool b=GetQueuedCompletionStatus(completionPort, &dwByteTransferred,
			(PULONG_PTR)&sClient, (LPOVERLAPPED*)&pOver, INFINITE);

		//��⣬һ��completionKeyΪsClient������ΪNULL�������˳��߳�
		if (sClient == NULL)
		{
			return  0;
		}

		//IO������ɣ����ݿ�ֱ��ʹ��
		if (b &&  dwByteTransferred > 0)
		{
			//ֱ����WSABUF�л�ȡ����
			cout << sClient << "	˵: " << pOver->Buffer.buf << endl;

			//��ջ�������
			ZeroMemory(pOver->Buffer.buf, 64);

			//����Ͷ��WSARecv����
			//Ͷ��WSARecv����
			int  ret = WSARecv(sClient, &pOver->Buffer, 1,
				&pOver->NumberOfBytesRecvd, &pOver->Flags, &pOver->overlap, NULL);
			if (ret == SOCKET_ERROR)
			{
				int  err = GetLastError();
				if (err == WSA_IO_PENDING)//����Ͷ�ݳɹ�
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
			cout << sClient << "	�뿪�ˣ�" << endl;
			::closesocket(sClient);
			delete  pOver;//�ͷŽṹ�� 
		    //cout << "GetQueuedCompletionStatus  error: " << WSAGetLastError() << endl;
		}

	}


	return 0;
}