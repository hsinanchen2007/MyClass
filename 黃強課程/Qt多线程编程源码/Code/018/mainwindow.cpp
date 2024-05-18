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
     //定义两个售票员
     MyThread t1("AAA");
     MyThread t2("BBB");

     //同时开始卖票
     t1.start();
     t2.start();

     //等待两个线程执行完毕
     t1.wait();
     t2.wait();

}
