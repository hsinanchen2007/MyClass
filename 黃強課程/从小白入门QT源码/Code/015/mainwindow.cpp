#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "test.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //手动连接按钮的 信号  和  自己命名的槽函数
    connect(ui->pushButton,    SIGNAL(clicked(bool)),   this,    SLOT(my_clicked())   );

    //手动连接按钮的 信号  和  自己命名的槽函数
    Test  *t=new Test ;
    connect(ui->pushButton,    SIGNAL(clicked(bool)),   t,    SLOT(my_test_solt())   );

    //这两个 宏，会生成字符串，分别用"1"#a     "2"#a
    qDebug()<< SIGNAL(xxx)<< SLOT(yyy)<<endl;

}

MainWindow::~MainWindow()
{
    delete ui;
}

//槽(利用默认名字规则 on_对象名_信号名)
void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"on_pushButton_clicked"<<endl;
}

void MainWindow::on_pushButton_clicked(bool checked)
{
     qDebug()<<"on_pushButton_clicked"<<checked<<endl;
}

void MainWindow::on_pushButton_pressed()
{
     qDebug()<<"on_pushButton_pressed"<<endl;
}

void MainWindow::on_pushButton_released()
{
     qDebug()<<"on_pushButton_released"<<endl;
}


void MainWindow::my_clicked()
{
   qDebug()<<"自己命名的槽函数"<<endl;
}


void MainWindow::on_mybtn_clicked()
{

}



