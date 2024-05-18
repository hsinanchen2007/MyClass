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

 private  slots:
    void   XJXM_Click(bool  b);

    void   Open_Click(bool  b);

    void   Other_Click(bool  b);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
