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
    void on_label_text_linkActivated(const QString &link);

    void on_label_text_linkHovered(const QString &link);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
