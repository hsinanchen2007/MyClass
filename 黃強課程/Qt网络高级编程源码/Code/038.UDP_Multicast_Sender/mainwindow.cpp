#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("UDP组播发送端");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonSend_clicked()
{
    //这里需要组播IP地址，否则就不是组播
    QString ip = ui->lineEditIP->text();
    quint16 port = ui->lineEditPort->text().toUInt();

    //发送的消息
    QString  msg= ui->lineEditSend->text();
    QByteArray  data = msg.toUtf8();

    //发送数据报
    m_udp.writeDatagram( data, QHostAddress(ip),port);
}
