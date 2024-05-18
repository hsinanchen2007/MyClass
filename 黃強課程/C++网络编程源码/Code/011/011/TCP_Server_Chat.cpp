#include<winsock2.h>//winsock2��ͷ�ļ�
#include<iostream>
using  namespace std;

//����������dll��lib
#pragma comment(lib, "ws2_32.lib")

//stdcall���̴߳�����
DWORD  WINAPI  ThreadFun( 	LPVOID lpThreadParameter );

int  main()
{

	//����winsock2�Ļ���
	WSADATA  wd;
	if (WSAStartup(MAKEWORD(2, 2), &wd) != 0)
	{
		cout << "WSAStartup  error��" << GetLastError() << endl;
		return 0;
	}


	//1.������ʽ�׽���
	SOCKET  s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
	{
		cout << "socket  error��" << GetLastError() << endl;
		return 0;
	}

	//2.�󶨶˿ں�ip
	sockaddr_in   addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8000);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	int len = sizeof(sockaddr_in);
	if (bind(s, (SOCKADDR*)&addr, len) == SOCKET_ERROR)
	{
		cout << "bind  error��" << GetLastError() << endl;
		return 0;
	}


	//3.����
	listen(s, 5);


	//���߳�ѭ�����տͻ��˵����� 
	while (true)
	{ 
		sockaddr_in   addrClient;
		len = sizeof(sockaddr_in);
		//4.���ճɹ�������clientͨѶ��Socket
		SOCKET  c= accept(s, (SOCKADDR*)&addrClient, &len);
		if (c != INVALID_SOCKET)
		{ 
			//�����̣߳����Ҵ�����clientͨѶ���׽���
			HANDLE  hThread = CreateThread(NULL, 0, ThreadFun, (LPVOID)c, 0, NULL);
			CloseHandle(hThread);//�رն��̵߳�����
		} 

	}


	//6.�رռ����׽���
	closesocket(s);

	//����winsock2�Ļ���
	WSACleanup();



	return 0;
}



DWORD  WINAPI  ThreadFun(LPVOID lpThreadParameter)
{
	//5.��ͻ���ͨѶ�����ͻ��߽������� 
	SOCKET  c =(SOCKET) lpThreadParameter;

	cout << "��ӭ"<< c << "���������ң�" << endl;

	//��������
	char buf[100] = {0};
	sprintf(buf, "��ӭ%d���������ң�", c);
	send(c, buf, 100, 0);

	//ѭ�����տͻ�������
	int  ret = 0;
	do
	{
		char buf[100] = {0}	;
		ret= recv(c, buf, 100, 0);
		cout << c << "	˵:" << buf << endl;

	} while (ret!= SOCKET_ERROR &&  ret!=0);

	cout << c << "�뿪�������ң�" << endl;

	return 0;
}