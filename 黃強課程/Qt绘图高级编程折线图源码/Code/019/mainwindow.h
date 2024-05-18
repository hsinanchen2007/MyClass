#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QMainWindow>
#include"dialwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //重写虚方法
    void timerEvent(QTimerEvent *event);

private:
    Ui::MainWindow *ui;

    //定义仪表类
    DialWidget dw;

};
#endif // MAINWINDOW_H
