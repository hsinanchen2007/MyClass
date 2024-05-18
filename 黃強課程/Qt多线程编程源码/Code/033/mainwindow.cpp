#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtConcurrent>
#include<QThread>
#include<QDebug>
#include<QList>

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

void Add(int &a) //������
{
    qDebug()<<QStringLiteral("��ʼ����")<<a<<QThread::currentThread();
    QThread::sleep(1);//ģ���ʱ
    a+=1;
    qDebug()<<QStringLiteral("��������");
}


int  Add2(int  a) //��������
{
    qDebug()<<QStringLiteral("��ʼ����")<<a<<QThread::currentThread();
    QThread::msleep(2);//ģ���ʱ2����
    a+=1;
    qDebug()<<QStringLiteral("��������");
    return a;
}

void  Sum(int & r , int e)
{
    qDebug()<<QStringLiteral("��ʼSum")<<r<<"   "<<e<<QThread::currentThread();
    QThread::msleep(1);//ģ���ʱ1����
    r+=e;
    qDebug()<<QStringLiteral("����Sum����");
}


QFuture<int>  f ;

void MainWindow::on_mappedReducedButton_clicked()
{
    //������QVector  QList  ,Ҫ�����������begin��end
    QList<int> list;
    for (int i=0;i<10000;++i) {
        list.append(0);
    }


    //�������е�ÿ��Ԫ��ִ��Add���㡢���޸�ԭ������
    //���Ƿ���һ������������޸ĺ�Ľ�������һ�������������Sum����
    f =  QtConcurrent::mappedReduced(list ,Add2,Sum );
  // f.waitForFinished();//�ȴ�ִ�н���
  // qDebug()<<f.result()<<f.results() ;
}


void MainWindow::on_stateButton_clicked()
{
   qDebug()<<QStringLiteral("����״̬�� �ѿ�ʼ%1 ȡ��%2 ��ͣ%3 ����%4 ���%5")
             .arg( f.isStarted()).arg(f.isCanceled()).arg(f.isPaused())
             .arg(f.isRunning()).arg(f.isFinished());

   if( f.isFinished())
   {
        qDebug()<<f.results() ;
   }
}

void MainWindow::on_cancelButton_clicked()
{
    qDebug()<<QStringLiteral("ȡ����");
    f.cancel();
}

void MainWindow::on_pauseButton_clicked()
{
    qDebug()<<QStringLiteral("��ͣ��");
    f.pause();
}

void MainWindow::on_resumeButton_clicked()
{
    qDebug()<<QStringLiteral("�ָ���");
    f.resume();
}
