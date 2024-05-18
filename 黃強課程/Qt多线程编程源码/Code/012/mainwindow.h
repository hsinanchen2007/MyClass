#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"worker.h"

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
    //定义信号来触发Worker类的方法
    void  mySig();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
