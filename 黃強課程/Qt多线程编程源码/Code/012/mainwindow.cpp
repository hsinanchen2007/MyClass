#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //第一步，定义QThread类的对象
    QThread  *t = new QThread();
    t->start();//启动线程

    //第二步,定义一个类，继承自QObject，然后定义一个槽函数，写入要执行的代码
    Worker * w = new Worker();


    //第三步,将自定义类调用 moveToThread移动到线程对象里面
    w->moveToThread(t);

    //第四步，绑定信号与槽，通过信号触发要执行的函数
    connect( this, &MainWindow::mySig , w , &Worker::Do);

    //可以绑定多个
    connect( this, &MainWindow::mySig , w , &Worker::DoOther);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //发送信号，执行Worker的函数
   emit mySig();
}
