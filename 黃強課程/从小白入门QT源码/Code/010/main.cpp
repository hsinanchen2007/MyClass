#include <QApplication>
#include <QWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    //基于Widget的GUI程序需要使用QApplication的实例
    QApplication a(argc, argv);

    QWidget  w;
    //设置窗口标题
    w.setWindowTitle("窗口");
    //设置窗口透明度范围0-1
    w.setWindowOpacity(1);
    //设置窗口提示
    w.setToolTip("这是提示");

    //设置Widget背景色
     QPalette pal=w.palette();
     pal.setColor(QPalette::Background, Qt::red);
     w.setPalette(pal);

     //设置 固定大小，无法调整
     w.setFixedSize(300,300);


     //显示窗口
      w.show();

      //设置客户区域的矩形
      //w.setGeometry(0,0,300,300);

      //仅设置客户区的长宽
      //w.resize(300,300);



     {//获取整个窗口的一些尺寸

        qDebug()<<"整个窗口矩形"<< w.frameGeometry()<<endl;
        qDebug()<<"整个窗口长宽"<< w.frameSize()<<endl;
        qDebug()<<"整个窗口左上坐标"<< w.pos()<<w.x()<<w.y()<<endl;

     }

      {//获取客户区的一些尺寸

         qDebug()<<"客户区的矩形"<< w.geometry()<<endl;
         qDebug()<<"客户区的矩形，以0,0为左上角"<< w.rect()<<endl;
         qDebug()<<"客户区的长宽"<< w.size()<< w.width()<<w.height() << endl;
         qDebug()<<"客户左上坐标"<< w.geometry().x()<< w.geometry().y() <<endl;

      }



    return a.exec();
}
