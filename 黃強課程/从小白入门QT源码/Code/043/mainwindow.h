#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class  QStandardItem;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public  slots:
   void  itemChangedSlot(QStandardItem * item);

private slots:
   void on_tableView_clicked(const QModelIndex &index);

   void on_insertBtn_clicked();

   void on_delBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
