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


void MainWindow::on_mapButton_clicked()
{
    //������QVector  QList  ,Ҫ�����������begin��end
    QList<int> list;
    list<<1<<2<<3<<4<<5;

    /*
template <typename Sequence, typename MapFunctor>
QFuture<void> map(Sequence &sequence, MapFunctor map)
*/
    //�������е�ÿ��Ԫ��ִ��Add���㡢�����޸���ԭ������
   QFuture<void>  f =  QtConcurrent::map(list ,Add );
   f.waitForFinished();//�ȴ�ִ�н���
   qDebug()<<list  ;
}


int  Add2(int  a) //��������
{
    qDebug()<<QStringLiteral("��ʼ����")<<a<<QThread::currentThread();
    QThread::sleep(1);//ģ���ʱ
    a+=1;
    qDebug()<<QStringLiteral("��������");
    return a;
}

void MainWindow::on_mappedButton_clicked()
{

    //������QVector  QList  ,Ҫ�����������begin��end
    QList<int> list;
    list<<1<<2<<3<<4<<5;

    //�������е�ÿ��Ԫ��ִ��Add���㡢���޸�ԭ������
    //���Ƿ���һ������������޸ĺ�Ľ��
   QFuture<int>  f =  QtConcurrent::mapped(list ,Add2 );
   f.waitForFinished();//�ȴ�ִ�н���
   qDebug()<<list << "     " <<f.results() ;
}


void  Sum(int & r , int e)
{
    qDebug()<<QStringLiteral("��ʼSum")<<r<<"   "<<e<<QThread::currentThread();
    QThread::sleep(1);//ģ���ʱ
    r+=e;
    qDebug()<<QStringLiteral("����Sum����");
}


void MainWindow::on_mappedReducedButton_clicked()
{
    //������QVector  QList  ,Ҫ�����������begin��end
    QList<int> list;
    list<<1<<2<<3<<4<<5;

    //�������е�ÿ��Ԫ��ִ��Add���㡢���޸�ԭ������
    //���Ƿ���һ������������޸ĺ�Ľ�������һ�������������Sum����
   QFuture<int>  f =  QtConcurrent::mappedReduced(list ,Add2,Sum );
   f.waitForFinished();//�ȴ�ִ�н���
   qDebug()<<list << "     " <<f.result()<<f.results() ;
}


//ɸѡ����
bool  Greater(int a)
{
    qDebug()<<QStringLiteral("��ʼɸѡ")<<a<<QThread::currentThread();
    QThread::sleep(1);//ģ���ʱ
    qDebug()<<QStringLiteral("����ɸѡ");
    return a>3;
}

void MainWindow::on_filterButton_clicked()
{
    //������QVector  QList  ,Ҫ�����������begin��end
    QList<int> list;
    list<<1<<2<<3<<4<<5;

    //�������е�ÿ��Ԫ��ִ��Greaterɸѡ��Ϊtrue������
    //Ϊfalse��ɾ�����޸�ԭ������
    QFuture<void> f=  QtConcurrent::filter(list, Greater);
    f.waitForFinished();
    qDebug()<<list;
}

void MainWindow::on_filteredButton_clicked()
{
    //������QVector  QList  ,Ҫ�����������begin��end
    QList<int> list;
    list<<1<<2<<3<<4<<5;

    //�������е�ÿ��Ԫ��ִ��Greaterɸѡ��Ϊtrue������
    //Ϊfalse��ɾ�������޸�ԭ��������ɸѡ����ŵ���������
    QFuture<int> f=  QtConcurrent::filtered(list, Greater);
    f.waitForFinished();
    qDebug()<<list <<  "   "<<f.results();
}

void MainWindow::on_filteredReducedButton_clicked()
{
    //������QVector  QList  ,Ҫ�����������begin��end
    QList<int> list;
    list<<1<<2<<3<<4<<5;

    //�������е�ÿ��Ԫ��ִ��Greaterɸѡ��Ϊtrue������
    //Ϊfalse��ɾ�������޸�ԭ��������ɸѡ����ŵ��������
    //����������ÿ��Ԫ�ؽ���Sum
    QFuture<int> f=  QtConcurrent::filteredReduced(list, Greater,Sum);
    f.waitForFinished();
    qDebug()<<list <<  "   "<<f.results();
}
