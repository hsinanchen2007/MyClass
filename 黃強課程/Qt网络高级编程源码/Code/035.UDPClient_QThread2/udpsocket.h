#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include<QUdpSocket>
#include<QThread>


//第一步、编写一个类，继承自QObject类
//很明显QUdpSocket的最根本的父类就是QObject
class UdpSocket : public QUdpSocket
{
    Q_OBJECT
public:
    UdpSocket();

public slots:
    //将要在线程中执行的内容写成槽函数
    void  slotSend(QHostAddress addr,quint16 port, QByteArray arr  );


 signals:
    //通知外面的MainWindow更新界面的信号
    void sigPrint(QString info );

};

#endif // UDPSOCKET_H
