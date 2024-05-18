#include<winsock2.h>
#include<iostream>
using namespace  std;

//��Ӷ�̬���lib
#pragma comment(lib, "ws2_32.lib")

//UDP�����
int  main()
{

	//��ʼ��winsock2����
	WSADATA  wd;
	if(WSAStartup(MAKEWORD(2,2), &wd) !=0)
	{
		cout << "WSAStartup error:" << GetLastError() << endl;
		return 0;
    }

	//1.����UDP���ݱ��׽���
	SOCKET  s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (s == INVALID_SOCKET)
	{
		cout << "socket  error:" << GetLastError() << endl;
		return 0;
	}


	//2.�󶨵�Ip��ַ�Ͷ˿�
	sockaddr_in  addr;
	addr.sin_port = htons(8000);//�����ֽ���
	//addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");//s_addr�Ǹ���
	addr.sin_family = AF_INET;

	int len = sizeof(SOCKADDR);
	if (bind(s, (SOCKADDR*)&addr, len) == SOCKET_ERROR)
	{
		cout << "bind error:" << GetLastError() << endl;
		return 0;
	}

	int nNetTimeout = 5000; //5��
    //����ʱ��
	if (setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&nNetTimeout, sizeof(int)) == SOCKET_ERROR)
	{
		cout << "setsockopt error:" << GetLastError() << endl;
		return 0;
	}



	//3.���ܻ��߷�������recvfrom, sendto ,��ͬ��TCP�� recv�� send
	int   ret = 0;
	do
	{
		//���ܿͻ��˵ĵ�ַ
		sockaddr_in  addrClient;
		memset(&addrClient, 0, sizeof(addrClient));
		int len = sizeof(SOCKADDR);//Ҫ��ֵ�ṹ��ĳ���

		char buf[100] = {0};
		//Ĭ���������ģ�Ҳ����˵�����û�����ݹ�������һֱ�ȴ�
		ret= recvfrom(s, buf, 100, 0, (SOCKADDR*)&addrClient, &len);
		cout << "recvfrom " << ret << ":    " << buf<<endl;


		//�ֽ�ʹ������Ŀͻ��˵�ַ
		ret= sendto(s, "I am Server!", strlen("I am Server!"),0,  (SOCKADDR*)&addrClient, len);

	} while (ret != SOCKET_ERROR  &&  ret != 0);

	//4.�ر��׽���
	closesocket(s);
	 

	//����winsock2����
	WSACleanup();


	return 0;
}