#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextEdit>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建停靠窗口
    QDockWidget *dock1= new QDockWidget("停靠窗一");

   //设置停靠窗口的内容
    QTextEdit *edit1= new QTextEdit("这是内容1111111");
    dock1->setWidget(edit1);

    //设置相关功能
    dock1->setFeatures( QDockWidget::DockWidgetMovable );
                      //   QDockWidget::DockWidgetClosable
                      //  |QDockWidget::DockWidgetMovable
                       // |QDockWidget::DockWidgetFloatable );

    //关闭某项功能
   dock1->setFeatures(  dock1->features()& (~QDockWidget::DockWidgetMovable ));

    //设置可以停靠的区域
    dock1->setAllowedAreas( Qt::TopDockWidgetArea | Qt::RightDockWidgetArea| Qt::BottomDockWidgetArea);

    //添加停靠窗口到右侧
    this->addDockWidget(Qt::RightDockWidgetArea,  dock1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dockWidget_visibilityChanged(bool visible)
{
    qDebug("是否可见%d",visible);
}
