#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"test.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

  //将Test类的  自定义信号 与   MainWindow类的  my_solt 槽连接
    connect (&t ,  SIGNAL(teacherHuang(int,QString)),this,SLOT(my_solt(int , QString)));

}


void MainWindow::my_solt(int a, QString b)
{
       qDebug()<<"自定的槽"<<a<<b<<endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //发射信号
    t.shoot();
}
