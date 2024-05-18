#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QColorDialog>
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

void MainWindow::on_change_clicked()
{
    //弹出颜色对话框，默认红色
   QColor  color=  QColorDialog::getColor(Qt::red,  this,  "我的颜色");

   if(color.isValid())//如果选择的颜色合法
   {
       ui->change->setStyleSheet(
           QString("background-color: rgb(%1,%2,%3);").arg(color.red()).arg(color.green()).arg(color.blue())  );

   }
   //否则，点了取消，返回非法颜色


   qDebug()<<color<<endl;

}
