#ifndef TEST_H
#define TEST_H

#include<QObject>
class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

signals:

public slots:
    void   my_test_solt();

};

#endif // TEST_H
