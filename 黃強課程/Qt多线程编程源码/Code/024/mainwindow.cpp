#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"producerthread.h"
#include"consumerthread.h"


int  Space = 3;//�ֿ���ഢ��3����Ʒ

QMutex  mutex; //����������֤�ֿ������޸ĵ���ȷ��


//�ȴ�������wait�����������߳�����������������һ����Ʒ֮��
//���� wakeone��������һ����wait�������������߳�
//wakeAll����ȫ�����������������߳�
QWaitCondition  goConsumer;//ȥ���Ѱ�


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
    //1��������
    ProducerThread  p1("DDD");

    //3��������
    ConsumerThread  c1("AAA");
    ConsumerThread  c2("BBB");
    ConsumerThread  c3("CCC");

    p1.start();

     c1.start();
     c2.start();
     c3.start();


     p1.wait();
}
