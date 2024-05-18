#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    void on_mybtn_clicked();

    void on_pushButton_clicked(bool checked);

    void on_pushButton_pressed();

    void on_pushButton_released();

    //自己命名的槽函数
    void  my_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
