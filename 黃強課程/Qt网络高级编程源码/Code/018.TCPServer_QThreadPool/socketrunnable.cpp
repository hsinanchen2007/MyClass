#include "socketrunnable.h"
#include "tcpserver.h"

SocketRunnable::SocketRunnable(qintptr  s)
{
  this->socketDescriptor = s;
}


//线程执行的位置
void   SocketRunnable::run()
{
    qDebug()<<"run 线程"<< QThread::currentThread();

    //在线程中创建于客户端通讯的QTcpSocket对象，它才属于此线程
     socket =  new  TcpSocket;
     socket->setSocketDescriptor(socketDescriptor);

     QString  str= QString("客户端%1:%2连接成功!")
             .arg(socket->peerAddress().toString())
             .arg(socket->peerPort());

     emit sigPrint(str);

     //绑定QTcpSocket相应的信号槽
     connect( socket, SIGNAL(disconnected()) ,
              this , SLOT(slotDisconnected()),Qt::DirectConnection);

   //接收到数据时发出的信号
     connect( socket, SIGNAL(readyRead()) ,
              this , SLOT(slotReadyRead()),Qt::DirectConnection);

     //绑定信号槽，触发发送数据
     //QueuedConnection是让槽函数在接受者所在的线程调用
     connect( this , SIGNAL(sigSend(QByteArray)) ,
              socket , SLOT(slotSend(QByteArray)),Qt::QueuedConnection);



     //保持一个事件循环,除非调用 eventLoop->exit来退出循环
     eventLoop= new QEventLoop();
     eventLoop->exec(); //如果想停止，必须调用 eventLoop->exit()

     //线程执行完毕

     //关闭连接
     socket->disconnectFromHost();
     //销毁对象
     socket->deleteLater();

     eventLoop->deleteLater();

     qDebug()<<"客户端线程结束了!";

}

 void   SocketRunnable::send(QByteArray arr)
 {
       emit sigSend(arr);
 }

 void   SocketRunnable::close( )
 {
       //退出线程的事件循环
         eventLoop->exit(0);
 }

void   SocketRunnable::slotDisconnected()
{
       emit sigPrint("连接被断开！");


      //移除当前线程对象
       TcpServer::clients.removeOne(this);
       qDebug()<<"剩余"<< TcpServer::clients.size()<<"个客户端";

        eventLoop->exit(0);//退出循环
}


void SocketRunnable::slotReadyRead()
{
    qDebug()<<"recv 数据 "<<QThread::currentThread();


   //有数据可以读
    QByteArray  data = socket->readAll();

    QString msg = data;
    QString str = QString("收到客户端%1:%2数据: %3")
            .arg(socket->peerAddress().toString())
            .arg(socket->peerPort())
            .arg(msg);

    emit sigPrint(str);

    //模拟一个耗时5s操作
    //QThread::sleep(5);

}
