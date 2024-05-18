#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCode_stateChanged(int arg1)
{
    //3态的复选框：    0  未选中    1 部分选中    2全部选中
    qDebug()<<"编程按钮"<<arg1<<endl;
}

void MainWindow::on_btnCode_clicked(bool checked)
{
    //3态的复选框：    0   false         （ 1 部分选中    2全部选中   true）
      qDebug()<<"编程选中"<<checked<<endl;
}

void MainWindow::on_btnMusic_stateChanged(int arg1)
{
    //2态的复选框：    0  未选中       2全部选中
    qDebug()<<"音乐按钮"<<arg1<<endl;
}

void MainWindow::on_btnMusic_clicked(bool checked)
{
      qDebug()<<"音乐选中"<<checked<<endl;
}



void MainWindow::on_btnMusic_toggled(bool checked)
{
      qDebug()<<"音乐toggled"<<checked<<endl;
}
