#include "recvthread.h"

RecvThread::RecvThread( )
{
    qDebug()<<"RecvThread对象 "<<QThread::currentThread();

}

void  RecvThread::setParam(QString ip ,quint16 port )
{
     this->ip =ip;
     this->port = port;
}

//写线程需要执行的内容
void RecvThread::run()
{

    qDebug()<<"run方法执行 "<<QThread::currentThread();

    //在run线程中创建的
    //m_tcpClient = new QTcpSocket();
    m_tcpClient = new TcpSocket();

    //连接到TCP服务器
    m_tcpClient->connectToHost(ip,port);

     //连接主要的信号槽
     connect( m_tcpClient, SIGNAL(connected()) ,
              this , SLOT(slotConnected()),Qt::DirectConnection);

     connect( m_tcpClient, SIGNAL(disconnected()) ,
              this , SLOT(slotDisconnected()),Qt::DirectConnection);

   //接收到数据时发出的信号
     connect( m_tcpClient, SIGNAL(readyRead()) ,
              this , SLOT(slotReadyRead()),Qt::DirectConnection);

     //触发发送消息
     connect( this , SIGNAL(sigSend(QByteArray)) ,
              m_tcpClient , SLOT(slotSend(QByteArray)),Qt::QueuedConnection);


     //保持一个事件循环,除非调用quit或者exit来退出循环
     exec();

     //线程执行完毕

     //关闭连接
     m_tcpClient->disconnectFromHost();
     //销毁对象
     m_tcpClient->deleteLater();

     qDebug()<<"线程结束了!";

}

void  RecvThread::close()//结束线程
{
   // quit();//退出事件循环

    exit(0);//退出事件循环
}




void   RecvThread::slotConnected()
{
    emit sigPrint("连接服务器成功！", true);
}

void   RecvThread::slotDisconnected()
{
      emit sigPrint("连接被断开！", false);

       exit(0);//退出循环
}


void RecvThread::slotReadyRead()
{
    qDebug()<<"recv 数据 "<<QThread::currentThread();


   //有数据可以读
    QByteArray  data = m_tcpClient->readAll();

    QString msg = data;
    QString str = QString("收到数据: %1").arg(msg);

    emit sigPrint(str, true);

    //模拟一个耗时5s操作
    //QThread::sleep(5);

}


void  RecvThread::send(QByteArray arr)
{
    emit sigSend(arr);
}
