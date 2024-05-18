#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置范围
    ui->dial->setRange(0,100);

    //设置 显示刻度
    ui->dial->setNotchesVisible(true);

    //设置长刻度的步长( 显示用的)
    ui->dial->setPageStep(20);

    //设置单步长( 显示用的)
    ui->dial->setSingleStep(10);

    //设置当前的值
    ui->dial->setValue(90);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dial_valueChanged(int value)
{
    qDebug()<<"当前刻度"<<ui->dial->value()<<endl;
}
