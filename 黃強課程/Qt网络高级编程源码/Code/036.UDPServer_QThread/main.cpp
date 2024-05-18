#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QThread>

int main(int argc, char *argv[])
{
    qDebug()<<"main 线程"<<QThread::currentThread();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
