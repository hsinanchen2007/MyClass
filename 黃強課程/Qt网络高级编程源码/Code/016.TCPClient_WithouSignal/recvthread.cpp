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
    m_tcpClient = new QTcpSocket();


    //连接到TCP服务器
    m_tcpClient->connectToHost(ip,port);

    //使用阻塞函数判断是否连接成功,设置超时时间1s
    bool  bConn= m_tcpClient->waitForConnected(1000);
    if(bConn)
    {
        emit sigPrint("连接服务器成功！",true);
    }
    else
    {
        emit sigPrint("连接服务器失败！",false);
    }

   //自己创建一个while循环， 读取服务器的数据
    while(bRun)
    {
        //如果已经不是连接状态，则退出循环
        if(m_tcpClient->state() !=  QTcpSocket::ConnectedState)
        {
            break;
        }


        //阻塞等待是否有数据可以读取,可以设置超时时间
        //超时返回false，继续向下运行
        if(m_tcpClient->waitForReadyRead(10))
        {
            //有数据可以读
             QByteArray  data = m_tcpClient->readAll();

             QString msg = data;
             QString str = QString("收到数据: %1").arg(msg);

             emit sigPrint(str, true);
        }

        //检查发送队列是否有要发送的数据
        while(que.size()>0)
        {
            QByteArray data=  que.dequeue();

            m_tcpClient->write(data);

            if(! m_tcpClient->waitForBytesWritten(10))
            {
                emit sigPrint("发送数据失败！", true);
            }

        }


    }//end-of-while

     //关闭连接
     m_tcpClient->disconnectFromHost();

     //判断一下状态，可以省略
     if((m_tcpClient->state() ==  QTcpSocket::UnconnectedState)
        || m_tcpClient->waitForDisconnected(10))
     {
         emit sigPrint("断开连接！",false);
     }

     //销毁对象
     m_tcpClient->deleteLater();

     qDebug()<<"线程结束了!";

}



