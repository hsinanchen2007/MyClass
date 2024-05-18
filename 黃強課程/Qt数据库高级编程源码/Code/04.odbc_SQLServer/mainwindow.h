#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSqlDatabase>
#include<QDebug>
#include<QSqlError>
#include<QSqlRecord>
#include<QSqlField>
#include<QSqlIndex>
#include<QSqlQuery>

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
    void on_pushButtonConn_clicked();

    void on_pushButtonConn2_clicked();

    void on_pushButtonInsert_clicked();

    void on_pushButtonSelect_clicked();

    void on_pushButtonUpdate_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
