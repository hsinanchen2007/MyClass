#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"producerthread.h"
#include"consumerthread.h"


int  Space = 3;//仓库最多储存3个商品

QMutex  mutex; //互斥锁，保证仓库数量修改的正确性


//等待条件，wait让生产者线程阻塞，消费检测到没有商品之后，
//调用 wakeone唤醒其中一个被wait阻塞的生产者线程
//wakeAll唤醒全部被阻塞的生产者线程
QWaitCondition  goProducer;//去生产吧


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_p3c1Button_clicked()
{
    //3个生产者
    ProducerThread  p1("AAA");
    ProducerThread  p2("BBB");
    ProducerThread  p3("CCC");

    //1个消费者
    ConsumerThread  c1("DDD");

     p1.start();
     p2.start();
     p3.start();

     c1.start();

     p1.wait();

}
