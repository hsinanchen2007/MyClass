#include "test.h"

#include<QDebug>
Test::Test(QObject *parent) : QObject(parent)
{

}


void   Test::my_test_solt()
{
    qDebug()<<"Test的槽"<<endl;

}
