#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置父窗口
    ww.setParent(this);

    //设置控件大小
    ww.setGeometry(150,50,500,500);

    //设置仪表的半径参数
    ww.setRadius(180 , 50 , 110 ,40 ,60);

    //设置范围
    ww.setRange(100,200);

    //设置小数位
    ww.setPrecise(2);

    //设置当前指针值
    ww.setValue(160);


    //开启定时器,每100ms触发一次
    startTimer(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    qDebug()<<"定时器触发！";

    double v = ww.getValue();
    v+=1;

    if(v>200)v= 100;

    ww.setValue(v);

}

