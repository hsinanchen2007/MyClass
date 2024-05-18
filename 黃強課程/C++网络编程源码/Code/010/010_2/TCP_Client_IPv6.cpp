#include<winsock2.h>//winsock��ͷ�ļ�
#include<ws2tcpip.h>//sockaddr_in6��ͷ�ļ�
#include<iostream>
using  namespace  std;

//ָ����̬���lib�ļ�
#pragma comment(lib,"ws2_32.lib")


//TCP�ͻ���
int main()
{

	//��ʼ��winsock2.2��صĶ�̬��
	WSADATA  wd;//��ȡsocket�����Ϣ
	if (WSAStartup(MAKEWORD(2, 2), &wd) != 0)//0��ʾ�ɹ�
	{
		cout << "WSAStartup  error:" << WSAGetLastError() << endl;
		return 0;
	}


	//1.����TCP   socket , ��ʽ�׽���, AF_INET��ΪAF_INET6
	SOCKET   s = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
	{
		cout << "socket  error:" << WSAGetLastError() << endl;
		return 0;
	}

	//2.���ӷ����
	sockaddr_in6   addr;//������ʹ��sockaddr��������sockaddr_in
	memset(&addr, 0, sizeof(sockaddr_in6)); //�ص㣬�����10049����
	addr.sin6_port = htons(8000);//�����ֽ��� 

	 //addr.sin6_addr = inet_addr("127.0.0.1");//��ָ����ַ�� ipv4
	inet_pton(AF_INET6, "fe80::ce6:3cc:f93a:4203%5", &addr.sin6_addr);//��ָ����ַ�� ipv6
	 
	addr.sin6_family = AF_INET6; //��ַ��
	int len = sizeof(sockaddr_in6);//�ṹ��С�ı�sizeof(sockaddr_in6)

	if (connect(s, (sockaddr*)&addr, len) == SOCKET_ERROR)
	{
		cout << "connect  error:" << WSAGetLastError() << endl;
		return 0;
	}

	//3.���ܷ�����Ϣ
	int  ret = 0;
	do
	{
		//���ܿͻ��˵���Ϣ
		char buf[64] = { '\0' };
		ret = recv(s, buf, 64, 0);//��flag��0

		  // inet_ntoa(addrClient.sin_addr) ��Ϊ  inet_ntop 
		char ipbuf[100] = { 0 };
		inet_ntop(AF_INET6, (LPVOID)&addr.sin6_addr, ipbuf, 100);


		cout << "recv	" << ipbuf << ":    " << buf << endl;// inet_ntoaת��ΪIP�ַ���

																			 //����
		ret = send(s, "I am Client!", strlen("I am Client!"), 0);

		Sleep(1000);
	} while (ret != SOCKET_ERROR &&  ret != 0);


	//4.�ر��׽���
	closesocket(s);

	//����winsock����
	WSACleanup();


	return   0;
}
