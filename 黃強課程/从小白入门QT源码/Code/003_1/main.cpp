#include <QCoreApplication>
#include<QDebug>
#include<stdio.h>
#include<iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // qt的打印
    qDebug()<<"Hello World!"<<endl;

    //C语言的打印
    printf("Hello World!\n");

    //C++的 打印
    std::cout<<"Hello World!"<<std::endl;

    return a.exec();
}
