#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStandardItemModel>
#include<QDebug>
#include<QStyleFactory>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //定义模型
    QStandardItemModel * model = new QStandardItemModel();
    //定义一个父节点1
    QStandardItem *r1 = new QStandardItem(QIcon(":/new/prefix1/imgs/computer.png") ,"兴趣");

    //定义两个子节点
    QStandardItem *item11 = new QStandardItem(QIcon(":/new/prefix1/imgs/computer.png") ,"编程");
    QStandardItem *item12 = new QStandardItem();
    item12->setText("音乐");
    item12->setIcon(QIcon(":/new/prefix1/imgs/music.png"));

    r1->appendRow(item11);      //把这两个节点作为子节点
    r1->appendRow(item12);


    //定义一个父节点2
    QStandardItem *r2 = new QStandardItem("特长");
    //定义一个子节点
    QStandardItem *item21 = new QStandardItem(QIcon(":/new/prefix1/imgs/dance.png") ,"跳舞");
    //把这个节点作为子节点
    r2->appendRow(item21);

    //将第1行第1列的内容设置为 r1节点
    model->setItem(0, 0, r1);
    //model->setItem(0, 1, new QStandardItem("备注"));

    //将第2行第1列的内容设置为 r2节点
    model->setItem(1, 0, r2);

    //设置模型
    ui->treeView->setModel(model);

    //设置列数
    model->setColumnCount(1);
   //设置列的标题
    model->setHeaderData( 0, Qt::Horizontal, "第一");
    model->setHeaderData( 1, Qt::Horizontal, "第二");
   //设置列的宽度
    ui->treeView->setColumnWidth(0,300);

    //隐藏头部
    ui->treeView->setHeaderHidden(true);

    //展开所有树节点
    ui->treeView->expandAll();

    //设置默认选中某项
    ui->treeView->setCurrentIndex( model->index(1,0));

    //设置 子节点选择
    ui->treeView->setCurrentIndex( model->index(0,0).child(1,0));

    //设置每级的缩进
   // ui->treeView->setIndentation(100);

   //设置图标大小
    ui->treeView->setIconSize(QSize(70,70));

    //设置多选
    ui->treeView->setSelectionMode(QTreeView::MultiSelection);


    //显示为windows样式，变成虚线
   ui->treeView->setStyle(QStyleFactory::create("windows"));

   //设置样式表
     ui->treeView->setStyleSheet(QString(
                                     "color: rgb(255, 0, 0);"
                                    "background-color: rgb(0, 255, 127);"
                                     ));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    //qDebug()<<"当前选择"<<  ui->treeView->model()->data(index)   <<endl;


    //获取所有选中的项
    QModelIndexList  list = ui->treeView->selectionModel()->selectedIndexes();
    foreach(QModelIndex  mi, list)
    {
        qDebug()<< ui->treeView->model()->data(mi)   <<endl;
    }
     qDebug()<< "-----------------------------"<<endl;

}
