#include "mainwindow.h"
#include "ui_mainwindow.h"

//����ֲ��洢����, �Ǹ�ģ����,��ĳ���߳����õ����ݣ�ֻ�Ը��߳���Ч
//��ͬ�߳������õ����ݻ�������
QThreadStorage< QString > ts;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //���߳�
    //�ڵ�ǰ�̴߳洢�ֲ�����
    ts.setLocalData("main");


    //�����߳�
    MyThread *t = new MyThread();
    t->start();



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //��ȡ��ǰ�̵߳Ĵ洢����
    QString str=  ts.localData();
    qDebug()<<str<<QThread::currentThreadId();
}
