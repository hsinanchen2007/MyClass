#ifndef RECVTHREAD_H
#define RECVTHREAD_H

#include<QSet>
#include<QThread>
#include<QUdpSocket>
#include "UdpSocket.h"

class RecvThread : public QThread
{
    Q_OBJECT
public:
    RecvThread(QString ip,quint16 port);

      virtual void run();

      void close();
      void  send(QByteArray arr);

 signals:
      //通知外面的MainWindow更新界面的信号
      void sigPrint(QString info , bool bind=false );

      //发送给QUdpSocket对象来发送消息的
      void  sigSend(QHostAddress addr,quint16 port, QByteArray arr  );

 public slots:
  void  slotReadyRead();


 private:
    //QUdpSocket   *socket;//指针，方便在run中new

    UdpSocket   *socket;//派生自QUdpSocket类，方便我们自己写槽函数

    //保存连接过来的客户端的IP与端口 （使用QSet可以避免重复保存的地址）
    QSet<QPair<QHostAddress,quint16>> clients;

    //服务端需要绑定的IP与端口
    QString ip;
    quint16 port;
};

#endif // RECVTHREAD_H
