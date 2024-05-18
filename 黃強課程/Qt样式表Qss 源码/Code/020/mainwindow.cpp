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

        model->setItem(0,0,new QStandardItem("后端"));
        model->item(0,0)->setChild(0,0,new QStandardItem("C++"));
        model->item(0,0)->setChild(0,1,new QStandardItem("精通"));

        model->item(0,0)->setChild(1,0,new QStandardItem("C语言"));
        model->item(0,0)->setChild(1,1,new QStandardItem("熟悉"));

        model->item(0,0)->setChild(2,0,new QStandardItem("go语言"));
        model->item(0,0)->setChild(2,1,new QStandardItem("了解"));

        model->setItem(1,0,new QStandardItem("前端"));
        model->item(1,0)->setChild(0,0,new QStandardItem("HTML"));
        model->item(1,0)->setChild(0,1,new QStandardItem("精通"));

        model->item(1,0)->setChild(1,0,new QStandardItem("JS"));
        model->item(1,0)->setChild(1,1,new QStandardItem("了解"));

        ui->treeView->setModel(model);
        //启用隔行变色
        ui->treeView->setAlternatingRowColors(true);
        //展开
        ui->treeView->expandAll();
    }



    {
           QStringList header;
           header<<QString("编程")<<QString("熟练度");
           ui->treeWidget->setHeaderLabels(header);
           ui->treeWidget->setColumnCount(2);

           QTreeWidgetItem *item0 =new QTreeWidgetItem(  ui->treeWidget,QStringList()<<("后端"));
           new QTreeWidgetItem(  item0, QStringList()<<"C++"<<"精通");
           new QTreeWidgetItem(  item0, QStringList()<<"C语言"<<"熟悉");
           new QTreeWidgetItem(  item0, QStringList()<<"go语言"<<"了解");

           QTreeWidgetItem *item1 =new QTreeWidgetItem(  ui->treeWidget,QStringList()<<("前端"));
           new QTreeWidgetItem(  item1, QStringList()<<"HTML"<<"精通");
           new QTreeWidgetItem(  item1, QStringList()<<"JS"<<"了解");

           //启用隔行变色
           ui->treeWidget->setAlternatingRowColors(true);
           //展开
           ui->treeWidget->expandAll();
       }


}

MainWindow::~MainWindow()
{
    delete ui;
}

