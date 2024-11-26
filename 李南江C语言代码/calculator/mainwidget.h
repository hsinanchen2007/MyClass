#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    QString str;
    QStringList list;
    double res;
    void btnClick();
    void highPriority(QString op, int currentIndex);
    void lowPriority(QString op, int currentIndex);
};

#endif // MAINWIDGET_H
