#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //也可以把布局直接放到centralWidget上
    //ui->centralWidget->setLayout(  ui->verticalLayout );


    //创建一个子窗口，等下来承载布局
    QWidget  *w = new QWidget(ui->centralWidget);
    w->setGeometry(QRect(500, 30, 181, 421));

    //创建垂直布局
    //创建时指定父窗口，布局默认在上面，如果不指定，需要w->setLayout
    QVBoxLayout * layout=    new  QVBoxLayout(w);

    //w->setLayout(layout);

    QPushButton *btn1= new QPushButton("one");
    QPushButton *btn2= new QPushButton("two");
    QPushButton *btn3= new QPushButton("three");

    //把按钮加入布局
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);

    //设置边距
    layout->setContentsMargins(20,20,20,20);
}

MainWindow::~MainWindow()
{
    delete ui;
}
