#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置滚动条的方向
    ui->horizontalScrollBar->setOrientation( Qt::Horizontal );

    //设置滚动条的范围
    ui->horizontalScrollBar->setRange(0,100);

    //设置单步长
    ui->horizontalScrollBar->setSingleStep(10);

    //设置翻页步长
    ui->horizontalScrollBar->setPageStep(30);

    //设置当前位置
    //ui->horizontalScrollBar->setValue(50);//槽
    ui->horizontalScrollBar->setSliderPosition(50);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
    qDebug()<<"滚动"<<value<<endl;

}
