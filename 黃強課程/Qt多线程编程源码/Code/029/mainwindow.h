#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThreadPool>

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
    void on_startButton_clicked();

    void on_activeThreadNumButton_clicked();


    void on_tryStartButton_clicked();

    void on_tryTakeButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;

    //定义一个线程池对象
    QThreadPool  pool;
};
#endif // MAINWINDOW_H
