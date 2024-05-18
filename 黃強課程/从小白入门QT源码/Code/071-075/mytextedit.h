#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H
#include<QTextEdit>


class MyTextEdit : public QTextEdit
{
    Q_OBJECT  //加上了才能使用信号-槽

public:
    MyTextEdit();

public:
  void  New(QString  name);
  void  Open(QString  path);
  void  Save(QString path);

  QString  GetFileName()
  {
      return fileName;
  }
  QString  GetFilePath()
  {
      return filePath;
  }
private  slots:
  void  documentWasModified();

private:
  QString  fileName;
  QString  filePath;
};

#endif // MYTEXTEDIT_H
