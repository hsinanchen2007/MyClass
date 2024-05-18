#ifndef TCPSERVER_H
#define TCPSERVER_H

#include<QTcpServer>
#include<QThreadPool>
#include<QList>
#include "socketrunnable.h"

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    TcpServer();

    //重写虚方法，当有新的客户端连接的时候，自动被调用，
    //会传给我们与客户端通讯的套接字描述符
      virtual void incomingConnection(qintptr handle);

     void send(QByteArray arr);

     void close();

  public:
     //静态的，方便RecvThread类里面访问
    static  QList<SocketRunnable *> clients;

};

#endif // TCPSERVER_H
