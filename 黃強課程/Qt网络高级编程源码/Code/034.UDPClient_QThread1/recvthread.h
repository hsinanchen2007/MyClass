#ifndef RECVTHREAD_H
#define RECVTHREAD_H

#include<QThread>
#include<QUdpSocket>
#include "UdpSocket.h"

class RecvThread : public QThread
{
    Q_OBJECT
public:
    RecvThread();

      virtual void run();

      void close();
      void  send(QHostAddress addr,quint16 port, QByteArray arr);

 signals:
      //通知外面的MainWindow更新界面的信号
      void sigPrint(QString info );

      //发送给QUdpSocket对象来发送消息的
      void  sigSend(QHostAddress addr,quint16 port, QByteArray arr  );

 public slots:
  void  slotReadyRead();


 private:
    //QUdpSocket   *socket;//指针，方便在run中new

    UdpSocket   *socket;//派生自QUdpSocket类，方便我们自己写槽函数
};

#endif // RECVTHREAD_H
