#ifndef TEST_H
#define TEST_H
#include<QDebug>
#include <QObject>
#include <QThread>
class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

 public slots:
      void  MySlot() ;

signals:

};

#endif // TEST_H
