#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //输出线程ID
    qDebug()<<"main:   "<<QThread::currentThreadId();


    return a.exec();
}
