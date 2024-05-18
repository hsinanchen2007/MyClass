#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //循环100万次，然后每次都设置按钮的文本为当前次数
   for(int i=0;i<=1000000;++i)
   {
       ui->pushButton->setText( QString::number(i) );
   }
}
