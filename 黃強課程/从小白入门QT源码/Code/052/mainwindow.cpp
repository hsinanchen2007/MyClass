#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QWidget *  w= new  QWidget(ui->centralWidget);
    w->setGeometry(QRect(150, 250, 381, 154));

    //表单布局
    QFormLayout  *layout= new QFormLayout(w);

    QLabel * label1= new QLabel("用户名称");
    QLineEdit  * edit1= new QLineEdit;
    layout->addRow(label1,edit1);

    QLabel * label2= new QLabel("手机号码");
    QPushButton  * btn2= new QPushButton("PushButton");
    layout->addRow(label2,btn2);

    //设置第3行的 标签域的小部件
    layout->setWidget(2,QFormLayout::LabelRole , new QPushButton("PushButton"));
    layout->setWidget(2,QFormLayout::FieldRole , new QListView());


}

MainWindow::~MainWindow()
{
    delete ui;
}
