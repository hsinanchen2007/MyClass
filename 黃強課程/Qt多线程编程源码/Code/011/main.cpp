#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    qDebug()<<QStringLiteral("main�߳�")<<QThread::currentThreadId();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
