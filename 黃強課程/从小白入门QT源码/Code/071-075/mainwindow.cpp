#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDebug>
#include<QLabel>
#include<QTimer>
#include<QDateTime>
#include<QFileDialog>
#include<QMdiSubWindow>
#include"mytextedit.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //把mdiArea设置为CentralWidget,让这个区域铺满窗口
    setCentralWidget( ui->mdiArea  );

    //设置窗口标题
    setWindowTitle("多文档记事本");

    //设置窗口图标
    setWindowIcon(QIcon(":/new/prefix1/icons/app.png"));


    // 设置窗口最大化
    showMaximized();

    //初始化菜单
    InitMenuBar();

    //初始化工具栏
    InitToolBar();

    //初始化状态栏
    InitStatusBar();

    //刷新菜单的状态
    RefreshStatus();

}

void  MainWindow::InitMenuBar()
{
    //为菜单设置图标
    ui->actionnew->setIcon(QIcon(":/new/prefix1/icons/new.png"));
    ui->actionopen->setIcon(QIcon(":/new/prefix1/icons/open.png"));
    ui->actionsave->setIcon(QIcon(":/new/prefix1/icons/save.png"));
    ui->actionsaveAs->setIcon(QIcon(":/new/prefix1/icons/saveas.png"));
    ui->actioncloseAll->setIcon(QIcon(":/new/prefix1/icons/closeall.png"));
    ui->actionquit->setIcon(QIcon(":/new/prefix1/icons/quit.png"));


    ui->actioncopy->setIcon(QIcon(":/new/prefix1/icons/copy.png"));
    ui->actioncut->setIcon(QIcon(":/new/prefix1/icons/cut.png"));
    ui->actionpaste->setIcon(QIcon(":/new/prefix1/icons/paste.png"));
    ui->actionundo->setIcon(QIcon(":/new/prefix1/icons/undo.png"));

    //设置快捷键
    ui->actionnew->setShortcut(QKeySequence::New); //Ctrl+N
    ui->actionopen->setShortcut(QKeySequence::Open);//Ctrl+O
    ui->actionsave->setShortcut(QKeySequence::Save);//Ctrl+S
    ui->actionsaveAs->setShortcut(QKeySequence("Ctrl+Shift+S"));
    ui->actionquit->setShortcut(QKeySequence("Ctrl+Q"));

    //设置工具条，状态栏可以带 √
    ui->actiontool->setCheckable(true);
    ui->actiontool->setChecked(true);

    ui->actionstatus->setCheckable(true);
    ui->actionstatus->setChecked(true);

    //为菜单添加信号与槽
    connect( ui->actionnew, SIGNAL(triggered(bool)) ,this, SLOT(newClicked()));
    connect( ui->actionopen, SIGNAL(triggered(bool)) ,this, SLOT(openClicked()));
    connect( ui->actionsave, SIGNAL(triggered(bool)) ,this, SLOT(saveClicked()));
    connect( ui->actionsaveAs, SIGNAL(triggered(bool)) ,this, SLOT(saveAsClicked()));
    connect( ui->actioncloseAll, SIGNAL(triggered(bool)) ,this, SLOT(closeAllClicked()));
    connect( ui->actionquit, SIGNAL(triggered(bool)) ,this, SLOT(quitClicked()));

    connect( ui->actioncopy, SIGNAL(triggered(bool)) ,this, SLOT(copyClicked()));
    connect( ui->actioncut, SIGNAL(triggered(bool)) ,this, SLOT(cutClicked()));
    connect( ui->actionpaste, SIGNAL(triggered(bool)) ,this, SLOT(pasteClicked()));
    connect( ui->actionundo, SIGNAL(triggered(bool)) ,this, SLOT(undoClicked()));


    connect( ui->actiontool, SIGNAL(triggered(bool)) ,this, SLOT(toolClicked(bool)));
    connect( ui->actionstatus, SIGNAL(triggered(bool)) ,this, SLOT(statusClicked(bool)));


}


void  MainWindow::InitToolBar()
{
    //向工具条添加QAction
    QList<QAction*>  list;

    list.append( ui->actionnew);
    list.append( ui->actionopen);
    list.append( ui->actionsave);
    list.append( ui->actionsaveAs);
    list.append( ui->actioncloseAll);

    list.append( ui->actioncopy);
    list.append( ui->actioncut);
    list.append( ui->actionpaste);
    list.append( ui->actionundo);

    list.append( ui->actionquit);


    ui->mainToolBar->addActions(list);

    //添加分隔条
    ui->mainToolBar->insertSeparator(ui->actioncopy );
    ui->mainToolBar->insertSeparator(ui->actionquit );

    //设置工具条样式
    ui->mainToolBar->setIconSize(QSize(40,40));
    ui->mainToolBar->setStyleSheet("QToolBar{spacing:5px;    padding:10px;}");

}


void MainWindow::InitStatusBar()
{
    //最右侧添加一个小部件
    QLabel * lbl = new QLabel("");
    lbl->setObjectName("lblTime");
    lbl->setAlignment(Qt::AlignRight);
    lbl->setFixedSize(300, 30);    //设置长宽

    //设置一个定时器
    QTimer *timer=new QTimer(this );
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    timer->start(1000);//1秒触发一次

    //将lbl添加到状态栏右侧
    statusBar()->addPermanentWidget(lbl);
    statusBar()->setSizeGripEnabled(false);//不显示调整小三角

}

void MainWindow::newClicked()
{
    qDebug()<<"新建点击"<<endl;


    //创建一个子窗口
    MyTextEdit *edit= new MyTextEdit;

    QString  fileName=QString("文档%1").arg(++index) ;

    //做额外的工作
    edit->New(fileName);

    //将会自动创建一个QMdiSubWindow，然后使用setWidget(edit)
    ui->mdiArea->addSubWindow(edit);

    //设置为最大化
    edit->showMaximized();

    //刷新菜单的状态
    RefreshStatus();
}



void MainWindow::openClicked()
{

    //选择文件
    QString filePath = QFileDialog::getOpenFileName(this,"打开文件",
                                                    "C:\\Users\\Administrator\\Desktop","Text File(*.txt)");
    qDebug() << filePath;

    if(!filePath.isEmpty())//如果文件路径有效
    {
        MyTextEdit * edit = new MyTextEdit();   //新建一个子窗口
        ui->mdiArea->addSubWindow(edit);

        edit->Open(filePath); //做一些打开的工作
        edit->showMaximized();//窗口最大化
    }

    //刷新菜单的状态
    RefreshStatus();

}


void MainWindow::saveClicked()
{
    //获取当前正在编辑窗口
    MyTextEdit *edit= activeTextEdit();

    if(edit==nullptr) return ;

    QString path=edit->GetFilePath();
    if(path.isEmpty())
    {//说明之前没有保存过，需要选择一个路径
        saveAsClicked();
    }
    else
    { //说明之前保存过，那么直接在原路径保存就行了
        edit->Save(path);
    }

}


void MainWindow::saveAsClicked()
{
    //获取当前正在编辑窗口
    MyTextEdit *edit= activeTextEdit();

    if(edit==nullptr) return ;

    QString dir="C:\\Users\\Administrator\\Desktop\\"+ edit->GetFileName();   //打开文件对话框选择储存路径，指定默认文件名
    //另存为对话框
    QString filePath= QFileDialog::getSaveFileName(this,"另存为的", dir  ,"Text File(*.txt)");

    qDebug() << filePath;

    if(!filePath.isEmpty())
    {
        edit->Save(filePath);//保存文件在选择的路径
    }


}


void MainWindow::closeAllClicked()
{
   //获取所有子窗口
  QList<QMdiSubWindow *>  list= ui->mdiArea->subWindowList();

  //开始检查每个窗口是否需要保存
  foreach (QMdiSubWindow * sub , list)
  {
      ui->mdiArea->setActiveSubWindow(sub);
      saveClicked();//保存当前窗口
  }

  //关闭所有子窗口
   ui->mdiArea->closeAllSubWindows();

   //刷新菜单的状态
   RefreshStatus();
}



void MainWindow::cutClicked()
{
    if(activeTextEdit())activeTextEdit()->cut();

}
void MainWindow::copyClicked()
{
    if(activeTextEdit())activeTextEdit()->copy();
}
void MainWindow::pasteClicked()
{
   if(activeTextEdit())activeTextEdit()->paste();
}

void MainWindow::undoClicked()
{
   if(activeTextEdit())activeTextEdit()->undo();
}

void MainWindow::toolClicked(bool  checked)
{
    ui->mainToolBar->setVisible(checked);
}

void MainWindow::statusClicked(bool  checked)
{
    ui->statusBar->setVisible(checked);
}

//槽
void  MainWindow::timeout( )
{

    QLabel * lbl= statusBar()->findChild<QLabel *>("lblTime");

    QDateTime *datetime=new QDateTime(QDateTime::currentDateTime());

    //设置时间显示格式
    QString str = datetime->toString(" 当前时间: yyyy-MM-dd hh:mm:ss ");

    lbl->setText(str);

}



void MainWindow::quitClicked()
{
  //保存所有子窗口
   closeAllClicked();

   //退出运用程序
    qApp->quit();
}



MyTextEdit *  MainWindow::activeTextEdit()
{
    //获取当前激活的子窗口
    QMdiSubWindow * sub  =  ui->mdiArea->activeSubWindow();

    if(sub !=nullptr)
    {
        //获取子窗口中的小部件MyTextEdit
        MyTextEdit *  edit=  (MyTextEdit * )  sub->widget();
        return edit;
    }

    return nullptr;
}

void  MainWindow::RefreshStatus()
{
    MyTextEdit *edit= activeTextEdit();

    //如果存在当前子窗口，才可 保存，另存为，关闭
    bool flag= ( edit!=nullptr);

    ui->actioncloseAll->setEnabled(flag);
    ui->actionsave->setEnabled(flag);
    ui->actionsaveAs->setEnabled(flag);

}


MainWindow::~MainWindow()
{
    delete ui;
}
