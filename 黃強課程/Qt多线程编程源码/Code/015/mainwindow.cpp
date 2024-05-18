#include "mainwindow.h"
#include "ui_mainwindow.h"

//定义局部存储对象, 是个模板类,在某个线程设置的数据，只对该线程有效
//不同线程中设置的数据互不干扰
QThreadStorage< QString > ts;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //主线程
    //在当前线程存储局部数据
    ts.setLocalData("main");


    //启动线程
    MyThread *t = new MyThread();
    t->start();



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //获取当前线程的存储数据
    QString str=  ts.localData();
    qDebug()<<str<<QThread::currentThreadId();
}
