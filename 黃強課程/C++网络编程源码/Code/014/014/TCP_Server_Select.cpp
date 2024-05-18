#include<winsock2.h>
#include<iostream>

using  namespace  std;

#pragma comment(lib,"Ws2_32.lib")

int  main()
{
	//��ʼ��winsock�Ļ���
	 WSADATA  wd;
	 if(WSAStartup(MAKEWORD(2,2,),  &wd) ==  SOCKET_ERROR)
	 {
		 cout << "WSAStartup  error:" <<GetLastError()<< endl;
		 return 0;
    }


	 //1.���������׽���
	 SOCKET  sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	 if (sListen == INVALID_SOCKET)
	 {
		 cout << "socket  error:" << GetLastError() << endl;
		 return 0;
	 }


	 //2.�󶨵�ip��˿�
	 sockaddr_in  addr;
	 addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	 addr.sin_port = htons(8000);
	 addr.sin_family = AF_INET;
	 int len = sizeof(sockaddr_in);
	 if (bind(sListen, (SOCKADDR*)&addr, len) == SOCKET_ERROR)
	 {
		 cout << "bind  error:" << GetLastError() << endl;
		 return 0;
	 }

	 //3.�����׽���
	 if (listen(sListen, 5) == SOCKET_ERROR)
	 {
		 cout << "listen  error:" << GetLastError() << endl;
		 return 0;
	 }


	 //4. select��ʼ��
	 fd_set  readSet;//����һ������������Ϣ���ļ���
	 FD_ZERO(&readSet);//��ʼ������
	 FD_SET(sListen, &readSet);


	 //��ͣ��select�ſ��Զ�ȡ�׽��ֵ�״̬�ı�
	 while (true)
	 {
		 fd_set tmpSet;//����һ����ʱ�ļ���
		 FD_ZERO(&tmpSet);//��ʼ������
		 tmpSet = readSet;// ÿ��ѭ���������е��׽���

		 //����selectѡ��������п��Զ�д�Ķ���׽��֣��е���ɸѡ
		 int ret = select(0, &tmpSet, NULL, NULL, NULL);//���һ������ΪNULL��һֱ�ȴ���ֱ�������ݹ���
		 if (ret == SOCKET_ERROR)
		 {
			 continue;
		 }

		 //�ɹ�ɸѡ������tmpSet���Է��ͻ��߽��յ�socket
		 for (int i = 0; i < tmpSet.fd_count; ++i)
		 {
			 //��ȡ���׽���
			 SOCKET  s = tmpSet.fd_array[i];
			 //���յ��ͻ��˵�����
			 if (s == sListen)
			 {
				 SOCKET  c = accept(s, NULL, NULL);
				 //fd_set�������ֵΪ64
				 if (readSet.fd_count < FD_SETSIZE)
				 {
					 //����������ӿͻ����׽���
					 FD_SET(c, &readSet);
					 cout << "��ӭ" << c << "���������ң�" << endl;

					 //���ͻ��˷��ͻ�ӭ
					 char buf[100] = {0};
					 sprintf(buf, "��ӭ%d���������ң�", c);
					 send(c, buf, 100, 0); 
				 }
				 else
				 {
					 cout << "�ﵽ�ͻ����������ߣ�" << endl;
				 }

			 }
			 else//һ���ǿͻ���
			 {
				 //���տͻ��˵�����
				 char buf[100] = { 0 }; 
				 ret=recv(s, buf, 100, 0);
				 if (ret == SOCKET_ERROR || ret == 0)
				 {
					 closesocket(s);
					 FD_CLR(s, &readSet);
					 cout<< s << "�뿪�����ң�" << endl;
				 }
				 else
				 {
					 cout << s << "˵��" <<buf<< endl;
				 }

			 }
		 }

	 }

	 //�رռ����׽���
	 closesocket(sListen);

	 //����winsock����
	 WSACleanup();

	return 0;
}