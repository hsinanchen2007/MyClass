#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     t= new MyThread();
     connect(t, &MyThread::mySig , this , &MainWindow::updateNum );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    t->start();
}

void MainWindow::updateNum(QString num)
{
    //¸üÐÂUI
   ui->pushButton->setText(num);
}
