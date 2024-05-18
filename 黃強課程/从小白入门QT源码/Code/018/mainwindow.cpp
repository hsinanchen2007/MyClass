#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //将单选按钮分组
    QButtonGroup *g1= new QButtonGroup;
    g1->addButton(ui->btnMusic,111); //添加按钮并设置id
    g1->addButton(ui->btnCode,222);

   //为QButtonGroup的buttonClicked(int)信号连接槽
    connect(g1, SIGNAL(buttonClicked(int)),this,SLOT(mybuttonClicked(int)));

    //为QButtonGroup的buttonClicked(QAbstractButton*)信号连接槽
     connect(g1, SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(mybuttonClicked2(QAbstractButton*)));

}

 void  MainWindow::mybuttonClicked(int id)
 {
     qDebug()<<"按钮选中"<<id<<endl;
 }

 void  MainWindow::mybuttonClicked2(QAbstractButton* btn)
 {
     qDebug()<<"按钮选中"<<btn->text()<<endl;
 }


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_male_clicked()
{
    qDebug()<<"男性选中"<<endl;
}



void MainWindow::on_female_clicked()
{
    qDebug()<<"女性选中"<<endl;
}
