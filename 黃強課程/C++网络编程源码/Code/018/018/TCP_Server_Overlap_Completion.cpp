#include <WinSock2.h>  
#include <iostream>  
using namespace std;

#pragma comment(lib,"Ws2_32.lib")  


//�ҽ��飬��ҷ�װһ���ṹ�壬��������Ϊ��Ա���������
//�Զ���ṹ�巽��WSARecv��������Ĳ���
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
Flags = 0;//����Ϊ0
}
~_MY_WSAOVERLAPPED()
{
delete []Buffer.buf ;
Buffer.buf = NULL;
Buffer.len =0;
}

} MY_WSAOVERLAPPED ,*PMY_WSAOVERLAPPED;

//������̺�����IO������ɺ����
void CALLBACK completionRoutine(DWORD dwError, DWORD cbTransferred,
	LPWSAOVERLAPPED lpOverlapped, DWORD dwFlags);

int main()
{
	// ��ʼ��Winsock 2.2
	WSAData wsaData;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		cout << "WSAStartup  error:" << WSAGetLastError() << endl;
		return -1;
	}

	//���������׽���
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
	//�󶨵����������ַ
	if (SOCKET_ERROR == bind(sListen, (sockaddr*)&sin, sizeof(sin)))
	{
		cout << "bind  error:" << WSAGetLastError() << endl;
		return -0;
	}

	//�����׽���
	if (listen(sListen, 5) == SOCKET_ERROR)
	{
		cout << " listen() Error:" << WSAGetLastError() << endl;
		return  0;
	}

	while (true)
	{
		// ��������  
		SOCKET  sClient = accept(sListen, NULL, NULL); 
		if (sClient == INVALID_SOCKET)
		{
			cout << " accept() Error:" << WSAGetLastError() << endl;
			continue;
		}

		cout << sClient << "	���������ң�" << endl;
		char tmp[64];
		sprintf(tmp, "��ӭ%d���������ң�", sClient);
		send(sClient, tmp, strlen(tmp), 0);

		//������̵Ĵ����д
		PMY_WSAOVERLAPPED  pOver = new MY_WSAOVERLAPPED;
		pOver->socket = sClient;


		//Ͷ��WSARecv�����ˣ������ص�IO���������
		int  ret = WSARecv(sClient, &pOver->Buffer, 1,
			&pOver->NumberOfBytesRecvd, &pOver->Flags,&pOver->overlap,completionRoutine);

			if (ret == SOCKET_ERROR)
			{
				int err = WSAGetLastError();
				if (err == WSA_IO_PENDING)//Ͷ�ݳɹ��ˣ�IO���������Ժ����
				{

				}
				else
				{
					//��������
					cout << "WSARecv  error" << GetLastError() << endl;
					closesocket(sClient);
					delete  pOver;
				}
			}


	}



	//�ر��׽���
	closesocket(sListen);

	// ���Ӧ����һЩ�������
	if (WSACleanup() == SOCKET_ERROR)
	{
		cout << "WSACleanup ����" << endl;
	}

}


//������msdn�в鿴WSARecv�����һ������Ҳ�����������completionRoutine��ԭ��  
void CALLBACK completionRoutine(DWORD dwError, DWORD cbTransferred, 
	LPWSAOVERLAPPED lpOverlapped, DWORD dwFlags)
{
     // WSAOVERLAPPED  *pOver = lpOverlapped;
	//�������ɣ�  overlap�ǵ�һ����Ա�������׵�ַ��MY_WSAOVERLAPPED���׵�ַһ�� 
	//�����ĺô��ǿ��Է����Զ���ṹ�ĳ�Ա
	PMY_WSAOVERLAPPED  pOver = (PMY_WSAOVERLAPPED)lpOverlapped;


	//IO�Ѿ����
	if (dwError == 0 && cbTransferred > 0)
	{
		cout << pOver->socket << "		˵:" << pOver->Buffer.buf << endl;
		ZeroMemory(pOver->Buffer.buf, 64);

		//����Ͷ��WSARecv������ɲ��ϵĽ���
		int  ret = WSARecv(pOver->socket, &pOver->Buffer, 1,
			&pOver->NumberOfBytesRecvd, &pOver->Flags, &pOver->overlap, completionRoutine);

		if (ret == SOCKET_ERROR)
		{
			int err = WSAGetLastError();
			if (err == WSA_IO_PENDING)//Ͷ�ݳɹ��ˣ�IO���������Ժ����
			{

			}
			else
			{
				//��������
				cout << "WSARecv  error" << GetLastError() << endl;
				closesocket(pOver->socket);
				delete  pOver;
			}
		}

	}
	else
	{
		cout << pOver->socket << "�뿪�ˣ�" << endl;
		closesocket(pOver->socket);
		delete pOver;
	}
	
}