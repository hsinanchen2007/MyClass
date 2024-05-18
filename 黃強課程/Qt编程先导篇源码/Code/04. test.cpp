#include<QApplication>
#include<QWidget>
 
int main(int argc,char *argv[])
{
    QApplication a(argc,argv);
    QWidget w;
    w.resize(500,300);
    w.show();
    return a.exec();
}  