#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置父窗口
    ww.setParent(this);

    //设置控件大小
    ww.setGeometry(150,50,500,500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

