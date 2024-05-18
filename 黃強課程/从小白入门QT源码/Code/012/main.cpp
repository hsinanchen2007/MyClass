#include <QApplication>
#include <QMainWindow>
#include <QDialog>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //父窗口
    QMainWindow  w;
    w.resize(800,400);
    w.show();


    QDialog  d(&w);

    //设置对话框为模态
    //d.setModal(true);
    //默认非模态显示对话框，除非设置setModal
    //d.show();


    //open打开模态的对话框并立即返回
    d.open();
    d.done(QDialog::Accepted);//手动关闭对话框，并设置结果
    qDebug()<<"open打开模态的对话框并立即返回"<<endl;
    qDebug()<<"返回结果"<<d.result()<<endl;

   //exec打开模态的对话框并阻塞
    //d.exec();
    //qDebug()<<"exec打开模态的对话框并阻塞"<<endl;


    return a.exec();
}
