#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化QTableWidget控件

    QStringList  header;
    header<<"学号"<<"姓名"<<"年龄"<<"分数";

    //设置为4列
    ui->tableWidget->setColumnCount(header.size());
    //设置100行
    ui->tableWidget->setRowCount(100);
    //设置列名
    ui->tableWidget->setHorizontalHeaderLabels(header);
    //隐藏行号
    ui->tableWidget->verticalHeader()->setHidden(true);
   //水平方向拉升
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    setWindowTitle("Qt ODBC访问Access");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//使用ODBC    DSN来连接数据库
void MainWindow::on_pushButtonConn_clicked()
{
    //查看Qt框架为我们提供的数据库驱动程序
    qDebug()<<"Qt支持的数据库驱动"<< QSqlDatabase::drivers();

    //创建一个数据库对象
    QSqlDatabase  db =QSqlDatabase::addDatabase("QODBC", "conn1");

    //设置连接参数
    db.setDatabaseName("hq3");//参数是DSN的名称
    db.setUserName(""); //连接数据库的用户名
    db.setPassword("");//连接数据库的密码

    //连接数据库
   bool bOpen= db.open();
   if(bOpen)
   {
       qDebug()<<"数据库（ DSN）连接成功！";
   }
   else
   {
         qDebug()<<"数据库（ DSN）连接失败："<<db.lastError();
   }

   //测试常用成员函数
   qDebug()<<"是否打开"<<db.isOpen();

   qDebug()<<"自定义的连接名称"<<db.connectionName();

   qDebug()<<"使用的驱动"<<db.driverName();

    qDebug()<<"主键字段的位置"<<db.primaryIndex("Student");

  qDebug()<<"数据库中的表：" <<db.tables();

  QSqlRecord rec =db.record("Student");
  for( int i=0;i< rec.count();++i)
  {
      qDebug()<< rec.fieldName(i) ;
  }


}

//使用ODBC 连接字符串来连接
void MainWindow::on_pushButtonConn2_clicked()
{
    //创建一个数据库对象
    QSqlDatabase  db =QSqlDatabase::addDatabase("QODBC", "conn2");

    //设置连接参数
    db.setDatabaseName(

                QString("DRIVER={%1};"
                                       "DBQ=%2;" //Access数据库文件的路径
                                       "UID=%3;"           //登录名
                                       "PWD=%4;"        //密码
                                       )
                              //.arg("Microsoft Access Driver (*.mdb)")//不区分大小写
                               .arg("Driver do Microsoft Access (*.mdb)")
                               .arg("C:\\Users\\Administrator\\Desktop\\Code\\School.mdb")
                               .arg("")
                               .arg("")
                );


    //连接数据库
   bool bOpen= db.open();
   if(bOpen)
   {
       qDebug()<<"数据库（使用连接字符串）连接成功！";
   }
   else
   {
         qDebug()<<"数据库（使用连接字符串）连接失败："<<db.lastError();
   }
}

/*
void MainWindow::on_pushButtonInsert_clicked()
{
    //打印一下当前已存在的数据库连接
    qDebug()<<"当前已经存在的连接"<<QSqlDatabase::connectionNames();

    //通过连接名称，获取已经存在的数据库连接
    //QSqlDatabase db=QSqlDatabase::database("conn1");//通过连接名称获取
     QSqlDatabase db= QSqlDatabase::database("conn2");

    //插入数据了
    QString  sql=QString("INSERT INTO Student (name,age,score) VALUES('%1',%2,%3 )")
            .arg("吴老师").arg(42).arg(77.123);

    //用于数据库操作的对象
    QSqlQuery  query(db);
   bool ret= query.exec(sql);
   if(ret)
   {
       //受影响的行数
       int num= query.numRowsAffected();
       qDebug()<<QString("插入%1条数据成功!").arg(num);

       //获取刚刚插入成功的自增id
       QString sql2= "SELECT @@IDENTITY";
        bool ret2= query.exec(sql2);
        if(ret2)
        {
            query.next();//获取到第一条记录
            qDebug()<<"刚刚插入的id为"<<query.value(0).toInt();
        }

   }
   else
   {
         qDebug()<<QString("插入数据失败:")<<query.lastError();
   }

}


*/

/*
void MainWindow::on_pushButtonInsert_clicked()
{
    //获取数据库连接的对象
     QSqlDatabase db= QSqlDatabase::database("conn2");

    //用于数据库操作的对象
    QSqlQuery  query(db);

    //准备一条SQL语句，使用？当做占位符
    query.prepare("INSERT INTO Student (name,age,score) VALUES( ?,?,?)");
    //为占位符赋值
    query.bindValue(0, "问号占位符");
    query.bindValue(1, 12);
    query.bindValue(2, 66.45);

   bool ret= query.exec( );
   if(ret)
   {
       //受影响的行数
       int num= query.numRowsAffected();
       qDebug()<<QString("插入%1条数据成功!").arg(num);

       //获取刚刚插入成功的自增id
       QString sql2= "SELECT @@IDENTITY";
        bool ret2= query.exec(sql2);
        if(ret2)
        {
            query.next();//获取到第一条记录
            qDebug()<<"刚刚插入的id为"<<query.value(0).toInt();
        }

   }
   else
   {
         qDebug()<<QString("插入数据失败:")<<query.lastError();
   }

}
*/


void MainWindow::on_pushButtonInsert_clicked()
{
    //获取数据库连接的对象
     QSqlDatabase db= QSqlDatabase::database("conn2");

    //用于数据库操作的对象
    QSqlQuery  query(db);

    //准备一条SQL语句，使用 :名称 当做占位符
    query.prepare("INSERT INTO Student  (name,age,score) VALUES( :name,:age,:score)");
    //为占位符赋值
    query.bindValue(":name", "占位名称");
    query.bindValue(":age", 15);
    query.bindValue(":score", 33.45);

   bool ret= query.exec( );
   if(ret)
   {
       //受影响的行数
       int num= query.numRowsAffected();
       qDebug()<<QString("插入%1条数据成功!").arg(num);

       //获取刚刚插入成功的自增id
       QString sql2= "SELECT @@IDENTITY";
        bool ret2= query.exec(sql2);
        if(ret2)
        {
            query.next();//获取到第一条记录
            qDebug()<<"刚刚插入的id为"<<query.value(0).toInt();
        }

   }
   else
   {
         qDebug()<<QString("插入数据失败:")<<query.lastError();
   }

}

void MainWindow::on_pushButtonSelect_clicked()
{
    //清除界面上一次的查询结果
    ui->tableWidget->clearContents();

    //查询数据

    //获取数据库连接的对象
     QSqlDatabase db= QSqlDatabase::database("conn2");

     QString sql="SELECT  *  FROM   Student";

     //用于数据库操作的对象
     QSqlQuery  query(db);

     //执行SQL语句
     bool ret= query.exec( sql );
     if(ret)
     {
         //受影响的行数
         int num= query.numRowsAffected();
         qDebug()<<QString("查询%1条数据成功!").arg(num);

         int row =0;

         //next()获取下一行数据，如果有则返回true
         while( query.next())
         {
                int id= query.value("id").toInt();// query.value(0).toInt();
                QString  name=  query.value("name").toString();//query.value(1).toString();
                int  age=   query.value("age").toInt();//query.value(2).toInt();
                float  score = query.value("score").toFloat();// query.value(3).toFloat();

                //设置每列的内容
                ui->tableWidget->setItem(row,0, new QTableWidgetItem(QString::number(id)));
                ui->tableWidget->setItem(row,1, new QTableWidgetItem( name));
                ui->tableWidget->setItem(row,2, new QTableWidgetItem(QString::number(age)));
                ui->tableWidget->setItem(row,3, new QTableWidgetItem(QString::number(score)));

                ++ row;
         }

     }
     else
     {
           qDebug()<<QString("查询数据失败:")<<query.lastError();
     }
}

/*
void MainWindow::on_pushButtonUpdate_clicked()
{
    //修改数据库

    //通过连接名称，获取已经存在的数据库连接
    QSqlDatabase db= QSqlDatabase::database("conn2");

    //修改数据的SQL语句
    QString  sql=QString("UPDATE  Student SET name='%1', "
                         "age=%2, score=%3  WHERE  id=%4")
            .arg("名称被修改").arg(66).arg(77.77).arg(11);

    //用于数据库操作的对象
    QSqlQuery  query(db);
   bool ret= query.exec(sql);
   if(ret)
   {
       //受影响的行数
       int num= query.numRowsAffected();
       qDebug()<<QString("修改%1条数据成功!").arg(num);
   }
   else
   {
         qDebug()<<QString("修改数据失败:")<<query.lastError();
   }
}

*/

void MainWindow::on_pushButtonUpdate_clicked()
{
    //修改数据库

    //通过连接名称，获取已经存在的数据库连接
    QSqlDatabase db= QSqlDatabase::database("conn2");

    //用于数据库操作的对象
    QSqlQuery  query(db);
    query.prepare("UPDATE  Student SET name=?, "
                  "age=?, score=?  WHERE  id=?");
    query.bindValue(0,"问号修改");
    query.bindValue(1,6);
    query.bindValue(2, 6.66);
    query.bindValue(3,12);

   bool ret= query.exec( );
   if(ret)
   {
       //受影响的行数
       int num= query.numRowsAffected();
       qDebug()<<QString("修改%1条数据成功!").arg(num);
   }
   else
   {
         qDebug()<<QString("修改数据失败:")<<query.lastError();
   }

   query.clear();
}

/*
void MainWindow::on_pushButtonDelete_clicked()
{
    //删除数据库的记录

    //通过连接名称，获取已经存在的数据库连接
    QSqlDatabase db= QSqlDatabase::database("conn2");

    //删除数据的SQL语句
    QString  sql=QString("DELETE  FROM  Student WHERE  id=%1")
            .arg(15);

    //用于数据库操作的对象
    QSqlQuery  query(db);
   bool ret= query.exec(sql);
   if(ret)
   {
       //受影响的行数
       int num= query.numRowsAffected();
       qDebug()<<QString("删除%1条数据成功!").arg(num);
   }
   else
   {
         qDebug()<<QString("删除数据失败:")<<query.lastError();
   }
}
*/
void MainWindow::on_pushButtonDelete_clicked()
{
    //删除数据库的记录

    //通过连接名称，获取已经存在的数据库连接
    QSqlDatabase db= QSqlDatabase::database("conn2");

    //用于数据库操作的对象
    QSqlQuery  query(db);
    query.prepare("DELETE  FROM  Student WHERE  id=:myid");
    query.bindValue(":myid", 17); // 绑定参数值
    bool ret= query.exec( );
   if(ret)
   {
       //受影响的行数
       int num= query.numRowsAffected();
       qDebug()<<QString("删除%1条数据成功!").arg(num);
   }
   else
   {
         qDebug()<<QString("删除数据失败:")<<query.lastError();
   }
}


void MainWindow::on_pushButtonClose_clicked()
{

    {
        //通过连接名称，获取已经存在的数据库连接
        QSqlDatabase db= QSqlDatabase::database("conn2");
        db.close();//关闭数据库对象
    }

    //移除该条连接
    QSqlDatabase::removeDatabase("conn2");
    //所有的数据库连接名
    qDebug()<<"所有连接"<<QSqlDatabase::connectionNames();

}
