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

    //定义模型,4行3列
    QStandardItemModel * model = new QStandardItemModel(4,3);

    /*设置行字段名*/
    //  model->setRowCount(3);
    model->setHeaderData(0,Qt::Vertical, "第一");
    model->setHeaderData(1,Qt::Vertical, "第二");
    model->setHeaderData(2,Qt::Vertical, "第三");

    /*设置列字段名*/
    // model->setColumnCount(3);
    model->setHeaderData(0,Qt::Horizontal, "姓名");
    model->setHeaderData(1,Qt::Horizontal, "年龄");
    model->setHeaderData(2,Qt::Horizontal, "性别");

    //设置第1行第1列的内容
    model->setItem(0, 0, new QStandardItem("张三"));
    //设置第1行第2列的内容
    model->setItem(0, 1, new QStandardItem("10"));
    model->setItem(0, 2, new QStandardItem("boy"));

    //设置第2行第1列的内容
    model->setItem(1, 0, new QStandardItem(QIcon(":/new/prefix1/imgs/computer.png")," 李四"));

    //为视图设置model
    ui->tableView->setModel(model);

    //连接单元格改变的信号与槽
    connect(model, SIGNAL(itemChanged(QStandardItem*)),this, SLOT(itemChangedSlot(QStandardItem*)));

    //设置某列的宽度
    ui->tableView->setColumnWidth(0,300);

    //设置某行的高度
    ui->tableView->setRowHeight(1,60);

    //设置样式表
    ui->tableView->setStyleSheet(QString(    "color: rgb(255, 0, 0);"
                                             "background-color: rgb(0, 255, 127);"    ));

    //设置多选
    ui->tableView->setSelectionMode(QAbstractItemView::MultiSelection);

    //显示为windows样式
    ui->tableView->setStyle(QStyleFactory::create("windows"));


}


void  MainWindow::itemChangedSlot(QStandardItem * item)
{

    qDebug()<<"改变"<<item->index()<<item->text()<<endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
   // qDebug()<<"当前"<<ui->tableView->model()->data(index)<<endl;

    //获取当前所有选择内容
    QModelIndexList list=  ui->tableView->selectionModel()->selectedIndexes();
     foreach (QModelIndex mi, list)
    {
            qDebug()<< ui->tableView->model()->data(mi)<<endl;
    }
     qDebug()<<"-------------------------------------"<<endl;
}

void MainWindow::on_insertBtn_clicked()
{
    ui->tableView->model()->insertRow(0);
}

void MainWindow::on_delBtn_clicked()
{
      ui->tableView->model()->removeRow(0);
}
