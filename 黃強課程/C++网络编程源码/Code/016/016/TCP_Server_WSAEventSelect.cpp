#include <WinSock2.h>  
#include <iostream>  
using namespace std;

#pragma comment(lib,"Ws2_32.lib")  


int main()
{
	// ��ʼ��Winsock 2.2
	WSAData wsaData;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		cout << "WSAStartup  error:" << WSAGetLastError() << endl;
		return -1;
	}

	//1���������׽���
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
	//2�󶨵����������ַ���˿�
	if (SOCKET_ERROR == bind(sListen, (sockaddr*)&sin, sizeof(sin)))
	{
		cout << "bind  error:" << WSAGetLastError() << endl;
		return -1;
	}

	//3�����׽���
	if (listen(sListen, 5) == SOCKET_ERROR)
	{
		cout << " listen() Error:" << WSAGetLastError() << endl;
		return  0;
	}


	WSAEVENT eventArray[WSA_MAXIMUM_WAIT_EVENTS];  // �¼���������64  
	SOCKET      sockArray[WSA_MAXIMUM_WAIT_EVENTS]; // �¼���Ӧ��SOCKET�������  
	int  N = 0;//�¼�����ĸ�������ʼ��Ϊ0


	//������һ���¼��������ڼ���socket ������ע���¼�
	WSAEVENT event = ::WSACreateEvent();
	::WSAEventSelect(sListen, event, FD_ACCEPT | FD_CLOSE);
	sockArray[N] = sListen;
	eventArray[N++] = event;//���˵�һ���¼�����


	while (true)
	{
		//�ȴ��¼���falseֻҪ��һ�����󱻴����ͷ��أ� ���޵ȴ�
		int   ret = ::WSAWaitForMultipleEvents(N, eventArray, false, WSA_INFINITE, false);
		if (ret == WSA_WAIT_FAILED) 
		{
			cout << "WSAWaitForMultipleEvents  error��" << WSAGetLastError() << endl;
			continue;
		}

		//���������е��±�Ϊ��  ������ֵ  -  WSA_WAIT_EVENT_0 �� 
		int  index = ret - WSA_WAIT_EVENT_0;

	
		SOCKET sock = sockArray[index];//��Ӧ��ϵ��ͨ��������ȡ��Ӧ��socket

		WSANETWORKEVENTS  netEvents;//���ط�����ʱ��
		//��ⷢ�����¼�
		::WSAEnumNetworkEvents(sock, eventArray[index], &netEvents); 
		//���ܵ��ͻ��˵������¼�
		if (netEvents.lNetworkEvents & FD_ACCEPT)
		{
			//�޴���
			if (netEvents.iErrorCode[FD_ACCEPT_BIT] == 0)
			{
				if (N >= WSA_MAXIMUM_WAIT_EVENTS)
				{
					cout << "�¼���������������" << endl;
					continue;
				}

				SOCKET client = ::accept(sock, NULL, NULL);
				if (client != INVALID_SOCKET)
				{
					cout << client << "	���������ң�" << endl;
					char tmp[64];
					sprintf(tmp, "��ӭ%d���������ң�", client);
					send(client, tmp, strlen(tmp), 0);

					//����һ���ͻ����׽��֣���ע����¼�
					WSAEVENT e = ::WSACreateEvent();
					::WSAEventSelect(client, e, FD_READ | FD_WRITE | FD_CLOSE);
					sockArray[N] = client;
					eventArray[N++] = e;//�ŵ��¼�������
				}
			}
		}
		//���¼�
		else if (netEvents.lNetworkEvents & FD_READ)
		{
			if (netEvents.iErrorCode[FD_READ_BIT] == 0)
			{
				char buf[64] = {0}; 
				int ret = recv(sock, buf, 64, 0);
				if (ret > 0)
				{
					cout << sock << "	˵: " << buf << endl;
				}
			}
		}
		else if (netEvents.lNetworkEvents & FD_CLOSE)
		{
			//�ر��¼�����
			::WSACloseEvent(eventArray[index]);
			::closesocket(sock);
			cout << sock << "	�뿪�ˣ�" << endl;

			//��������Ԫ�أ�ɾ���رյ��׽���
			for (int j = index; j<N - 1; j++) {
				eventArray[j] = eventArray[j + 1];
				sockArray[j] = sockArray[j + 1];
			}
			--N;//��������һ
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
