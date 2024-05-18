#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"mythread.h"

//全局变量
//int N=0;

//原子整型(只对整数有用)，线程安全的
QAtomicInteger<int>  N;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    N =0; //赋初始值

    //两个线程
    MyThread t1;
    MyThread t2;

    t1.start();
    t2.start();


    t1.wait();
    t2.wait();

    qDebug()<<QStringLiteral("N自增20万次之后结果是 ")<<N;

}
