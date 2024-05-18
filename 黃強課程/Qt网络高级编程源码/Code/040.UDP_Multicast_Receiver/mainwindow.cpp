#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("UDP组播接收端");

    //绑定QUdpSocket相应的信号槽
    connect( &m_udp,  & QUdpSocket::readyRead , this  ,  &MainWindow::slotReadyRead);

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

            ui->plainTextEdit->appendPlainText(str);
        }

    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonBind_clicked()
{
    //获取端口
    quint16 port = ui->lineEditPort->text().toUInt();

    bool ret= m_udp.bind( QHostAddress::AnyIPv4, port,QUdpSocket::ShareAddress);

    if(ret)
    {
        ui->plainTextEdit->appendPlainText("绑定成功!");
    }
    else
    {
          ui->plainTextEdit->appendPlainText("绑定失败!");
    }


}

void MainWindow::on_pushButtonJoin_clicked()
{
    //要加入的组播IP
   QString ip = ui->lineEditIP->text();

  bool ret=  m_udp.joinMulticastGroup(QHostAddress(ip));
  if(ret)
  {
      ui->plainTextEdit->appendPlainText("加入组播成功!");
  }
  else
  {
        ui->plainTextEdit->appendPlainText("加入组播失败!");
  }
}

void MainWindow::on_pushButtonLeave_clicked()
{
    //要离开的组播IP
   QString ip = ui->lineEditIP->text();

  bool ret=  m_udp.leaveMulticastGroup(QHostAddress(ip));
  if(ret)
  {
      ui->plainTextEdit->appendPlainText("离开组播成功!");
  }
  else
  {
        ui->plainTextEdit->appendPlainText("离开组播失败!");
  }
}
