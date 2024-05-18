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

void Add(int &a) //传引用
{
    qDebug()<<QStringLiteral("开始运算")<<a<<QThread::currentThread();
    QThread::sleep(1);//模拟耗时
    a+=1;
    qDebug()<<QStringLiteral("结束运算");
}


void MainWindow::on_mapButton_clicked()
{
    //容器有QVector  QList  ,要求这个容器有begin、end
    QList<int> list;
    list<<1<<2<<3<<4<<5;

    /*
template <typename Sequence, typename MapFunctor>
QFuture<void> map(Sequence &sequence, MapFunctor map)
*/
    //对容器中的每个元素执行Add运算、并且修改在原容器上
   QFuture<void>  f =  QtConcurrent::map(list ,Add );
   f.waitForFinished();//等待执行结束
   qDebug()<<list  ;
}


int  Add2(int  a) //不传引用
{
    qDebug()<<QStringLiteral("开始运算")<<a<<QThread::currentThread();
    QThread::sleep(1);//模拟耗时
    a+=1;
    qDebug()<<QStringLiteral("结束运算");
    return a;
}

void MainWindow::on_mappedButton_clicked()
{

    //容器有QVector  QList  ,要求这个容器有begin、end
    QList<int> list;
    list<<1<<2<<3<<4<<5;

    //对容器中的每个元素执行Add运算、不修改原容器，
    //而是返回一个新容器存放修改后的结果
   QFuture<int>  f =  QtConcurrent::mapped(list ,Add2 );
   f.waitForFinished();//等待执行结束
   qDebug()<<list << "     " <<f.results() ;
}


void  Sum(int & r , int e)
{
    qDebug()<<QStringLiteral("开始Sum")<<r<<"   "<<e<<QThread::currentThread();
    QThread::sleep(1);//模拟耗时
    r+=e;
    qDebug()<<QStringLiteral("结束Sum运算");
}


void MainWindow::on_mappedReducedButton_clicked()
{
    //容器有QVector  QList  ,要求这个容器有begin、end
    QList<int> list;
    list<<1<<2<<3<<4<<5;

    //对容器中的每个元素执行Add运算、不修改原容器，
    //而是返回一个新容器存放修改后的结果、并且还对新容器进行Sum运算
   QFuture<int>  f =  QtConcurrent::mappedReduced(list ,Add2,Sum );
   f.waitForFinished();//等待执行结束
   qDebug()<<list << "     " <<f.result()<<f.results() ;
}


//筛选函数
bool  Greater(int a)
{
    qDebug()<<QStringLiteral("开始筛选")<<a<<QThread::currentThread();
    QThread::sleep(1);//模拟耗时
    qDebug()<<QStringLiteral("结束筛选");
    return a>3;
}

void MainWindow::on_filterButton_clicked()
{
    //容器有QVector  QList  ,要求这个容器有begin、end
    QList<int> list;
    list<<1<<2<<3<<4<<5;

    //对容器中的每个元素执行Greater筛选，为true的留下
    //为false的删除、修改原容器，
    QFuture<void> f=  QtConcurrent::filter(list, Greater);
    f.waitForFinished();
    qDebug()<<list;
}

void MainWindow::on_filteredButton_clicked()
{
    //容器有QVector  QList  ,要求这个容器有begin、end
    QList<int> list;
    list<<1<<2<<3<<4<<5;

    //对容器中的每个元素执行Greater筛选，为true的留下
    //为false的删除、不修改原容器，将筛选结果放到新容器里
    QFuture<int> f=  QtConcurrent::filtered(list, Greater);
    f.waitForFinished();
    qDebug()<<list <<  "   "<<f.results();
}

void MainWindow::on_filteredReducedButton_clicked()
{
    //容器有QVector  QList  ,要求这个容器有begin、end
    QList<int> list;
    list<<1<<2<<3<<4<<5;

    //对容器中的每个元素执行Greater筛选，为true的留下
    //为false的删除、不修改原容器，将筛选结果放到新容器里、
    //将新容器的每个元素进行Sum
    QFuture<int> f=  QtConcurrent::filteredReduced(list, Greater,Sum);
    f.waitForFinished();
    qDebug()<<list <<  "   "<<f.results();
}
