#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置日期范围
    ui->calendarWidget->setMinimumDate(QDate(2000,1,1));
    ui->calendarWidget->setMaximumDate(QDate(2003,1,1));

    //设置当前选择的日期
    ui->calendarWidget->setSelectedDate( QDate(2001,2,3));

    //设置显示网格线
    ui->calendarWidget->setGridVisible(true);

    //设置头部导航隐藏
   // ui->calendarWidget->setNavigationBarVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calendarWidget_selectionChanged()
{
    qDebug()<<ui->calendarWidget->selectedDate()<<endl;
}
