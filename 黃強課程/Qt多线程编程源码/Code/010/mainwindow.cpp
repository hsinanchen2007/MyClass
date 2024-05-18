#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mythread.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    t= new MyThread();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
    t->start();
}

void MainWindow::on_exitButton_clicked()
{
    //退出事件循环
    t->quit();
}
