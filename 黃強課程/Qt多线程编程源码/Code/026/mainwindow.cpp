#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QRunnable>
#include<QDebug>

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

//�����Գ�����
class  DoSomeThing1: public  QRunnable
{
 public:
    virtual void run()
    {
       qDebug()<<QStringLiteral("ִ�е�һ���£�");
    }
    ~DoSomeThing1()
    {
        qDebug()<<QStringLiteral("����DoSomeThing1��");
    }
};

class  DoSomeThing2: public  QRunnable
{
 public:
    virtual void run()
    {
       qDebug()<<QStringLiteral("ִ�еڶ����£�");
    }
    ~DoSomeThing2()
    {
        qDebug()<<QStringLiteral("����DoSomeThing2��");
    }
};


//ΪʲôҪ���QRunnable,��Ϊ�˶���һ�ֽӿ�
//�����п�ִ�е��£�������ѭ����ӿ�

void  Execute(QRunnable * r)
{
    //ִ��ĳ����ִ�ж���
    r->run();

    //�Ƿ�ִ��������ٴ˶���
    if(r->autoDelete())
    {
        delete  r;
    }
}

void MainWindow::on_pushButton_clicked()
{
    // ����ʵ����������
    // QRunnable  run;

    //�������������ʹ�ã���û�б�Ҫ����QRunnable
   // DoSomeThing1 do1;
   // do1.run();

    //������ʹ��Ӧ����͹�� ��̬����
    QRunnable * r =nullptr;

    //ĳ������
    r= new DoSomeThing1();
    qDebug()<<QStringLiteral("Ĭ���Ƿ��Զ�����:  %1").arg(r->autoDelete()   );
    r->setAutoDelete(false); //����ִ��������֮�󣬲������������


    //��һ��������ִ��
    // r = new DoSomeThing2();

    //ͬ���ĵ��ã�����ʵ�ֵĲ�ͬ��չ�ֲ�ͬ�Ľ��
    Execute(r);


}
