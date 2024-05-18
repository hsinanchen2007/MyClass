#include "tcpserver.h"
#include"mainwindow.h"

//静态变量初始化
QList<SocketRunnable *> TcpServer::clients;

TcpServer::TcpServer()
{

}


void TcpServer::incomingConnection(qintptr handle)
{
    qDebug()<<"当有客户端连接时被调用"<<handle;

    //为每个客户端创建一个QRunnable对象，执行相关的通讯代码
    SocketRunnable  * runnable = new SocketRunnable(handle);

    //默认就是run执行完毕之后自动删除QRunnable对象
    // runnable->setAutoDelete(true);

   //连接线程对象的信号槽
    connect( runnable, &SocketRunnable::sigPrint , (MainWindow*) parent(),   &MainWindow::slotPrint);


    //加入到客户端列表中去
    clients.push_back(runnable);

    //在线程池中，获取一个线程来执行QRunable
    QThreadPool::globalInstance()->start(runnable);

}


  void TcpServer::send(QByteArray arr)
  {
      //分别调用每个线程的发送
      foreach(SocketRunnable *t  , clients)
      {
          t->send(arr);
      }
  }


  void TcpServer::close( )
  {
      //调用父类的close
      QTcpServer::close();

      //分别调用每个线程对象的close
      foreach(SocketRunnable *t  , clients)
      {
          t->close();
      }

      //清空客户端列表
      clients.clear();
  }
