#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMetaEnum>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("UDP服务端（多线程、方式一）");


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

    //群发送数据
    thread->send( data);
}


void MainWindow::slotPrint(QString info ,bool bind)
{
     ui->plainTextEditRecv->appendPlainText(info);

     if(bind)
     {
         ui->pushButtonBind->setText("停止");
     }
     else
     {
           ui->pushButtonBind->setText("绑定");
     }
}

void MainWindow::slotFinished()
{
    //  ui->plainTextEditRecv->appendPlainText("线程结束啦！");
    qDebug()<<"线程结束啦！";
      ui->pushButtonBind->setText("绑定");
}


void MainWindow::closeEvent(QCloseEvent *event)
{
      qDebug()<<"窗口关闭按钮被点击！！！";

      //停止线程
      thread->close();
      thread->wait();//等待线程结束
}



void MainWindow::on_pushButtonBind_clicked()
{
   QString  text = ui->pushButtonBind->text();
   if(text == "绑定")
   {
       QString ip = ui->lineEditIP->text();
       quint16  port  = ui->lineEditPort->text().toUInt();

       thread = new RecvThread(ip,port);

       //开启线程
       thread->start();

       //连接信号槽
       connect( thread, &RecvThread::sigPrint, this ,&MainWindow::slotPrint);

       connect( thread,&QThread::finished, this , &MainWindow::slotFinished);

   }
   else
   {
       //关闭线程
       thread->close();
   }

}
