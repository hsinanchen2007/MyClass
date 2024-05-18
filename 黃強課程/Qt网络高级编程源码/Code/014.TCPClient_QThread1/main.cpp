#include "mainwindow.h"

#include <QApplication>
#include<QThread>
#include<QDebug>

int main(int argc, char *argv[])
{
     qDebug()<<"main线程"<<QThread::currentThread();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
