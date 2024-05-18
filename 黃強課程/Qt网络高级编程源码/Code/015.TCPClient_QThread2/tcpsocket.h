#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include<QThread>
#include<QTcpSocket>


//步骤一， 新建一个类，继承自QObject类 （QTcpSocket也是继承自QObject类）
class TcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    TcpSocket();

 public slots:

    //将线程中要执行的内容写成槽函数
    void slotConnect(QString ip, quint16   port); //连接
    void slotSend(QByteArray  arr);//发送
    void slotClose();//关闭套接字

 signals:
    //发给外部MainWindow的信号，方便通知外面的界面进行一些打印
    void sigPrint(QString info, bool conn);

};

#endif // TCPSOCKET_H
