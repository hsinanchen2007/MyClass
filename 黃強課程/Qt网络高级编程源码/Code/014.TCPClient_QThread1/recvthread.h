#ifndef RECVTHREAD_H
#define RECVTHREAD_H
//头文件
#include<QTcpSocket>
#include<QThread>
#include<QDebug>
#include"tcpsocket.h"

//步骤一，新建一个类继承自QThread
class RecvThread : public QThread
{
    Q_OBJECT
public:
    RecvThread( );

    void  setParam(QString ip ,quint16 port );

     //步骤二，重写虚方法run
     virtual void run();

public slots:
    //槽函数
      void   slotConnected();
      void   slotDisconnected();
      void   slotReadyRead();

 public:
      void close();//结束线程
      void send(QByteArray arr);//发送数据

 signals:
      //这个信号，线程内发送，传递给外面的MainWindows 在界面上显示
      void  sigPrint(QString info,  bool conn =true);
      //这个信号是发给 TcpSocket，触发发送消息行为
      void  sigSend(QByteArray  arr);
private:
    //定义一个QTcpSocket对象（在主线程中创建的）
    //在run方法使用这个对象，会提示一些问题
   //QTcpSocket  m_tcpClient;

    //最好是在线程run中创建QTcpSocket对象
   // QTcpSocket  *m_tcpClient;

      //因为需要自定义一个槽函数，所以派生自QTcpSocket
     TcpSocket  *m_tcpClient;

    QString ip;
    quint16 port;

};

#endif // RECVTHREAD_H
