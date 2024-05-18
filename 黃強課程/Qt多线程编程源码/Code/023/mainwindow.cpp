#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"producerthread.h"
#include"consumerthread.h"


int  Space = 3;//�ֿ���ഢ��3����Ʒ

QMutex  mutex; //����������֤�ֿ������޸ĵ���ȷ��


//�ȴ�������wait���������߳����������Ѽ�⵽û����Ʒ֮��
//���� wakeone��������һ����wait�������������߳�
//wakeAll����ȫ�����������������߳�
QWaitCondition  goProducer;//ȥ������


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
    //3��������
    ProducerThread  p1("AAA");
    ProducerThread  p2("BBB");
    ProducerThread  p3("CCC");

    //1��������
    ConsumerThread  c1("DDD");

     p1.start();
     p2.start();
     p3.start();

     c1.start();

     p1.wait();

}
