#include <WinSock2.h>  
#include <iostream>  
using namespace std;

#pragma comment(lib,"Ws2_32.lib")  


//ȫ�����飬������
WSAEVENT   eventArray[WSA_MAXIMUM_WAIT_EVENTS];  // �¼���������64  
SOCKET         sockArray[WSA_MAXIMUM_WAIT_EVENTS]; // �¼���Ӧ��SOCKET�������
WSAOVERLAPPED *overArray[WSA_MAXIMUM_WAIT_EVENTS]; // �¼���Ӧ���ص��ṹ����
WSABUF     bufArray[WSA_MAXIMUM_WAIT_EVENTS];//WSARecv�е�buf����ɺ�ֱ�ӿɻ�ȡ����

//�ҽ��飬��ҷ�װһ���ṹ�壬��������Ϊ��Ա���������
/*
//�Զ���ṹ�巽��WSARecv��������Ĳ���
typedef struct  _MY_WSAOVERLAPPED
{
WSAOVERLAPPED overlap;
WSABUF Buffer;
DWORD NumberOfBytesRecvd;
DWORD Flags;

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


WSAEVENT eventArray[WSA_MAXIMUM_WAIT_EVENTS];  // �¼���������64
SOCKET sockArray[WSA_MAXIMUM_WAIT_EVENTS]; // �¼���Ӧ��SOCKET�������
PMY_WSAOVERLAPPED   overlappedArray[WSA_MAXIMUM_WAIT_EVENTS]; // �ص��ṹָ������
int  N = 0;//�¼�����ĸ���


*/



int  N = 0;//��¼�����¼��ĸ���


DWORD WINAPI  ThreadProc(LPVOID lpParameter);

int main()
{
	// ��ʼ��Winsock 2.2
	WSAData wsaData;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		cout << "WSAStartup  error:" << WSAGetLastError() << endl;
		return -1;
	}

	//���������׽���,socket������Ĭ������ WSA_FLAG_OVERLAPPED ��־��WSASocket()��Ҫ�ֶ����ñ�־
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
		return 0;
	}

	//�����׽���
	if (listen(sListen, 5) == SOCKET_ERROR)
	{
		cout << " listen() Error:" << WSAGetLastError() << endl;
		return  0;
	}


	// �����̣߳�������¼��źŵĵ���
	HANDLE hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
	CloseHandle(hThread);//�رն��̵߳����� 


	while (true)
	{
		// ���ܿͻ�����������  
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

		//��ʼ�����¼����ص�io����

		//�����¼�����
		WSAEVENT  event = WSACreateEvent();
		 //�����ص��ṹ
		WSAOVERLAPPED *pOver = new WSAOVERLAPPED;
		pOver->hEvent = event;

	
		eventArray[N] = event;
		overArray[N] = pOver;
		sockArray[N] = sClient;



		//Ͷ��WSARecv��������տͻ�������
		WSABUF buf;
		buf.buf = new char[100];
		ZeroMemory(buf.buf, 100);
		buf.len = 100;

		bufArray[N] = buf;

		++N;


		DWORD numberOfBytesRecvd = 0;
		DWORD  flags = 0;
		int  ret= WSARecv(sClient, &buf, 1, &numberOfBytesRecvd, &flags, pOver, NULL);
		if (ret == SOCKET_ERROR)//�첽��������������SOCKET_ERROR�����Ҵ�����WSA_IO_PENDING
		{
			int  err = WSAGetLastError();
			if (err == WSA_IO_PENDING)//֤��Ͷ�ݵ�����ɹ���IO�������ں����ʱ�����
			{

			}
			else
			{
				cout << "WSARecv ʧ�ܣ�" << endl;
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




//7ʵ���̺߳�����������ȫ�ֵģ�Ҳ��������ľ�̬������
DWORD WINAPI  ThreadProc(LPVOID lpParameter)
{
	 //����Ƿ��¼����ź�
	while (TRUE)
	{
		//1���ӳ�ʱ�ͷ��أ������WSA_INFINITE,������event��������ʱ������ĺ����������������ἰʱ��⵽
		int  ret= WSAWaitForMultipleEvents(N, eventArray, false, 1000, false);
		if (ret == WSA_WAIT_FAILED ||  ret== WSA_WAIT_TIMEOUT)
		{
			continue;
		}

		//�����¼������������е��±�
		int  index = ret - WSA_WAIT_EVENT_0;

		//�˿��¼�Ϊ���źţ���ҪWSAReset���¼�����Ϊ���źţ��Ա��´�ʹ��
		WSAResetEvent(eventArray[index]);

		WSAOVERLAPPED *pOver = overArray[index];

		//	�����ص�������ʵ�ʽ���(����)���ֽ���
		DWORD lpcbTransfer = 0;
		DWORD lpdwFlags = 0;
		//����ص�IO�����Ƿ����,  
		int ret2 = WSAGetOverlappedResult(sockArray[index], pOver, &lpcbTransfer, true, &lpdwFlags);

		if (ret2 && lpcbTransfer > 0)
		{
			//ֱ����WSABUF�л�ȡ����
			cout << sockArray[index] << "	˵: " <<  bufArray[index].buf << endl;

			//��ջ�������
			ZeroMemory(bufArray[index].buf, 100);

			DWORD numberOfBytesRecvd = 0;
			DWORD  flags = 0;
			// ������һ���첽����  
			WSARecv(sockArray[index],
				&bufArray[index],
				1,
				&numberOfBytesRecvd, 
				&flags,
				pOver,
				NULL);
		}
		else
		{
			cout << sockArray[index] << "�뿪�ˣ�"<<endl;
			closesocket(sockArray[index]);
			WSACloseEvent(eventArray[index]);
			delete overArray[index];
			delete  bufArray[index].buf;

			//��Ҫ�������indexԪ��ɾ�����Ѻ����Ԫ��ǰ�ƶ�
			while (index < N - 1)
			{
				sockArray[index] = sockArray[index + 1];
				overArray[index] = overArray[index+1];
				eventArray[index] = eventArray[index+1];
				bufArray[index] = bufArray[index+1];
				++index;
			}

			--N;

		}



	}


	return 0;
}