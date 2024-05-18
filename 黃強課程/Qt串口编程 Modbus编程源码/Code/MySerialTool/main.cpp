#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //Êä³öÏß³ÌID
    qDebug()<<QThread::currentThreadId();

    return a.exec();
}
