#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("TCP服务端（使用线程池）");

    //方便在TcpServer类中获取MainWindow类的对象
    m_tcpServer.setParent(this);
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
            //在ip与端口监听客户端的连接,在主线程
            bool  ret= m_tcpServer.listen(addr, port);
            if(ret)
            {
                ui->plainTextEditRecv->appendPlainText("监听成功！");
                ui->pushButtonStart->setText("停止");

            }
            else
            {
                ui->plainTextEditRecv->appendPlainText("监听失败！");
            }
    }
    else
    {

           //关闭TCP的监听
           m_tcpServer.close();
           ui->plainTextEditRecv->appendPlainText("服务器已停止!");
           ui->pushButtonStart->setText("启动");
    }


}

void MainWindow::on_pushButtonSend_clicked()
{
    QString  msg = ui->lineEditSend->text();

    //注意字符编码，需要保持一致
    QByteArray data = msg.toUtf8();

    m_tcpServer.send(data);
}

void  MainWindow::slotPrint(QString info,  bool conn)
{
      ui->plainTextEditRecv->appendPlainText(info);
}
