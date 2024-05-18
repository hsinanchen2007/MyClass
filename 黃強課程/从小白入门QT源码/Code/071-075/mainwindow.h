#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MyTextEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void  InitMenuBar();
    void  InitToolBar();
    void  InitStatusBar();

    MyTextEdit *  activeTextEdit();//获取当前子窗口
    void  RefreshStatus();//刷新菜单的状态
private  slots:

   void   newClicked();
   void   openClicked();
   void   saveClicked();
   void   saveAsClicked();
   void   closeAllClicked();
   void   quitClicked();


   void   cutClicked();
   void   copyClicked();
   void   pasteClicked();
   void   undoClicked();

   void   toolClicked(bool  checked);
   void   statusClicked(bool  checked);

   void   timeout( );

private:
    Ui::MainWindow *ui;

 private:
    int  index=0; //文档递增序号

};

#endif // MAINWINDOW_H
