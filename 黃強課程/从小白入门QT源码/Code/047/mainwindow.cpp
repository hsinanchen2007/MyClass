#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置行数列数
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(3);

    //设置水平方向的标题
    ui->tableWidget->setHorizontalHeaderLabels({"姓名","年龄","性别"});

    //设置垂直方向的标题
      ui->tableWidget->setVerticalHeaderLabels({"第一","第二"});

     //设置数据
      ui->tableWidget->setItem(0,0,new QTableWidgetItem("张三"));
      ui->tableWidget->setItem(0,1,new QTableWidgetItem(QIcon(":/new/prefix1/imgs/computer.png"),"13"));

      QTableWidgetItem *item= new QTableWidgetItem;
      item->setText("boy");
      item->setIcon(QIcon(":/new/prefix1/imgs/dance.png"));
      ui->tableWidget->setItem(0,2, item);

      //该项被选中
      item->setSelected(true);

      //设置第二行的数据
     ui->tableWidget->setItem(1,0,new QTableWidgetItem("李四"));
     ui-> tableWidget->setItem(1,1,new QTableWidgetItem("12"));
     ui-> tableWidget->setItem(1,2,new QTableWidgetItem(QIcon(":/new/prefix1/imgs/dance.png"), "跳舞"));

     //设置多选
     ui->tableWidget->setSelectionMode(QTableWidget::MultiSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
  //  qDebug()<<item->row()<<" , "<<item->column()<<"改变"<<item->text()<<endl;
}

void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
   // qDebug()<<item->row()<<" , "<<item->column()<<"点击"<<item->text()<<endl;
}

void MainWindow::on_tableWidget_itemSelectionChanged()
{
     QList<QTableWidgetItem*>   list =ui->tableWidget->selectedItems();
     foreach(  QTableWidgetItem*item, list )
     {
          qDebug()<<item->row()<<" , "<<item->column()<<"点击"<<item->text()<<endl;
     }
           qDebug()<<"------------------------------------"<<endl;
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    //根据行，列 获取相应的QTableWidgetItem
       QTableWidgetItem * item =  ui->tableWidget->item(row,column);
      qDebug()<< row<<" , "<< column <<"点击"<<item->text()<<endl;
}
