#ifndef SOCKETRUNNABLE_H
#define SOCKETRUNNABLE_H

#include<QRunnable>
#include<QDebug>
#include<QEventLoop>
#include<QHostAddress>
#include "tcpsocket.h"


//继承自QObject是为了使用信号槽的connect
class SocketRunnable :  public QObject ,public QRunnable
{
      Q_OBJECT

public:
    SocketRunnable(qintptr  socketDescriptor);

    ~SocketRunnable()
    {
        qDebug()<<"QRunnable对象销毁！"<<this;
    }
   virtual void run();
   void  send(QByteArray arr);
   void close();

public slots:
    //槽函数
      void   slotDisconnected();
      void   slotReadyRead();

signals:
     //这个信号，线程内发送，传递给外面的MainWindows 在界面上显示
     void  sigPrint(QString info,  bool conn =true);

     //去触发QTcpSocket去发送数据
     void sigSend(QByteArray arr);

 private:

    //与客户端通讯的套接字对象
   //QTcpSocket *  socket;

     //自定义的类，为了能实现自己的槽函数
     TcpSocket *  socket;

    //系统底层套接字描述符（传统的网络编程 socket()函数返回的值）
    qintptr  socketDescriptor;

    //事件循环类
    QEventLoop * eventLoop;

};

#endif // SOCKETRUNNABLE_H
