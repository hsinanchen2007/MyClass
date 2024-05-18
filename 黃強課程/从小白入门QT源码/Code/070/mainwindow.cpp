#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QInputDialog>
#include<QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

     bool  ok=false;//true 点了确定按钮 ，  false点了取消按钮

    //单行文本输入框
  // QString  str=  QInputDialog::getText(this, "单行文本","请输入你名字" ,
  //                                      QLineEdit::Normal,"默认文本" , &ok);
   //点确定返回输入的文本，点取消  返回""
  // if(ok)
  // {
  //  qDebug()<<str<<endl;
  // }

     //整数输入框
//   int   num= QInputDialog::getInt(this, "整数","请输入你年龄",18,1,100,1,&ok);
//   if(ok)
//   {
//        qDebug()<<num<<endl;
//    }


     //浮点数输入框,2表示保留两位小数
//    double   dou= QInputDialog::getDouble(this, "小数","请输入你体重",50.23,1,100,2,&ok);
//    if(ok)
//    {
//         qDebug()<<dou<<endl;
//    }

    //列表输入框
//     QString   item   = QInputDialog::getItem(this, "列表","选择兴趣", {"编程","音乐","跳舞"} ,1,true, &ok);
//      if(ok)
//     {
//              qDebug()<<item<<endl;
//      }

      //多行输入框
      QString   strs   = QInputDialog::getMultiLineText(this, "多行文本","输入多行文字", "这是默认文本\n下一行的文本", &ok);
       if(ok)
      {
               qDebug()<<strs<<endl;
       }

}
