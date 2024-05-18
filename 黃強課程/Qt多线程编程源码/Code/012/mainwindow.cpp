#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //��һ��������QThread��Ķ���
    QThread  *t = new QThread();
    t->start();//�����߳�

    //�ڶ���,����һ���࣬�̳���QObject��Ȼ����һ���ۺ�����д��Ҫִ�еĴ���
    Worker * w = new Worker();


    //������,���Զ�������� moveToThread�ƶ����̶߳�������
    w->moveToThread(t);

    //���Ĳ������ź���ۣ�ͨ���źŴ���Ҫִ�еĺ���
    connect( this, &MainWindow::mySig , w , &Worker::Do);

    //���԰󶨶��
    connect( this, &MainWindow::mySig , w , &Worker::DoOther);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //�����źţ�ִ��Worker�ĺ���
   emit mySig();
}
