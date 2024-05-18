#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置列数
    ui->treeWidget->setColumnCount(1);

    //设置头部每列标签文本
    ui->treeWidget->setHeaderLabels({"标一","标二","标三"});

    //隐藏头部
    ui->treeWidget->setHeaderHidden(true);

    //设置列宽
    ui->treeWidget->setColumnWidth(0,300);

    //创建根节点r1
    QTreeWidgetItem  * r1= new QTreeWidgetItem({"兴趣"});
    r1->setIcon(0,QIcon(":/new/prefix1/imgs/computer.png"));

    //创建两个子节点
    QTreeWidgetItem * item11= new QTreeWidgetItem({"编程"});
    item11->setIcon(0,QIcon(":/new/prefix1/imgs/computer.png") );
    r1->addChild(item11);


    QTreeWidgetItem * item12= new QTreeWidgetItem(r1,{"跳舞"} );
    item12->setIcon(0,QIcon(":/new/prefix1/imgs/dance.png") );

    //创建根节点r2
    QTreeWidgetItem  * r2= new QTreeWidgetItem( QStringList()<<"其他");
    r2->setIcon(0,QIcon(":/new/prefix1/imgs/music.png"));

   //添加子节点
    r2->addChild(new QTreeWidgetItem({"跑步"}));


    //添加一个顶层节点
    ui->treeWidget->addTopLevelItem(r1);
    //添加一个顶层节点
    ui->treeWidget->addTopLevelItem(r2);

    //展开所有节点
    ui->treeWidget->expandAll();

    //设置多选
    ui->treeWidget->setSelectionMode(QTreeWidget::MultiSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
   // qDebug()<<"选择"<<item->text(0)<< column<<endl;
}

void MainWindow::on_treeWidget_itemSelectionChanged()
{
    QList<QTreeWidgetItem*> list= ui->treeWidget->selectedItems();

    foreach(QTreeWidgetItem * it, list)
    {
        qDebug()<<it->text(0)<<endl;
    }
     qDebug()<<"----------------------------------------------"<<endl;
}
