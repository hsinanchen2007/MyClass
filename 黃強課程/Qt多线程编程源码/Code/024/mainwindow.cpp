#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"producerthread.h"
#include"consumerthread.h"


int  Space = 3;//仓库最多储存3个商品

QMutex  mutex; //互斥锁，保证仓库数量修改的正确性


//等待条件，wait让消费者者线程阻塞，生产者生产一个商品之后，
//调用 wakeone唤醒其中一个被wait阻塞的消费者线程
//wakeAll唤醒全部被阻塞的消费者线程
QWaitCondition  goConsumer;//去消费吧


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


void MainWindow::on_p1c3Button_clicked()
{
    //1个生产者
    ProducerThread  p1("DDD");

    //3个消费者
    ConsumerThread  c1("AAA");
    ConsumerThread  c2("BBB");
    ConsumerThread  c3("CCC");

    p1.start();

     c1.start();
     c2.start();
     c3.start();


     p1.wait();
}
