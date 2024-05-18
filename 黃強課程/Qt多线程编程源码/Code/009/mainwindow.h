#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QThread>
#include<QDebug>
#include <QMainWindow>

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

    void on_statusButton_clicked();

    void on_exitButton_clicked();


    void  startSlot();
    void finishSlot();
private:
    Ui::MainWindow *ui;

      QThread  t;//线程对象
};
#endif // MAINWINDOW_H
