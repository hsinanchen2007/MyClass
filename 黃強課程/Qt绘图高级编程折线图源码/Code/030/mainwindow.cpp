#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置控件的父窗口
    mc.setParent(this);

    //设置控件的位置大小
    mc.setGeometry(100,100, 600,300);

    //设置轴文本
    mc.SetAxisText("x轴", "y轴");

    //设置轴的范围
    mc.SetRange(0,100,1000,2000);

    //加入一些点
    mc.AppendPoint(QPointF( 1,1200));
    mc.AppendPoint(QPointF( 30,1700));
    mc.AppendPoint(QPointF( 40,1500));
    mc.AppendPoint(QPointF( 70,1800));
    mc.AppendPoint(QPointF( 100,1400));


}

MainWindow::~MainWindow()
{
    delete ui;
}

