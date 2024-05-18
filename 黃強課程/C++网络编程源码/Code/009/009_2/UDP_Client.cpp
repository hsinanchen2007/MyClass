#include<winsock2.h>
#include<iostream>
using namespace  std;

//��Ӷ�̬���lib
#pragma comment(lib, "ws2_32.lib")

//UDP�ͻ���
int  main()
{

	//��ʼ��winsock2����
	WSADATA  wd;
	if (WSAStartup(MAKEWORD(2, 2), &wd) != 0)
	{
		cout << "WSAStartup error:" << GetLastError() << endl;
		return 0;
	}


	//1.��Ȼ�Ǵ������ݱ�socket 
	SOCKET  s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if ( s== INVALID_SOCKET)
	{
		cout << "socket error:" << GetLastError() << endl;
		return 0;
	}

	//�������˵ĵ�ַ
	sockaddr_in  addr;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(8000);//�����ֽ���
	addr.sin_family = AF_INET;
	int len = sizeof(sockaddr_in);

	int  ret = 0;
	do 
	{
		//2.����sendto���ͺ� recvfrom���� 
		ret = sendto(s, "I am Client!", strlen("I am Client!"), 0, (SOCKADDR*)&addr, len);

		 char buf[100] = {0};
		 ret= recvfrom(s, buf, 100, 0, NULL, NULL);//����Ҫ����˵�ַ
		 cout << "recvfrom  " << ret << "  :" << buf << endl;

		 Sleep(1000);

	} 
	while (ret!= SOCKET_ERROR && ret!=0);


	//3.�ر��׽���
	closesocket(s);


	//����winsock2����
	WSACleanup();


	return 0;
}