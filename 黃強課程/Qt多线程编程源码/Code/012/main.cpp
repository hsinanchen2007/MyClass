#include "mainwindow.h"
#include <QDebug>
#include <QThread>
#include <QApplication>

int main(int argc, char *argv[])
{
    qDebug()<<QStringLiteral("Ö÷Ïß³Ì")<< QThread::currentThreadId();


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
