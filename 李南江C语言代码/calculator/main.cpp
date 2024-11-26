#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.setWindowTitle(QString("计算器--LNJ"));
    w.show();

    return a.exec();
}
