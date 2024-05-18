#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QThread>
#include<QDebug>
#include <QMainWindow>
#include"mythread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

 signals:
    //пе╨е
      void  mySig();

private:
    Ui::MainWindow *ui;

    MyThread  *t;
};
#endif // MAINWINDOW_H
