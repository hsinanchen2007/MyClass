#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置状态栏的颜色
    ui->statusBar->setStyleSheet("background-color:green;color:white");

    //设置显示信息3秒
   // statusBar()->showMessage("这是临时信息",3000);

    //在状态栏左侧添加控件
    ui->statusBar->addWidget(new QLabel("文本控件"));
    ui->statusBar->addWidget(new QPushButton("按钮控件"));

    //在状态栏右侧加一个编辑框
    QLineEdit  *edit=new QLineEdit("编辑控件");
    edit->setFixedSize(100,50);
    ui->statusBar->addPermanentWidget(edit);
      //在状态栏右侧插入一个编辑框
   ui->statusBar->insertPermanentWidget(2, new QPushButton("按钮控件"));

    //去除手柄，则可以完全靠右边
    ui->statusBar->setSizeGripEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}
