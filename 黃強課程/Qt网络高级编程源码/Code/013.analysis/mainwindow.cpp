#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("TCP客户端");


    //连接主要的信号槽
    connect( &m_tcpClient, SIGNAL(connected()) , this , SLOT(slotConnected()));
    connect( &m_tcpClient, SIGNAL(disconnected()) , this , SLOT(slotDisconnected()));
    connect( &m_tcpClient, SIGNAL(stateChanged(QAbstractSocket::SocketState)) ,
             this , SLOT(slotStateChanged(QAbstractSocket::SocketState)));
    connect( &m_tcpClient, SIGNAL(error(QAbstractSocket::SocketError)) ,
             this , SLOT(slotError(QAbstractSocket::SocketError)));

    //接收到数据时发出的信号
    connect( &m_tcpClient, SIGNAL(readyRead()) ,
             this , SLOT(slotReadyRead()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonConnect_clicked()
{
    QString text=ui->pushButtonConnect->text();
    if(text=="连接")
    {
        //获取IP与端口
        QString ip= ui->lineEditIP->text();
        uint  port = ui->lineEditPort->text().toUInt();

        //连接到TCP服务器
        m_tcpClient.connectToHost(ip,port);
    }
    else
    {
         //断开与服务器的连接
        m_tcpClient.disconnectFromHost();
    }
}


void   MainWindow::slotConnected()
{
   ui->plainTextEditRecv->appendPlainText("连接服务器成功！");
   ui->pushButtonConnect->setText("断开");
}

void   MainWindow::slotDisconnected()
{
   ui->plainTextEditRecv->appendPlainText("连接被断开！");
   ui->pushButtonConnect->setText("连接");
}
void   MainWindow::slotStateChanged(QAbstractSocket::SocketState state)
{
    //枚举类型转为字符串、方便观测
     QString  strState = QMetaEnum::fromType
             <QAbstractSocket::SocketState>().valueToKey( state );

    QString str = QString("状态: %1").arg(strState);
    ui->plainTextEditRecv->appendPlainText( str );
}

void   MainWindow::slotError(QAbstractSocket::SocketError  err)
{
    //枚举类型转为字符串、方便观测
     QString  strError = QMetaEnum::fromType
             <QAbstractSocket::SocketError>().valueToKey( err );

    QString str = QString("错误: %1").arg(strError);
    ui->plainTextEditRecv->appendPlainText( str );
}


void MainWindow::slotReadyRead()
{
    qDebug()<<"recv 数据 "<<QThread::currentThread();


   //有数据可以读
    QByteArray  data = m_tcpClient.readAll();

    QString msg = data;
    QString str = QString("收到数据: %1").arg(msg);
    ui->plainTextEditRecv->appendPlainText(str);

    //模拟一个耗时5s操作
    QThread::sleep(5);

}

void MainWindow::on_pushButtonSend_clicked()
{
    qDebug()<<"send 数据 "<<QThread::currentThread();

    QString  msg = ui->lineEditSend->text();

    //注意字符编码，需要保持一致
    QByteArray data = msg.toUtf8();
    //给服务端发送数据
    m_tcpClient.write(data);
}
