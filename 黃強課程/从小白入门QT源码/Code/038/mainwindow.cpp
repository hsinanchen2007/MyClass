#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置显示位数
    ui->lcdNumber->setDigitCount(6);

    //设置显示的数字,如果超过就 不显示
   // ui->lcdNumber->display(123456);
    //显示小数，小数点占用一位
    // ui->lcdNumber->display(123.454); 
    //显示字符串, 从右侧开始，超过左侧会截断
    //  ui->lcdNumber->display("123.4567");



   //设置显示进制，仅对整数有效
    ui->lcdNumber->display(6666666);
    // ui->lcdNumber->setMode(QLCDNumber::Bin);//二进制



      //设置样式表
      ui->lcdNumber->setStyleSheet(QString(
                                       "color: rgb(255, 0, 0);"
                                       "background-color: rgb(85, 255, 0);"
                                       ));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lcdNumber_overflow()
{
    qDebug()<<"溢出"<<endl;
}
