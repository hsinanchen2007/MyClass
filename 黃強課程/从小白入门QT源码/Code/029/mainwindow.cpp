#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->spinBox->setValue(15);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fontComboBox_currentFontChanged(const QFont &f)
{
    //改变字体
    QFont  qf= f;
    qf.setPointSize(  ui->spinBox->value()  );
    ui->label->setFont(qf);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    //改变字体大小
     QFont  qf= ui->fontComboBox->currentFont();
     qf.setPointSize(  arg1  );
     ui->label->setFont(qf);
}
