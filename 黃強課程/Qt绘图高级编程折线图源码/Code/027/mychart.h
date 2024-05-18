#ifndef MYCHART_H
#define MYCHART_H

#include <QWidget>

namespace Ui {
class MyChart;
}

class MyChart : public QWidget
{
    Q_OBJECT

public:
    explicit MyChart(QWidget *parent = nullptr);
    ~MyChart();

    virtual void paintEvent(QPaintEvent *event);

private:
    Ui::MyChart *ui;
};

#endif // MYCHART_H
