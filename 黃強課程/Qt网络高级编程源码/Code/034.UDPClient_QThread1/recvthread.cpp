#include "recvthread.h"

RecvThread::RecvThread()
{
    //因为sigSend信号使用了QHostAddress，
    //(Make sure 'QHostAddress' is registered using qRegisterMetaType().)
    qRegisterMetaType<QHostAddress>("QHostAddress");
}

//线程执行的位置
void RecvThread::run()
{
    qDebug()<<"run 线程"<<QThread::currentThread();


    //在线程中创建这个对象
      socket = new  UdpSocket();

      //绑定QUdpSocket相应的信号槽

       //Qt::DirectConnection让槽函数在发送者所在的线程调用
      connect( socket,  & QUdpSocket::readyRead ,
               this  ,  &RecvThread::slotReadyRead , Qt::DirectConnection);

      //Qt::QueuedConnection让槽函数在接收者所在的线程调用
      connect(this ,  &RecvThread::sigSend ,
                socket,   &UdpSocket::slotSend ,Qt::QueuedConnection)  ;


      emit sigPrint("线程启动！");

      //开启事件循环，保持线程一直运行的状态
      exec();

      //关闭
      socket->close();
      socket->deleteLater();

      qDebug()<<"退出线程事件循环啦！";
}

void  RecvThread::slotReadyRead()
{
    qDebug()<<"recv 线程"<<QThread::currentThread();


    //是否有数据抵达
    while ( socket->hasPendingDatagrams())
    {
        //获取要读取数据的大小
        int size = socket->pendingDatagramSize();

        //定义一块缓冲区，来接收数据
        QByteArray arr;
        arr.resize(size);

        QHostAddress  addr; //发送方的IP
        quint16  port;//发送方的端口

        //接收数据的同时，获取到对方的IP与端口
        int ret = socket->readDatagram(arr.data(),size, &addr,&port);

        if(ret>0)
        {
            QString msg = arr;

            QHostAddress  ipv4 (addr.toIPv4Address());
            QString str = QString("接收到%1:%2的消息: %3")
                    .arg(ipv4.toString()).arg(port).arg(msg);

            emit sigPrint(str);
        }

    }
}
void RecvThread::close()
{
     exit(0);//结束线程的事件循环
}

void  RecvThread::send(QHostAddress addr,quint16 port, QByteArray arr)
{
    //触发发送数据的信号
    emit sigSend( addr,port, arr);
}
