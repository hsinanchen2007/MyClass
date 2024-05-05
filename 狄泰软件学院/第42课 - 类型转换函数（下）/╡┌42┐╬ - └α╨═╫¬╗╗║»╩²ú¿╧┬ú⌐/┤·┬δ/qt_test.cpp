#include <QDebug>
#include <QString>

int main()
{
    QString str = "";
    int i = 0;
    double d = 0;
    short s = 0;

    str = "-255";
    i = str.toInt();
    d = str.toDouble();
    s = str.toShort();

    qDebug() << "i = " << i << endl;
    qDebug() << "d = " << d << endl;
    qDebug() << "s = " << s << endl;

    return 0;
}
