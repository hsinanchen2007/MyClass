#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMetaEnum>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("UDP客户端（多线程、方式二）");

    //因为sigSend信号使用了QHostAddress，
    //(Make sure 'QHostAddress' is registered using qRegisterMetaType().)
    qRegisterMetaType<QHostAddress>("QHostAddress");


    // 第三步，调用moveToThread将QUdpSocket对象 移动到线程里面
    socket.moveToThread(&thread);

    //开启线程
    thread.start();

    //连接信号槽
    connect(this , &MainWindow::sigSend, &socket ,&UdpSocket::slotSend);

    connect(&socket , &UdpSocket::sigPrint, this ,&MainWindow::slotPrint);

    connect(&thread,&QThread::finished, this , &MainWindow::slotFinished);


    qDebug()<<"thread对象的地址"<<&thread;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonSend_clicked()
{
    //无需连接，指定IP与端口就可以发送数据了
    QString ip = ui->lineEditIP->text();
    quint16  port  = ui->lineEditPort->text().toUInt();

    //获取要发送的内容
    QString msg = ui->lineEditSend->text();
    QByteArray  data = msg.toUtf8();

    QHostAddress addr(ip);
    //发送数据，需要指定接收方的IP与端口
    emit  sigSend(addr, port,data);
}


void MainWindow::slotPrint(QString info)
{
     ui->plainTextEditRecv->appendPlainText(info);
}

void MainWindow::slotFinished()
{
    //  ui->plainTextEditRecv->appendPlainText("线程结束啦！");
    qDebug()<<"线程结束啦！";
}


void MainWindow::closeEvent(QCloseEvent *event)
{
      qDebug()<<"窗口关闭按钮被点击！！！";

      //停止线程
      thread.quit();

      thread.wait();//等待线程结束
}


