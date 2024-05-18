#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mywidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //定义窗口类
     MyWidget  * my= new MyWidget(this);
     //设置窗口位置
     my->setGeometry(100,100,200,200);
    //设置样式表
     my->setStyleSheet("border:2px solid  black;"
                                      "background:red;");

}

MainWindow::~MainWindow()
{
    delete ui;
}

