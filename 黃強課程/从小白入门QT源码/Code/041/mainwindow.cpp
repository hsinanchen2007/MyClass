#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStandardItemModel>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

      //设置视图的模式
     ui->listView->setViewMode(QListView::IconMode);

     //设置项目的间隔
     ui->listView->setSpacing(50);

     //设置网格大小， spacing失效
     ui->listView->setGridSize(QSize(150,150));

     //设置图标的大小
     ui->listView->setIconSize(QSize(100,100));

     //设置为可以多选
     ui->listView->setSelectionMode(QListView::MultiSelection);

     //设置拖拽模式Static 不能移动, Free 自由移动, Snap 对齐到网格
     ui->listView->setMovement(QListView::Snap);


       //数据模型类，通常与QListView QTableView 组合成 Model/View 结构
       QStandardItemModel * model = new QStandardItemModel(this);

       QStandardItem *item1 = new QStandardItem(QIcon(":/new/prefix1/imgs/music.png"),"音乐");
       model->appendRow(item1);//向模型中添加一行

       QStandardItem *item2 = new QStandardItem(QIcon(":/new/prefix1/imgs/computer.png"),"编程");
       model->appendRow(item2);//向模型中添加一行

       QStandardItem *item3 = new QStandardItem(QIcon(":/new/prefix1/imgs/dance.png"),"跳舞");
       model->appendRow(item3);//向模型中添加一行

        ui->listView->setModel(model);   //设置模型

    //设置默认选择
        ui->listView->setCurrentIndex(  model->index(2,0)  );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    //获取点击的项
    //qDebug()<< ui->listView->model()->data( index )<<endl;

    //获取当前选择的所有项的索引
    QModelIndexList  indexs=ui->listView->selectionModel()->selectedIndexes();
    foreach(QModelIndex  mi, indexs)
    {
        qDebug()<< ui->listView->model()->data( mi )<<endl;
    }
    qDebug()<<"-----------------------------------"<<endl;
}
