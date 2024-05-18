#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //连接信号和槽
    connect(&t, &MyThread::started,this , &MainWindow::ThreadStarted  );
    connect(&t, &MyThread::finished,this , &MainWindow::ThreadFinished );


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startBtn_clicked()
{
   //第三步,开始执行线程
    t.start();

}

void MainWindow::on_termiateBtn_clicked()
{
   //终止线程，不推荐使用，因为会强行终止代码，导致一些资源无法释放
    t.terminate();
}

void MainWindow::on_statusBtn_clicked()
{
   //线程状态
   qDebug()<<"isRunning "<<t.isRunning()<<"   isFinished"<<t.isFinished();
}


void  MainWindow::ThreadStarted()
{
     qDebug()<<"ThreadStarted.....";
}
void  MainWindow::ThreadFinished()
{
    qDebug()<<"ThreadFinished....";
}
