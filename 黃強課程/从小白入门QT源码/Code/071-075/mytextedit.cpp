#include "mytextedit.h"
#include<QDebug>
#include<QFileInfo>
#include<QMessageBox>

MyTextEdit::MyTextEdit()
{

}


  void  MyTextEdit::New(QString  name)
  {
     //连接 QTextDocument类的 contentsChanged信号  到   槽
      connect( document(), SIGNAL(contentsChanged()) , this, SLOT(documentWasModified()));

      fileName = name;

      //设置默认标题
       setWindowTitle(fileName);

  }

  void  MyTextEdit::Open(QString  path)
  {
      QFile file(path);
      //打开文件
      if (!file.open(QFile::ReadOnly | QFile::Text))
      {
          QMessageBox::warning(this, "提示","文件打开失败");
          return ;
      }

      //QFile和QTextStream配合使用，读取内容
      QTextStream in(&file);

      //设置内容到QTextEdit
      setPlainText(in.readAll());

      filePath = path; //打开文件的路径
      fileName = QFileInfo(path).fileName(); //根据文件路径，获取文件名


      //设置标题
      setWindowTitle(fileName);

    //连接 QTextDocument类的 contentsChanged信号  到   槽
   //  connect( document(), SIGNAL(contentsChanged()) , this, SLOT(documentWasModified()));

      //信号，槽的另外一种写法
      connect( document(),  & QTextDocument::contentsChanged,  this,  &MyTextEdit::documentWasModified);

  }


  //写入文件
  void  MyTextEdit::Save(QString  path)
  {
        //创建文本文件
         QFile file(path);
         if (!file.open(QFile::WriteOnly | QFile::Text))
         {
             QMessageBox::warning(this,"提示","文件保存错误");
             return  ;
         }

         QTextStream out(&file); //文件流和一个文件相关联
         out << toPlainText();  //将编辑框的内容写入到  文件中

         filePath = path; //存储当前路径，方便下次保存的时候直接使用
         fileName = QFileInfo(path).fileName();//存储当前文件名

         setWindowTitle(  fileName  ); //设置为最新的文件名，不带*

         document()->setModified(false);//将文档对象设置为未修改

  }

 void   MyTextEdit::documentWasModified()
 {
      qDebug( )<<"文档改变"<<document()->isModified()<<endl;

      setWindowTitle(fileName+"*");
 }
