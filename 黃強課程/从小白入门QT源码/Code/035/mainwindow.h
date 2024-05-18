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
    void on_btnForward_clicked();

    void on_btnBack_clicked();

    void on_textBrowser_backwardAvailable(bool arg1);

    void on_textBrowser_forwardAvailable(bool arg1);

    void on_textBrowser_sourceChanged(const QUrl &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
