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

MyTask * t5;

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

        if(i==5) t5=t;
    }

     qDebug()<<QStringLiteral("��������!");
}




void MainWindow::on_tryStartButton_clicked()
{
    MyTask * t = new MyTask(QStringLiteral("����%1").arg(10) );
     t->setAutoDelete(true);//����Ϊִ�����֮������

    //����ִ��һ���������û�п����̣߳����񲻻�ִ�У����ҷ���false
    //����ִ�з���true
   bool  ret=  pool.tryStart(t);
   qDebug()<<QStringLiteral("����ִ��")<<ret;
}

void MainWindow::on_tryTakeButton_clicked()
{
    //ֻ���Ƴ�����������ʧ�ܷ���false
    bool  ret= pool.tryTake(t5);
    qDebug()<<QStringLiteral("�����Ƴ�")<<ret;
}

void MainWindow::on_clearButton_clicked()
{
    //�����������������
    pool.clear();
     qDebug()<<QStringLiteral("�����������������");
}
