#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //绑定线程的信号槽
    connect(&t, &QThread::started , this , &MainWindow::startSlot);
    connect(&t, &QThread::finished , this ,  &MainWindow::finishSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
      t.start();//开启线程,调用QThread::run

      qDebug()<<QStringLiteral("开始QThread对象！");

     // t.wait();//等待t线程执行结束

     qDebug()<<QStringLiteral("on_startButton_clicked");

}

void MainWindow::on_statusButton_clicked()
{
    qDebug()<<QStringLiteral("线程状态 ")<<t.isRunning();
}

void MainWindow::on_exitButton_clicked()
{
   // t.exit();//退出QThread类run方法中exec中的while循环

    t.quit();//本质就是调用exit(0)
}


void MainWindow::startSlot()
{
     qDebug()<<QStringLiteral("线程开始运行了 ");
}
void MainWindow::finishSlot()
{
     qDebug()<<QStringLiteral("线程结束了 ");
}
