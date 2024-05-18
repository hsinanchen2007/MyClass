#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QRunnable>
#include<QDebug>
#include<QThread>

//��ִ�е�����
class  MyTask:public QRunnable
{
public:
    MyTask(QString name)
    {
        this->name= name;
    }
    virtual void run()
    {
            qDebug()<<name<<QStringLiteral("��ʼִ��")<<QThread::currentThread();
            QThread::sleep(10);
            qDebug()<<name<<QStringLiteral("����ִ��!");
    }
    ~MyTask( )
    {
        qDebug()<<name<<QStringLiteral("������!");
    }
private:
    QString name;

};



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

void MainWindow::on_activeThreadNumButton_clicked()
{
     qDebug()<<QStringLiteral("��߳���!")<<pool.activeThreadCount();
}


void MainWindow::on_startButton_clicked()
{
   //�����̳߳������߳�����
    pool.setMaxThreadCount(3);

    for (int i=1;i<=5;++i)
    {
        //����һЩ����Ĭ�ϻᱻ�̳߳��Զ����٣�
        MyTask * t = new MyTask(QStringLiteral("����%1").arg(i) );
        t->setAutoDelete(false);//��������ִ����Ϻ󲻱�����
        //�ŵ��̳߳���ȥִ��
        pool.start(t);
    }

     qDebug()<<QStringLiteral("��������!");
}



void MainWindow::on_prioityButton_clicked()
{
    //�����̳߳������߳�����
     pool.setMaxThreadCount(3);

     for (int i=1;i<=10;++i)
     {
         //����һЩ����Ĭ�ϻᱻ�̳߳��Զ����٣�
         MyTask * t = new MyTask(QStringLiteral("����%1").arg(i) );
         t->setAutoDelete(false);//��������ִ����Ϻ󲻱�����
         //�ŵ��̳߳���ȥִ��
         pool.start(t, i );//�����ȼ�
     }

      qDebug()<<QStringLiteral("��������!");
}

void MainWindow::on_waitButton_clicked()
{
    //�����̳߳������߳�����
     pool.setMaxThreadCount(3);

     for (int i=1;i<=5;++i)
     {
         //����һЩ����Ĭ�ϻᱻ�̳߳��Զ����٣�
         MyTask * t = new MyTask(QStringLiteral("����%1").arg(i) );
         t->setAutoDelete(false);//��������ִ����Ϻ󲻱�����
         //�ŵ��̳߳���ȥִ��
         pool.start(t, i );//�����ȼ�
     }

     //�ȴ��̳߳��е���������ִ�����֮��ż������£����������
     //����-1 ������Զ����ʱ��һֱ�ȴ�
      pool.waitForDone(  -1 );
      //����ָ����ʱʱ�䣬ֻ�ȴ�3s
     // pool.waitForDone(  3000 );

      qDebug()<<QStringLiteral("��������!");
}
