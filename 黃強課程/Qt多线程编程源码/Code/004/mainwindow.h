#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mythread.h"
#include<QDebug>

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
    void on_startBtn_clicked();

    void on_termiateBtn_clicked();

    void on_statusBtn_clicked();

    void  ThreadStarted();
    void  ThreadFinished();
private:
    Ui::MainWindow *ui;

    //定义线程对象
    MyThread t;
};
#endif // MAINWINDOW_H
