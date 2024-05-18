#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //小部件上已经堆叠了两个
   QWidget *  w1= ui->stackedWidget->widget(0);
   w1->setStyleSheet("background-color:red");

   QWidget *  w2= ui->stackedWidget->widget(1);
   w2->setStyleSheet("background-color:green");



   //再添加第3个小部件
   QWidget  *w3= new QWidget();
   w3->setStyleSheet("background-color:blue");

   //添加到 堆叠窗口
   ui->stackedWidget->addWidget(w3);

   //获取窗口的索引
   int  index = ui->stackedWidget->indexOf(w3);

   qDebug("索引%d",index);

   // 设置当前显示的窗口的索引
   ui->stackedWidget->setCurrentIndex(2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int index = ui->stackedWidget->currentIndex();
    int count = ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex( ++index %count);
}
