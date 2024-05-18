#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);  //运行子线程

    t= new MyThread();
    t->start();
    QThread::sleep(1);//确保run里面的 new Test已经执行

    //将main主线程作为发信号者的线程（sender 为mainwindow对象）
    //将 t子线程作为接收信号的线程(reciever为 test对象)

    //DirectConnection 本质是直接调用槽函数，槽函数在sender所在的线程内执行。
   // connect( this, &MainWindow::mySig,  t->test, &Test::MySlot,Qt::DirectConnection  );

    //QueuedConnection 通过事件循环调用槽函数，槽函数在receiver所在线程调用。
   //connect( this, &MainWindow::mySig,  t->test, &Test::MySlot,Qt::QueuedConnection  );

    //BlockingQueuedConnection  通过事件循环调用槽函数，槽函数在receiver所在线程调用，在槽函数调用完成之前将阻塞 sender所在的线程
   //connect( this, &MainWindow::mySig,  t->test, &Test::MySlot,Qt::BlockingQueuedConnection  );

    //AutoConnection   自动连接：（默认值）
   // 如果sender和receiver的在同一个线程，则等同于Qt::DirectConnection，否则等同于Qt :: QueuedConnection
   //connect( this, &MainWindow::mySig,  t->test, &Test::MySlot,Qt::AutoConnection  );
    //connect( this, &MainWindow::mySig,  t->test, &Test::MySlot);

    //UniqueConnection,和上面四个组合使用，防止多次绑定
    connect( this, &MainWindow::mySig,  t->test, &Test::MySlot, Qt::AutoConnection);
    connect( this, &MainWindow::mySig,  t->test, &Test::MySlot, (Qt::ConnectionType) (Qt::UniqueConnection | Qt::AutoConnection));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   //发送信号
    emit  mySig();

    qDebug()<<"on_pushButton_clicked";

}
