#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("TCP客户端(多线程 方式二)");


    //步骤二
    m_thread.start();

    //步骤三，调用XXX.moveToThread将对象移动至线程中
    m_tcp.moveToThread(&m_thread);

    qDebug()<<"QThread对象的地址"<< &m_thread;



    //连接信号槽
    connect(this, &MainWindow::sigConnect , &m_tcp, &TcpSocket::slotConnect);
    connect(this, &MainWindow::sigSend , &m_tcp, &TcpSocket::slotSend);
    connect(this, &MainWindow::sigClose , &m_tcp, &TcpSocket::slotClose);

    //连接TcpSocket触发 MainWindow界面的信号
    connect( &m_tcp , &TcpSocket::sigPrint, this, &MainWindow::slotPrint);
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

        //去触发 线程中的TcpSocket对象的槽函数
        emit  sigConnect(ip,port);

    }
    else
    {
         //断开与服务器的连接
         emit  sigClose();
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
    emit sigSend(data);
}

//点击窗口关闭按钮的时候自动被调用
void MainWindow::closeEvent(QCloseEvent *event)
{
   //关闭套接字
    emit sigClose();

    //quit退出线程的消息循环
    m_thread.quit();

    //等待线程结束
    m_thread.wait();

    qDebug()<<"线程退出了！";

}

