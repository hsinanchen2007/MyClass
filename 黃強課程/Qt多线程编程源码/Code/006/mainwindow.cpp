#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mythread.h"

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
    /*
    //让一个线程执行5秒
    MyThread  t1("AAA", 5);
    t1.start();

    //wait不带参数代表永不超时
    bool  ret=t1.wait(10000);//此处阻塞主线程，等待t1线程执行完毕之后才解除阻塞
                           //或者3秒超时也停止阻塞

    if(ret)
    {
        qDebug()<<QStringLiteral("线程结束后wait返回!");
    }
    else
    {
         qDebug()<<QStringLiteral("wait超时返回!");
    }


    */

    MyThread  t1("AAA", 3);
    t1.start();

    MyThread  t2("BBB", 2);
    t2.start();

    MyThread  t3("CCC", 3);
    t3.start();


    t1.wait(); //等待t1执行完成
    t2.wait();//等待t2执行完成
    t3.wait();//等待t3执行完成

    qDebug()<<"on_pushButton_clicked()";

}
