#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //定义QThread类的对象
    t= new QThread();
    t->start();//启动线程

    //定义自定义的类， 继承自QObject类
    Worker *w = new Worker();
     // 把w移动到线程对象中
    w->moveToThread(t);

    //绑定信号和槽,发送startSig来执行线程函数Do
    connect(this, &MainWindow::startSig, w ,&Worker::Do);

    //绑定信号槽，发送mySig来更新UI
    connect(w, &Worker::mySig,  this  ,&MainWindow::updateNum);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   // 发送startSig来执行线程函数Do
    emit  startSig();
}

 void MainWindow::updateNum(QString num)
 {
          //更新UI
      ui->pushButton->setText(num);

 }
