#ifndef TEST_H
#define TEST_H

#include <QObject>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

    void  shoot()
    {
        //发射信号
        emit teacherHuang(666,"你好");
    }

signals:
    //自定义信号,并且带有两个参数
    void   teacherHuang(int a,  QString b);


public slots:
};

#endif // TEST_H
