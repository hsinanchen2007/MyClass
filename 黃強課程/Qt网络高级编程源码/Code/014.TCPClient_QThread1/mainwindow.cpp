#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("TCP客户端（使用线程、方式一）");


    connect( &thread , &RecvThread::sigPrint , this , &MainWindow::slotPrint);
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

        thread.setParam(ip,port);

        //步骤三，启动线程,会自动的调用run方法
         thread.start();


    }
    else
    {
         //断开与服务器的连接
        thread.close();
    }
}

void  MainWindow::slotPrint(QString info,  bool conn)
{
      ui->plainTextEditRecv->appendPlainText(info);

      if(conn)
      {
        ui->pushButtonConnect->setText("断开");
      }
      else
      {
           ui->pushButtonConnect->setText("连接");
      }
}


void MainWindow::on_pushButtonSend_clicked()
{
    QString  msg = ui->lineEditSend->text();

    //注意字符编码，需要保持一致
    QByteArray data = msg.toUtf8();
    //给服务端发送数据
     thread.send( data);
}
