#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("TCP服务端");

  }

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButtonStart_clicked()
{
    QString text = ui->pushButtonStart->text();
    if(text == "启动")
    {
            QString ip = ui->lineEditIP->text();
            uint port  = ui->lineEditPort->text().toUInt();

            QHostAddress addr(ip);
            //在ip与端口监听客户端的连接
            bool  ret= m_tcpServer.listen(addr, port);
            if(ret)
            {
                ui->plainTextEditRecv->appendPlainText("监听成功！");
                ui->pushButtonStart->setText("停止");

                //连接信号槽 （ 当有客户端连接的时候发出newConnection信号）
                 connect(&m_tcpServer,  SIGNAL(newConnection()),
                              this , SLOT(slotNewConnection()));

            }
            else
            {
                ui->plainTextEditRecv->appendPlainText("监听失败！");
            }
    }
    else
    {
           //关闭与所有客户端的连接
          foreach( QTcpSocket * c , clients)
          {
            c->close();
          }

           //关闭TCP的监听
           m_tcpServer.close();
           ui->plainTextEditRecv->appendPlainText("服务器已停止!");
           ui->pushButtonStart->setText("启动");
    }


}


void MainWindow::slotNewConnection()
{
         //nextPendingConnection返回该连接与客户端通讯的套接字对象
         QTcpSocket * client=  m_tcpServer.nextPendingConnection();

         if(client!=nullptr)
         {
             QString  str= QString("客户端%1:%2连接成功!")
                     .arg(client->peerAddress().toString())
                     .arg(client->peerPort());
             ui->plainTextEditRecv->appendPlainText(str);

            //接收到数据时发出的信号
             connect( client, SIGNAL(readyRead()) ,  this , SLOT(slotReadyRead()));
             //绑定客户相应套接字的信号
             connect( client, SIGNAL(disconnected()) , this , SLOT(slotDisconnected()));

             //保存到客户端列表
             clients.push_back(client);

         }


}


void MainWindow::slotReadyRead()
{
   //有数据可以读,但是不知道是哪个客户端发来的数据
   //所以需要遍历每个客户端
    foreach( QTcpSocket * c , clients)
    {
            QByteArray  data = c->readAll();

             //接收的数据大小
             if(data.size()>0)
            {
               QString msg = data;

                QString  str= QString("收到了%1:%2消息:%3")
                        .arg( c->peerAddress().toString())
                        .arg( c->peerPort())
                        .arg( msg);

                ui->plainTextEditRecv->appendPlainText(str);
                }
    }

}

//客户端断开的时候发送disconnected的信号的槽函数
void   MainWindow::slotDisconnected()
{
    //sender表示发送信号的对象
   QTcpSocket * c = ( QTcpSocket * )sender();

   QString  str= QString("客户端%1:%2断开了！")
           .arg( c->peerAddress().toString())
           .arg( c->peerPort()) ;

   ui->plainTextEditRecv->appendPlainText(str);

   //从客户端列表移除
   clients.removeOne(c);

   //关闭QTcpSocket对象
   c->close();

}

void MainWindow::on_pushButtonSend_clicked()
{
    //获取要发送的内容
    QString  msg = ui->lineEditSend->text();
    QByteArray  data = msg.toUtf8();//转换为utf8字节数组

    //群发消息
     foreach( QTcpSocket * c , clients)
     {
         //发送数据
         c->write(data);
     }
}
