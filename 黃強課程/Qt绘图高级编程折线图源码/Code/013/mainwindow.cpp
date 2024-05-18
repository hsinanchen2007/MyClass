#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置仪表盘的父窗口
    dw.setParent(this);

    //设置仪表盘的大小
    dw.setGeometry(150,50, 500,500);

}

MainWindow::~MainWindow()
{
    delete ui;
}

