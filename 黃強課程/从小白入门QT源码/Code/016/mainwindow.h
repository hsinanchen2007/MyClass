#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "test.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

     void my_solt(int a, QString b);

private:
    Ui::MainWindow *ui;

    Test   t ;

};

#endif // MAINWINDOW_H
