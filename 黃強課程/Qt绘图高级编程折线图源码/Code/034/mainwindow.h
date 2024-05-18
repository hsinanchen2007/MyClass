#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts> //头文件

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


     QLineSeries *series ;
     QDateTimeAxis *axisX;
};
#endif // MAINWINDOW_H
