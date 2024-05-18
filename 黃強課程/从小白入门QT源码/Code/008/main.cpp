#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QWidget>

int main(int argc, char *argv[])
{
    //对于基于Widget的GUI程序的 唯一应用程序实例
    QApplication a(argc, argv);

    //只能有一个实例
    qDebug()<<"是否相同" <<(  (  &a ==  qApp )&& (&a ==QApplication::instance() ))<<endl;


    MainWindow w;
    w.show();

   QWidget  w2;//第二个窗口
   w2.show();


   //获取所有的Widget
   QWidgetList  list = QApplication::allWidgets();
    qDebug()<<"窗口个数"<<list.count()<<endl;

    //设置运用程序字体
    QFont font;
    font.setFamily( "STXingkai");//华文行楷
    QApplication::setFont(font );


    //设置调色板
    QPalette palette = QApplication::palette();
    palette.setColor(QPalette::Window, Qt::red);
    QApplication::setPalette(palette);


    //设置当前激活的窗口
    QApplication::setActiveWindow(&w);


    int  ret= a.exec(); //进入事件循环，除非调用exit(XXX) 或者 关闭所有窗口会结束此循环

    qDebug()<<"返回"<<ret<<endl;

    return  ret;
}
