#include<winsock2.h>//winsock��ͷ�ļ�
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


	//1.����TCP   socket , ��ʽ�׽���
	SOCKET   s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
	{
		cout << "socket  error:" << WSAGetLastError() << endl;
		return 0;
	}

	//2.���ӷ����
	sockaddr_in   addr;//������ʹ��sockaddr��������sockaddr_in
	addr.sin_port = htons(8000);//�����ֽ���
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//�����ֽ���
	addr.sin_family = AF_INET; //��ַ��
	int len = sizeof(sockaddr_in);
	  
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
	   cout << "recv" << inet_ntoa(addr.sin_addr) << ":    " << buf << endl;// inet_ntoaת��ΪIP�ַ���

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
