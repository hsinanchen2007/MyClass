#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMetaEnum>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("UDP服务端");

    //绑定QUdpSocket相应的信号槽

    connect( &m_udp,  & QUdpSocket::readyRead , this  ,  &MainWindow::slotReadyRead);

    connect( &m_udp,  & QUdpSocket::stateChanged , this  ,  &MainWindow::slotStateChanged);

    //这样写出现歧义，究竟是信号error 还是函数erro
   //connect(&m_udp , &QUdpSocket::error ,this ,&MainWindow::slotError);

    //方法一：
  // connect(&m_udp , SIGNAL(error(QAbstractSocket::SocketError)) ,this , SLOT(slotError(QAbstractSocket::SocketError)));

     //方法一：
   connect( &m_udp,
   static_cast< void  (QUdpSocket::*)(QAbstractSocket::SocketError)>(& QUdpSocket::error) ,
    this  ,
   &MainWindow::slotError);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonSend_clicked()
{
    //获取要发送的内容
    QString msg = ui->lineEditSend->text();
    QByteArray  data = msg.toUtf8();


    //群发
    foreach (  auto pair,   clients)
    {
        //客户端的IP与端口， first代表QPair的第一个值， second代表第二个
        QHostAddress addr = pair.first;
        quint16 port = pair.second;

        //发送数据，需要指定接收方的IP与端口
        m_udp.writeDatagram(data,  addr, port);
    }

}

void  MainWindow::slotReadyRead()
{
    //是否有数据抵达
    while ( m_udp.hasPendingDatagrams())
    {
        //获取要读取数据的大小
        int size = m_udp.pendingDatagramSize();

        //定义一块缓冲区，来接收数据
        QByteArray arr;
        arr.resize(size);

        QHostAddress  addr; //发送方的IP
        quint16  port;//发送方的端口

        //接收数据的同时，获取到对方的IP与端口
        int ret = m_udp.readDatagram(arr.data(),size, &addr,&port);

        if(ret>0)
        {
            QString msg = arr;

            QHostAddress  ipv4 (addr.toIPv4Address());
            QString str = QString("接收到%1:%2的消息: %3")
                    .arg(ipv4.toString()).arg(port).arg(msg);

            ui->plainTextEditRecv->appendPlainText(str);

            //保存客户端的IP与端口，方便我到时给客户端发数据
            // 推荐观看黄强老师的 《C++ STL高级编程》课程
            clients.insert( qMakePair( ipv4 ,port) ); //重复则插入不进去
            qDebug() << "客户端数量"<<clients.size();

        }

    }
}


 void MainWindow::slotStateChanged(QAbstractSocket::SocketState  state)
{
          //枚举类型转为字符串、方便观测
            QString  strState = QMetaEnum::fromType<QAbstractSocket::SocketState>().valueToKey( state );

            QString str =QString("状态：%1").arg( strState ) ;

            ui->plainTextEditRecv->appendPlainText( str );

}

 void MainWindow::slotError(QAbstractSocket::SocketError  err)
 {
     //枚举类型转为字符串、方便观测
       QString  strErr = QMetaEnum::fromType<QAbstractSocket::SocketError>().valueToKey( err );

       QString str =QString("错误码：%1   描述： %2").arg( strErr ).arg(  m_udp.errorString() ) ;

       ui->plainTextEditRecv->appendPlainText( str );
 }

void MainWindow::on_pushButtonBind_clicked()
{

    QString text= ui->pushButtonBind->text();

    if(text == "绑定")
    {
                QString ip = ui->lineEditIP->text();
                quint16  port  = ui->lineEditPort->text().toUInt();

                QHostAddress  addr(ip );


                // 绑定指定IP与端口
                bool   ret= m_udp.bind(addr,port, QUdpSocket::ShareAddress);
                if(ret)
                {
                     ui->plainTextEditRecv->appendPlainText("绑定成功！");
                       ui->pushButtonBind->setText("停止");
                }
                else
                {
                       ui->plainTextEditRecv->appendPlainText("绑定失败 "+m_udp.errorString());
                }
    }
    else
    {
          m_udp.close();

          //清空客户端列表
          clients.clear();

          ui->plainTextEditRecv->appendPlainText("停止绑定了！");

          ui->pushButtonBind->setText("绑定");
    }

}
