#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("UDP广播发送端");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonSend_clicked()
{
    //接收端的端口
    quint16 port = ui->lineEditPort->text().toUInt();

    //消息内容
    QString  msg= ui->lineEditSend->text();
    QByteArray data= msg.toUtf8();

    //发送时，指定广播QHostAddress::Broadcast
    //m_udp.writeDatagram( data, QHostAddress::Broadcast ,port );

   // m_udp.writeDatagram( data, QHostAddress("255.255.255.255") ,port );

    m_udp.writeDatagram( data, QHostAddress("192.168.16.255") ,port );
}
