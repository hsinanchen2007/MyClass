#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

  //设置前缀后缀
    ui->spinBox->setPrefix("这是");
    ui->spinBox->setSuffix("秒数");

    //设置范围
   ui->spinBox->setRange(0,10);

   //设置步长为2
   ui->spinBox->setSingleStep(2);

   //设置显示的进制
   ui->spinBox->setDisplayIntegerBase(10);

   //设置当前的值
   ui->spinBox->setValue(5);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    qDebug()<<"当前"<<arg1<<endl;
}
