#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置仪表盘的父窗口
    dw.setParent(this);

    //设置仪表盘的大小
    dw.setGeometry(150,50, 500,500);

    //设置仪表的当前值
    //dw.setValue(50);

    //设置定时器，100ms触发一次
    startTimer(100);

}

//定时器响应函数
void MainWindow::timerEvent(QTimerEvent *event)
{
    qDebug()<<" 定时器函数触发";
    int v= dw.getValue();

    if(v>300)v=0;

    dw.setValue(v+1);
}

MainWindow::~MainWindow()
{
    delete ui;
}



