#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置方向
    ui->horizontalSlider->setOrientation(Qt::Horizontal);

    //设置范围
    ui->horizontalSlider->setRange(0,100);

    //设置单步长
    ui->horizontalSlider->setSingleStep(1);

    //设置页长
    ui->horizontalSlider->setPageStep(30);

    //设置当前位置
    ui->horizontalSlider->setValue(50);

    //设置刻度
    ui->horizontalSlider->setTickPosition(QSlider::TicksAbove);

    // 设置刻度间隔
    ui->horizontalSlider->setTickInterval(10);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
     qDebug()<<"当前位置"<<value<<endl;
}
