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
    void on_btnCode_stateChanged(int arg1);

    void on_btnMusic_clicked(bool checked);

    void on_btnCode_clicked(bool checked);

    void on_btnMusic_stateChanged(int arg1);

    void on_btnMusic_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
