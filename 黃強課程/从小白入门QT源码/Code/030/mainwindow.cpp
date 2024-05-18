#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //设置时间显示的格式
    ui->dateTimeEdit->setDisplayFormat("yyyy年MM月dd日HH:mm:ss");

    //设置最大，最小的日期
    ui->dateTimeEdit->setMinimumDateTime(  QDateTime(QDate(2018,1,1),QTime(1,1,1)) );
    ui->dateTimeEdit->setMaximumDateTime(  QDateTime(QDate(2019,3,3),QTime(1,1,1))  );

    //设置是否弹出日历
    ui->dateTimeEdit->setCalendarPopup(true);

    //设置当前显示的日期时间
    ui->dateTimeEdit->setDateTime(  QDateTime(QDate(2018,1,2),QTime(3,4,5))  );

    //设置获取焦点
    ui->dateTimeEdit->setFocus();

    //获取默认的编辑区域
     QDateTimeEdit::Section   s=  ui->dateTimeEdit->currentSection();
     qDebug()<<"编辑区域"<<s<<endl;

     qDebug()<<"区域个数"<< ui->dateTimeEdit->sectionCount()<<endl;

     //获取某个区域的字符串
     qDebug()<<"小时区域内容"<< ui->dateTimeEdit->sectionText( QDateTimeEdit::HourSection);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    //分别设置到两个控件上
      ui->dateEdit->setDate(dateTime.date());

      ui->timeEdit->setTime(dateTime.time());
}

void MainWindow::on_pushButton_clicked()
{
    //把编辑区域改到秒上
    ui->dateTimeEdit->setSelectedSection(QDateTimeEdit::SecondSection);
}
