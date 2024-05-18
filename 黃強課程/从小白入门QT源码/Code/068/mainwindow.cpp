#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFontDialog>
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

void MainWindow::on_changeBtn_clicked()
{
    //打开一个字体选择对话框，成功ok为true，取消为false
     bool  ok =false;
     QFont  font = QFontDialog::getFont(&ok, QFont("Arial",20), this);

     if(ok){
         //设置按钮字体
         ui->changeBtn->setFont(font);
     }


     qDebug()<<font<<endl;

}
