#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStandardItemModel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //设置内容
       QStandardItemModel *model = new QStandardItemModel();
        model->appendRow(new QStandardItem("黄强老师"));
        model->appendRow(new QStandardItem("C++"));
        model->appendRow(new QStandardItem("Qt框架"));
        model->appendRow(new QStandardItem("JAVA"));
        model->appendRow(new QStandardItem("编程"));
       ui->listView->setModel(model);

       //启用交替色
       ui->listView->setAlternatingRowColors(true);

       ////////////////////////////////////////////////////////

       //设置内容
           ui->listWidget->addItem("黄强老师");
           ui->listWidget->addItem("C++");
           ui->listWidget->addItem("Qt框架");
           ui->listWidget->addItem("JAVA");
           ui->listWidget->addItem("编程");

           //启用交替色
           ui->listWidget->setAlternatingRowColors(true);



}

MainWindow::~MainWindow()
{
    delete ui;
}

