#include <QApplication>
#include <QMainWindow>
#include <QDebug>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow  w;

    //调整客户区的大小
    w.resize(800,500);

    //设置整个窗口的背景色
      QPalette pal=w.palette();
      pal.setColor(QPalette::Background, Qt::red);
      w.setPalette(pal);


      //设置菜单条（一个）
       QMenuBar menuBar(&w);
       menuBar.addMenu("菜单1");
       w.setMenuBar(&menuBar);

       //添加工具条(多个)
       QToolBar  toolBar(&w);
       toolBar.setStyleSheet("background-color:#FFFF00");
       w.addToolBar(&toolBar);

       //设置状态条（一个）
       QStatusBar statusBar(&w);
       statusBar.addWidget(new  QLabel("这是状态栏"));
       statusBar.setStyleSheet("background-color:#FF00FF");
       w.setStatusBar(&statusBar);


         //停靠条
       QDockWidget dock("Dock1",&w);
       dock.setStyleSheet("background-color:#00FFFF");//设置停靠区背景色
       dock.setWidget(new QWidget());//设置停靠区的窗口
       dock.setFixedSize(200,300);//设置停靠区大小
      //设置可以移动，可关闭停靠区
       dock.setFeatures(QDockWidget::DockWidgetMovable |    QDockWidget::DockWidgetClosable);
       //设置可以左右停靠区
       dock.setAllowedAreas(Qt::AllDockWidgetAreas);

       //添加停靠条（多个）
      w.addDockWidget(Qt::RightDockWidgetArea,&dock);


         //设置centralWidget的背景色
         QWidget  centralWidget(&w);
        //使用样式表来设定外观
         centralWidget.setStyleSheet("background-color:#00FF00");

         //设置中心区域窗口
         w.setCentralWidget(&centralWidget);



      //显示主窗口
      w.show();


    return a.exec();
}
