#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置日期格式
   // ui->dateTimeEdit_2->setDisplayFormat("yyyy/MM/dd HH:mm:ss");
    //设置带日历
    //ui->dateTimeEdit_2->setCalendarPopup(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

