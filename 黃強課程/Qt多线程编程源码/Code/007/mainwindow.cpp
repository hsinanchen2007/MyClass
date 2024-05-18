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


void MainWindow::on_startButton_clicked()
{
   t.start();
}

void MainWindow::on_forceButton_clicked()
{
    //强制终止线程执行，终止的地方不确定
    t.terminate();
}

void MainWindow::on_flagButton_clicked()
{
    //改变标记，让线程循环终止，从而结束线程
    t.flag =false;
}
