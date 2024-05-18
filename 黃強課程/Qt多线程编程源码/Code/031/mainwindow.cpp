#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QThread>

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


int  fun()
{
    qDebug()<<QStringLiteral("����0��ʼ")<<QThread::currentThread();
    QThread::sleep(10);//ģ���ʱ
    qDebug()<<QStringLiteral("����0����");

    return 0;
}


int  fun1(int a1)
{
   qDebug()<<QStringLiteral("����%1��ʼ").arg(a1)<<QThread::currentThread();
   QThread::sleep(10);//ģ���ʱ
   qDebug()<<QStringLiteral("����%1����").arg(a1);
   return  a1;
}


int  fun2(int a1,QString a2)
{
   qDebug()<<QStringLiteral("����%1��ʼ").arg(a1)<<a2<<QThread::currentThread();
   QThread::sleep(10);//ģ���ʱ
   qDebug()<<QStringLiteral("����%1����").arg(a1);
   return  a1;
}

int  fun5(int a1,QString a2,float a3,char a4,short a5)
{
   qDebug()<<QStringLiteral("����%1��ʼ").arg(a1)<<a2<<a3<<QThread::currentThread();
   QThread::sleep(10);//ģ���ʱ
   qDebug()<<QStringLiteral("����%1����").arg(a1);
   return  a1;
}


//�º���
class  Functor1
{
public:
    int  operator()(int a1)
     {
          qDebug()<<QStringLiteral("����%1��ʼ").arg(a1)<<QThread::currentThread();
          QThread::sleep(10);//ģ���ʱ
          qDebug()<<QStringLiteral("����%1����").arg(a1);
          return  a1;
     }
};

//��������
struct  FunctionObject1
{
    typedef  int result_type;
     result_type  operator()(int a1)
     {
          qDebug()<<QStringLiteral("����%1��ʼ").arg(a1)<<QThread::currentThread();
          QThread::sleep(a1);//ģ���ʱ
          qDebug()<<QStringLiteral("����%1����").arg(a1);
          return  a1;
     }
};

QFuture<int> f8;

void MainWindow::on_runButton_clicked()
{
    /*
    QFuture<T> run(T (*functionPointer)())
    //����ָ��Ϊ����
    */
    QtConcurrent::run( fun);

    /*
    QFuture<T> run(T (*functionPointer)(Param1), const Arg1 &arg1)
    */
   QtConcurrent::run( fun1, 1);

   /*
QFuture<T> run(T (*functionPointer)(Param1, Param2), const Arg1 &arg1, const Arg2 &arg2)
*/
   QtConcurrent::run( fun2, 2 ,QString("hello"));

  /*
QFuture<T> run(T (*functionPointer)(Param1, Param2, Param3, Param4, Param5), const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5)
*/
   QtConcurrent::run( fun5, 5 ,QString("hello"),0.12f, 'A',55);

   /*
template <typename Functor, typename Arg1>
auto run(Functor functor, const Arg1 &arg1)
*/
    QtConcurrent::run( Functor1(), 6);

    /*
template <typename FunctionObject, typename Arg1>
QFuture<typename FunctionObject::result_type> run(FunctionObject functionObject, const Arg1 &arg1)
*/
      QtConcurrent::run( FunctionObject1(), 7);


      /*
template <typename FunctionObject, typename Arg1>
QFuture<typename FunctionObject::result_type> run(QThreadPool *pool, FunctionObject functionObject, const Arg1 &arg1)
{
*/
     f8=  QtConcurrent::run( new QThreadPool() ,FunctionObject1(), 8);

      //�ȴ�����8ִ�����
     // f8.waitForFinished();
     // qDebug()<<QStringLiteral("f8�Ľ����")<<f8.result()<<f8.results();

      qDebug()<<QStringLiteral("�ۺ���������") ;


}

void MainWindow::on_stateButton_clicked()
{
    qDebug()<<
    QStringLiteral("����8״̬����ʼ%1����%2��ͣ%3ȡ��%4���%5 ")
    .arg(f8.isStarted()).arg(f8.isRunning())
    .arg( f8.isPaused()).arg(f8.isCanceled())
    .arg(f8.isFinished());

    //һ���ǵȴ������������֮�󣬲Ż�ȡ���
         if(f8.isFinished())
         {
             qDebug()<<QStringLiteral("����8���")<<f8.result();
         }

}
