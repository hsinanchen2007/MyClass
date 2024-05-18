#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //使用时钟
    ui->AnalogClock->setTime(QTime::currentTime());

    //旋钮
    ui->Knob->setScale( 10,50);
    ui->Knob->setValue(30);

    //指南针
       ui->Compass->setNeedle( new QwtCompassMagnetNeedle(
           QwtCompassMagnetNeedle::TriangleStyle, Qt::white, Qt::red ) );
       ui->Compass->setValue( 45);

       //温度计
       ui->Thermo->setScale(0,50); //设置刻度范围
       ui->Thermo->setFillBrush(Qt::green); //管道液体颜色
       ui->Thermo->setAlarmEnabled(true); //阈值报警
       ui->Thermo->setAlarmBrush(Qt::red);// 报警颜色
       ui->Thermo->setAlarmLevel(30); //阈值
       ui->Thermo->setValue(36);//当前值


}

MainWindow::~MainWindow()
{
    delete ui;
}

