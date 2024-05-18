#include<winsock2.h>//winsock��ͷ�ļ�
#include<iostream>
using  namespace  std;

//ָ����̬���lib�ļ�
#pragma comment(lib,"ws2_32.lib")

//TCP�����
int main()
{

	//��ʼ��winsock2.2��صĶ�̬��
	WSADATA  wd;//��ȡsocket�����Ϣ
	if (WSAStartup(MAKEWORD(2, 2), &wd) != 0)//0��ʾ�ɹ�
	{
		cout << "WSAStartup  error:"<< WSAGetLastError() << endl;
		return 0;
	}

	//1.����TCP   socket , ��ʽ�׽���
	SOCKET   s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
	{
		cout << "socket  error:" << WSAGetLastError() << endl;
		return 0;
	}

	//2.��socket��һ��IP��ַ�Ͷ˿�
	sockaddr_in   addr;//������ʹ��sockaddr��������sockaddr_in
	addr.sin_port = htons(8000);//�����ֽ���
	addr.sin_addr.S_un.S_addr =inet_addr(  "127.0.0.1" );//�����ֽ���
	addr.sin_family = AF_INET; //��ַ��
	int len = sizeof(sockaddr_in);
	if (bind(s, (sockaddr *)&addr, len) == SOCKET_ERROR)
	{
		cout << "bind  error:" << WSAGetLastError() << endl;
		return 0;
	}

	//3.����, 5�������ڵȴ������Ӧ��TCP��·���ֹ��̵Ķ��г���
	if(listen(s, 5) == SOCKET_ERROR)
	{
		cout << "listen  error:" << WSAGetLastError() << endl;
		return 0;
	}
	 

	//4.���ܿͻ������󣬲��ҷ��غͿͻ���ͨѶ���׽���
	sockaddr_in   addrClient;// ����ͻ���IP��ַ�˿� 
	memset(&addrClient, 0, sizeof(sockaddr_in));
	 len = sizeof(sockaddr_in);
	SOCKET c= accept(s, (sockaddr*)&addrClient, &len);//�ɹ������׽���
	if (c == INVALID_SOCKET)
	{
		cout << "accept  error:" << WSAGetLastError() << endl;
		return 0;
	}


	//5.���ͣ�������Ϣ
	int  ret = 0;
	do
	{
		//��ͻ��˷�������,�����ü����׽���s����Ӧ����accept���ص��׽���c
		ret = send(c, "I am  Server!", strlen("I am  Server!"), 0);//��flag��0

		//���ܿͻ��˵���Ϣ
		char buf[64] = {'\0'};
		ret = recv(c, buf, 64, 0);//��flag��0
		cout << "recv" << inet_ntoa (  addrClient.sin_addr )<<":    "<< buf << endl;// inet_ntoaת��ΪIP�ַ���
	} while (ret != SOCKET_ERROR &&  ret != 0);//�Է��رգ�����0 �����󷵻�SOCKET_ERROR


	//6.�ر��׽���
	closesocket(s);


	//����winsock����
	WSACleanup();


	return   0;
}

