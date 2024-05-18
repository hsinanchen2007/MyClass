#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //添加一些选项
    ui->listWidget->addItem("编程");
    ui->listWidget->addItem(new QListWidgetItem( QIcon(":/new/prefix1/imgs/music.png"),"音乐" ) );

    //插入选项
    QListWidgetItem *item = new QListWidgetItem( QIcon(":/new/prefix1/imgs/dance.png"),"跳舞" );
    ui->listWidget->insertItem(0,item);

    //设置图标 大小
   ui->listWidget->setIconSize(QSize(60,60));

   //一次添加多个项
   ui->listWidget->addItems(  {"下棋","跑步" });

   //设置当前选择
   ui->listWidget->setCurrentItem(item);

   //设置多选
   ui->listWidget->setSelectionMode(QListWidget::MultiSelection);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
   // qDebug()<<"点击"<<item->text()<<endl;
}

void MainWindow::on_listWidget_itemSelectionChanged()
{
    QList<QListWidgetItem*> list= ui->listWidget->selectedItems();

    foreach(QListWidgetItem * it, list)
    {
        qDebug()<<it->text()<<endl;
    }
       qDebug()<<"----------------------------------------------"<<endl;
}
