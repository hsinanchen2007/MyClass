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

//派生自抽象类
class  DoSomeThing1: public  QRunnable
{
 public:
    virtual void run()
    {
       qDebug()<<QStringLiteral("执行第一件事！");
    }
    ~DoSomeThing1()
    {
        qDebug()<<QStringLiteral("销毁DoSomeThing1！");
    }
};

class  DoSomeThing2: public  QRunnable
{
 public:
    virtual void run()
    {
       qDebug()<<QStringLiteral("执行第二件事！");
    }
    ~DoSomeThing2()
    {
        qDebug()<<QStringLiteral("销毁DoSomeThing2！");
    }
};


//为什么要设计QRunnable,是为了定义一种接口
//让所有可执行的事，都能遵循这个接口

void  Execute(QRunnable * r)
{
    //执行某个可执行对象
    r->run();

    //是否执行完后销毁此对象
    if(r->autoDelete())
    {
        delete  r;
    }
}

void MainWindow::on_pushButton_clicked()
{
    // 不能实例化抽象类
    // QRunnable  run;

    //如果是这样来简单使用，则没有必要定义QRunnable
   // DoSomeThing1 do1;
   // do1.run();

    //真正的使用应该是凸显 多态特性
    QRunnable * r =nullptr;

    //某个任务
    r= new DoSomeThing1();
    qDebug()<<QStringLiteral("默认是否自动销毁:  %1").arg(r->autoDelete()   );
    r->setAutoDelete(false); //设置执行完任务之后，不销毁这个对象


    //换一种任务来执行
    // r = new DoSomeThing2();

    //同样的调用，根据实现的不同，展现不同的结果
    Execute(r);


}
