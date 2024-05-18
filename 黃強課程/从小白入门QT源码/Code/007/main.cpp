#include <QCoreApplication>
#include<QDebug>
#include<QTimer>


int main(int argc, char *argv[])
{
    //一个应用程序，只应该有一个QCoreApplication的实例
    QCoreApplication a(argc, argv);

    // 输出运用程序的名称
   qDebug()<< QCoreApplication::applicationName()<<endl;
   // 输出运用程序的进程id
   qDebug()<< QCoreApplication::applicationPid()<<endl;
   // 输出运用程序的目录
   qDebug()<< QCoreApplication::applicationDirPath()<<endl;
   // 输出运用程序的可执行文件的 路径
   qDebug()<< QCoreApplication::applicationFilePath()<<endl;


  //大胆的猜测，instance返回的实例 与  a 是同一个实例
  QCoreApplication *pA= QCoreApplication::instance();
  bool  isEqual= (pA ==  &a) &&  ( pA == qApp) ;
  qDebug()<< "是否相等"<<isEqual<<endl;


  //5秒后调用exit(0)
  QTimer::singleShot(5000,&a,SLOT(quit()));

   int  ret=  a.exec();//进入事件循环,除非调用了exit(XXX),才能结束循环

  qDebug()<< "返回"<< ret<<endl;

    return  ret;
}
