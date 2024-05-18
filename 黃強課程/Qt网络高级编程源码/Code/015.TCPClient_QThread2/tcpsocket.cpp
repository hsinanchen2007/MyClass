#include "tcpsocket.h"

TcpSocket::TcpSocket()
{
       //连接到服务端 信号槽 ,lamba表达式的写法
    connect( this , &TcpSocket::connected ,[this]
    {
         emit sigPrint("连接服务器成功!",true);
    });

    //断开连接信号
     connect( this , &TcpSocket::disconnected ,[this]
     {
          emit sigPrint("连接被断开!",false);
     });

     //有数据可读的信号
      connect( this , &TcpSocket::readyRead ,[this]
      {

          qDebug()<<"recv 数据 "<<QThread::currentThread();


         //有数据可以读
          QByteArray  data =  readAll();

          QString msg = data;
          QString str = QString("收到数据: %1").arg(msg);

          emit sigPrint(str, true);

          //模拟一个耗时5s操作
          //QThread::sleep(5);

      });
}


void TcpSocket::slotSend(QByteArray  arr)
{
      qDebug()<<"send 数据 "<<QThread::currentThread();

       write( arr );
}


void TcpSocket::slotConnect(QString ip, quint16   port)
{

    qDebug()<<"connect 连接 "<<QThread::currentThread();

    //连接到TCP服务端
    connectToHost(ip, port);
}

void TcpSocket::slotClose()
{
    //关闭与服务端的连接
    //close();
    disconnectFromHost();
}
