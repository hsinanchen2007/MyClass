#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    {
            QStandardItemModel *model = new QStandardItemModel();//创建模型指定父类

            QStringList header;
            header<<QString("编程")<<QString("熟练度");
            model->setHorizontalHeaderLabels(header);

            model->setItem(0,0,new QStandardItem("C++"));
            model->setItem(0,1,new QStandardItem("精通"));

            model->setItem(1,0,new QStandardItem("C语言"));
            model->setItem(1,1,new QStandardItem("熟悉"));

            model->setItem(2,0,new QStandardItem("go语言"));
            model->setItem(2,1,new QStandardItem("了解"));

            model->setItem(3,0 ,new QStandardItem("HTML"));
            model->setItem(3,1 ,new QStandardItem("精通"));


            ui->tableView->setModel(model);
            //启用隔行变色
            ui->tableView->setAlternatingRowColors(true);
        }


    {
           QStringList header;
           header<<QString("编程")<<QString("熟练度");

           ui->tableWidget->setColumnCount(2);
           ui->tableWidget->setRowCount(4);

           ui->tableWidget->setHorizontalHeaderLabels(header);

             ui->tableWidget->setItem(0,0,new QTableWidgetItem("C++"));
             ui->tableWidget->setItem(0,1,new QTableWidgetItem("精通"));

             ui->tableWidget->setItem(1,0,new QTableWidgetItem("C语言"));
             ui->tableWidget->setItem(1,1,new QTableWidgetItem("熟悉"));

             ui->tableWidget->setItem(2,0,new QTableWidgetItem("go语言"));
             ui->tableWidget->setItem(2,1,new QTableWidgetItem("了解"));

             ui->tableWidget->setItem(3,0 ,new QTableWidgetItem("HTML"));
             ui->tableWidget->setItem(3,1 ,new QTableWidgetItem("精通"));

           //启用隔行变色
           ui->tableWidget->setAlternatingRowColors(true);
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}

