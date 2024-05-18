#include "mainwindow.h"
#include "ui_mainwindow.h"

#pragma execution_character_set("utf-8")

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Qt 打印支持的驱动");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonPrint_clicked()
{
    //查看Qt框架为我们提供的数据库驱动程序
    qDebug()<<"Qt支持的数据库驱动"<< QSqlDatabase::drivers();

}
