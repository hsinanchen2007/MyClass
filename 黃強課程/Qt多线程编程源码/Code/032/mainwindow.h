#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void on_mapButton_clicked();

    void on_mappedButton_clicked();

    void on_mappedReducedButton_clicked();

    void on_filterButton_clicked();

    void on_filteredButton_clicked();

    void on_filteredReducedButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
