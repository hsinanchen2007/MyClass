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

    //设置仪表的半径参数
    ww.setRadius(180 , 50 , 110 ,40 ,60);

    //设置范围
    ww.setRange(100,200);

    //设置小数位
    ww.setPrecise(2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

