#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //����߳�ID
    qDebug()<<QThread::currentThreadId();

    return a.exec();
}
