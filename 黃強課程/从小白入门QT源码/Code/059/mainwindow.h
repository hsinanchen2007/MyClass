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
    void on_newBtn_clicked();

    void on_closeBtn_clicked();

    void on_cdBtn_clicked();

    void on_tabBtn_clicked();

    void on_ppBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
