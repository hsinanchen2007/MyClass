#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),//step 3
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   //加入样式到下拉框
     QStringList files;
     files<<"AMOLED.qss"<<"Aqua.qss"<<"ConsoleStyle.qss"<<"ElegantDark.qss"<<"MacOS.qss"<<"ManjaroMix.qss"
         <<"MaterialDark.qss"<<"MetroUI.qss"<<"NeonButtons.qss"<<"Ubuntu.qss";


     foreach(QString f , files)
     {
         ui->comboBox->addItem(f);
     }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_currentTextChanged(const QString &name)
{

    //切换样式
    QString path= QString(":/qss/%1").arg(name );
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
        exit(0);

    QTextStream in(&file);
    QString css = in.readAll();
    //应用程序对象的QApplication::setStyleSheet
    qApp->setStyleSheet(css);
}
