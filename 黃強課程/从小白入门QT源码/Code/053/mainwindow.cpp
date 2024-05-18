#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStackedLayout>

#include<QStackedLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QWidget  *w = new QWidget(ui->centralWidget);
    w->setObjectName("w");
    w->setGeometry(100,100,400,200);

    //为w窗口创建堆叠布局
    QStackedLayout *layout = new QStackedLayout(w);

    //创建3个小部件窗口
    QWidget *w1 = new QWidget;
    w1->setStyleSheet("background-color:red");
    QWidget *w2 = new QWidget;
    w2->setStyleSheet("background-color:green");
    QWidget *w3 = new QWidget;
    w3->setStyleSheet("background-color:blue");

    //把窗口加入堆叠布局
    layout->addWidget(w1);
    layout->insertWidget(1,w2);
    layout->addWidget(w3);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   //获取子窗口
    QWidget * w =  centralWidget()->findChild<QWidget*>("w");
   QStackedLayout *layout=  (QStackedLayout *)     w->layout();

   //轮流切换
    int  index =  layout->currentIndex();
    int  count =  layout->count() ;//布局中包含的小部件数量

   layout->setCurrentIndex( ++ index % count );
}
