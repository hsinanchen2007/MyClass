#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //����QThread��Ķ���
    t= new QThread();
    t->start();//�����߳�

    //�����Զ�����࣬ �̳���QObject��
    Worker *w = new Worker();
     // ��w�ƶ����̶߳�����
    w->moveToThread(t);

    //���źźͲ�,����startSig��ִ���̺߳���Do
    connect(this, &MainWindow::startSig, w ,&Worker::Do);

    //���źŲۣ�����mySig������UI
    connect(w, &Worker::mySig,  this  ,&MainWindow::updateNum);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   // ����startSig��ִ���̺߳���Do
    emit  startSig();
}

 void MainWindow::updateNum(QString num)
 {
          //����UI
      ui->pushButton->setText(num);

 }
