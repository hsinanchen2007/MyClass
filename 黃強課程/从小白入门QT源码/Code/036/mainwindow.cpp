#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsSimpleTextItem>
#include<QGraphicsPixmapItem>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建场景(无法显示，仅仅是管理功能)
    QGraphicsScene * scene= new  QGraphicsScene;

    //添加一个矩形图元
     QGraphicsRectItem *item = new QGraphicsRectItem(QRect(0,0,100,100) );
     item->setBrush(Qt::red);
     scene->addItem(item);

      //添加一个文本图元
     QGraphicsSimpleTextItem *item2 = new QGraphicsSimpleTextItem("Hello, world!");
     item2->setPos(100,100);
     item2->setBrush(Qt::green);
     scene->addItem(item2);


     //添加一个图片图元
      QGraphicsPixmapItem *item3= new   QGraphicsPixmapItem( QPixmap(":/new/prefix1/imgs/computer.png"));
      item3->setPos(0,100);
      item3->setScale(0.3);
      scene->addItem(item3);

      //场景要显示，需要QGraphicsView
      ui->graphicsView->setScene(scene);

      //设置场景背景色
      ui->graphicsView->setBackgroundBrush(QBrush(Qt::gray));

      //设置可以画橡皮筋矩形
      ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bigBtn_clicked()
{
    ui->graphicsView->scale(2,2);
}

void MainWindow::on_smallBtn_clicked()
{
     ui->graphicsView->scale(0.5,0.5);
}

void MainWindow::on_rotateBtn_clicked()
{
    ui->graphicsView->rotate(90);//顺时针旋转90度
}

void MainWindow::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{
    //橡皮矩形改变时，当橡皮筋选择结束时全部为空值
    qDebug()<<viewportRect<<"    "<<fromScenePoint<<"    "<<toScenePoint<<endl;
}
