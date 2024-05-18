#ifndef DIALWIDGET_H
#define DIALWIDGET_H

#include <QWidget>

namespace Ui {
class DialWidget;
}

class DialWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DialWidget(QWidget *parent = nullptr);
    ~DialWidget();

     void paintEvent(QPaintEvent *event);

private:
    Ui::DialWidget *ui;
};

#endif // DIALWIDGET_H
