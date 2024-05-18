#include "udpsocket.h"

UdpSocket::UdpSocket()
{

    //连接QUdpSocket相关的信号槽

    //以lamba表达式的形式， 你也可以用传统的方式
    connect(  this  ,  &QUdpSocket::readyRead ,[=]
    {
        qDebug()<<"recv 线程"<<QThread::currentThread();


        //是否有数据抵达
        while ( hasPendingDatagrams())
        {
            //获取要读取数据的大小
            int size = pendingDatagramSize();

            //定义一块缓冲区，来接收数据
            QByteArray arr;
            arr.resize(size);

            QHostAddress  addr; //发送方的IP
            quint16  port;//发送方的端口

            //接收数据的同时，获取到对方的IP与端口
            int ret =  readDatagram(arr.data(),size, &addr,&port);

            if(ret>0)
            {
                QString msg = arr;

                QHostAddress  ipv4 (addr.toIPv4Address());
                QString str = QString("接收到%1:%2的消息: %3")
                        .arg(ipv4.toString()).arg(port).arg(msg);

                 //发出信号通知主界面显示
                emit sigPrint(str);
            }

        }
    });


}

void  UdpSocket::slotSend(QHostAddress addr,quint16 port, QByteArray arr  )
{
    qDebug()<<"send 线程"<<QThread::currentThread();

      writeDatagram(arr,  addr, port);
}
