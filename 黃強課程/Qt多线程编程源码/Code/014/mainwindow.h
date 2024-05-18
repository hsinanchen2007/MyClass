#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"worker.h"

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
    void on_pushButton_clicked();
    void updateNum(QString num);
signals:
    void  startSig();
private:
    Ui::MainWindow *ui;

    QThread *t;//方式二 使用 原生类
};
#endif // MAINWINDOW_H
