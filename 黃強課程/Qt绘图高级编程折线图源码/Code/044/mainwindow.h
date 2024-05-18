#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QMainWindow>
#include"qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   virtual void timerEvent(QTimerEvent *event);
private:
    Ui::MainWindow *ui;

    QCustomPlot  *customPlot ;
      QCPGraph  *graph;
};
#endif // MAINWINDOW_H
