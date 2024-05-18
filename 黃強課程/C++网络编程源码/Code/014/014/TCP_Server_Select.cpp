#include<winsock2.h>
#include<iostream>

using  namespace  std;

#pragma comment(lib,"Ws2_32.lib")

int  main()
{
	//初始化winsock的环境
	 WSADATA  wd;
	 if(WSAStartup(MAKEWORD(2,2,),  &wd) ==  SOCKET_ERROR)
	 {
		 cout << "WSAStartup  error:" <<GetLastError()<< endl;
		 return 0;
    }


	 //1.创建监听套接字
	 SOCKET  sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	 if (sListen == INVALID_SOCKET)
	 {
		 cout << "socket  error:" << GetLastError() << endl;
		 return 0;
	 }


	 //2.绑定到ip与端口
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

	 //3.监听套接字
	 if (listen(sListen, 5) == SOCKET_ERROR)
	 {
		 cout << "listen  error:" << GetLastError() << endl;
		 return 0;
	 }


	 //4. select开始了
	 fd_set  readSet;//定义一个读（接受消息）的集合
	 FD_ZERO(&readSet);//初始化集合
	 FD_SET(sListen, &readSet);


	 //不停的select才可以读取套接字的状态改变
	 while (true)
	 {
		 fd_set tmpSet;//定义一个临时的集合
		 FD_ZERO(&tmpSet);//初始化集合
		 tmpSet = readSet;// 每次循环都是所有的套接字

		 //利用select选择出集合中可以读写的多个套接字，有点像筛选
		 int ret = select(0, &tmpSet, NULL, NULL, NULL);//最后一个参数为NULL，一直等待，直到有数据过来
		 if (ret == SOCKET_ERROR)
		 {
			 continue;
		 }

		 //成功筛选出来的tmpSet可以发送或者接收的socket
		 for (int i = 0; i < tmpSet.fd_count; ++i)
		 {
			 //获取到套接字
			 SOCKET  s = tmpSet.fd_array[i];
			 //接收到客户端的链接
			 if (s == sListen)
			 {
				 SOCKET  c = accept(s, NULL, NULL);
				 //fd_set集合最大值为64
				 if (readSet.fd_count < FD_SETSIZE)
				 {
					 //往集合中添加客户端套接字
					 FD_SET(c, &readSet);
					 cout << "欢迎" << c << "进入聊天室！" << endl;

					 //给客户端发送欢迎
					 char buf[100] = {0};
					 sprintf(buf, "欢迎%d进入聊天室！", c);
					 send(c, buf, 100, 0); 
				 }
				 else
				 {
					 cout << "达到客户端容量上线！" << endl;
				 }

			 }
			 else//一定是客户端
			 {
				 //接收客户端的数据
				 char buf[100] = { 0 }; 
				 ret=recv(s, buf, 100, 0);
				 if (ret == SOCKET_ERROR || ret == 0)
				 {
					 closesocket(s);
					 FD_CLR(s, &readSet);
					 cout<< s << "离开聊天室！" << endl;
				 }
				 else
				 {
					 cout << s << "说：" <<buf<< endl;
				 }

			 }
		 }

	 }

	 //关闭监听套接字
	 closesocket(sListen);

	 //清理winsock环境
	 WSACleanup();

	return 0;
}