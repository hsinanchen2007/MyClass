#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // 设置第一个tab的标题、 图标
    ui->toolBox->setItemText(0,"家人");
    ui->toolBox->setItemIcon(0,QIcon(":/new/prefix1/imgs/computer.png"));


    //获取第一个tab 的widget
    QWidget* page1= ui->toolBox->widget(0);
    page1->setStyleSheet("background-color:red;");

  //获取第二个tab 的widget
    QWidget* page2= ui->toolBox->widget(1);
    page2->setStyleSheet("background-color:green;");


    //添加一个Tab页
    QWidget  *page3= new QWidget;
    //定义垂直布局
    QVBoxLayout *layout = new QVBoxLayout(page3);
    for(int i=0;i<100;++i){
        QPushButton *btn = new QPushButton();
        btn->setIcon(QIcon(":/new/prefix1/imgs/dance.png"));
       // btn->setText("张三");
        btn->setFixedSize(60,60);
        layout->setAlignment(Qt::AlignHCenter);
        layout->addWidget( btn );
    }

    ui->toolBox->addItem(page3, QIcon(":/new/prefix1/imgs/music.png"),"同事");

    //设置默认打开的tab
   // ui->toolBox->setCurrentWidget(page3);
    ui->toolBox->setCurrentIndex(2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolBox_currentChanged(int index)
{
    qDebug("当前索引%d",index);
}
