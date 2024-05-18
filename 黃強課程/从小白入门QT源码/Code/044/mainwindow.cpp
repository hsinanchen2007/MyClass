#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStandardItemModel>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStandardItemModel * model = new QStandardItemModel();      //定义模型

    //创建一个项
    QStandardItem *zg = new QStandardItem(QIcon(":/new/prefix1/imgs/computer.png"),"中国");

    QStandardItem *bj = new QStandardItem("北京");
    QStandardItem *sh = new QStandardItem("上海");
    QStandardItem *sz  = new QStandardItem("深圳");
    //为zg添加3项
    zg->appendRow(bj);
    zg->appendRow(sh);
    zg->appendRow(sz);

    QStandardItem *cy = new QStandardItem("朝阳区域");
    QStandardItem *ft = new QStandardItem("丰台区域");
    QStandardItem *dc  = new QStandardItem("东城区域");
    //为bj添加3行
    bj->appendRow(cy);
    bj->appendRow(ft);
    bj->appendRow(dc);

    //将zg添加到model
    model->appendRow(zg);

    //设置模型
    ui->columnView->setModel(model);

    //设定每列的宽度
    ui->columnView->setColumnWidths({ 100,200,300 });

    //设置是否显示调整手柄
    ui->columnView->setResizeGripsVisible(false);

    //设置多选
    ui->columnView->setSelectionMode(QColumnView::MultiSelection);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_columnView_clicked(const QModelIndex &index)
{
  //  qWarning()<<"当前"<<index<<endl;


    //获取当前所有选择内容
    QModelIndexList list=  ui->columnView->selectionModel()->selectedIndexes();
    foreach (QModelIndex mi, list)
    {
        qWarning()<<  ui->columnView->model()->data(mi);
    }

    qWarning()<<"-----------------------------------------"<<endl;


}
