#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
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
    void  mybuttonClicked(int id);
   void   mybuttonClicked2(QAbstractButton* btn);
   void on_male_clicked();

   void on_female_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
