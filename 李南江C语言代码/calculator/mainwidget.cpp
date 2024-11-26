#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    // 注册按钮监听事件
    connect(ui->oneButton, &QPushButton::clicked, this, MainWidget::btnClick);
    connect(ui->twoButton, &QPushButton::clicked, this, MainWidget::btnClick);
    connect(ui->threeButton, &QPushButton::clicked, this, MainWidget::btnClick);
    connect(ui->fourButton, &QPushButton::clicked, this, MainWidget::btnClick);
    connect(ui->fiveButton, &QPushButton::clicked, this, MainWidget::btnClick);
    connect(ui->sixButton, &QPushButton::clicked, this, MainWidget::btnClick);
    connect(ui->sevenButton, &QPushButton::clicked, this, MainWidget::btnClick);
    connect(ui->eightButton, &QPushButton::clicked, this, MainWidget::btnClick);
    connect(ui->nineButton, &QPushButton::clicked, this, MainWidget::btnClick);
    connect(ui->zeroButton, &QPushButton::clicked, this, MainWidget::btnClick);
    connect(ui->addButton, &QPushButton::clicked, this, MainWidget::btnClick);
    connect(ui->subButton, &QPushButton::clicked, this, MainWidget::btnClick);
    connect(ui->mulButton, &QPushButton::clicked, this, MainWidget::btnClick);
    connect(ui->divButton, &QPushButton::clicked, this, MainWidget::btnClick);
    connect(ui->decButton, &QPushButton::clicked, this, MainWidget::btnClick);
    connect(ui->eqButton, &QPushButton::clicked, this, MainWidget::btnClick);
    connect(ui->acButton, &QPushButton::clicked, this, MainWidget::btnClick);
}

MainWidget::~MainWidget()
{
    delete ui;
}
// 监听按钮点击事件
void MainWidget::btnClick(){
    // 获取触发事件的对象
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    // 根据当前对象做对应的处理
    QString name = btn->objectName();
    if(name == "acButton"){
        // 清空显示字符串
        this->str.clear();
        // 清空数组
        this->list.clear();
        // 清空结果
        this->res = 0;
        ui->disLabel->setText("0");
        return;
    }else if(name == "oneButton"){
        this->str.append("1");
        this->list.append("1");
    }else if(name == "twoButton"){
        this->str.append("2");
        this->list.append("2");
    }else if(name == "threeButton"){
        this->str.append("3");
        this->list.append("3");
    }else if(name == "fourButton"){
        this->str.append("4");
        this->list.append("4");
    }else if(name == "fiveButton"){
        this->str.append("5");
        this->list.append("5");
    }else if(name == "sixButton"){
        this->str.append("6");
        this->list.append("6");
    }else if(name == "sevenButton"){
        this->str.append("7");
        this->list.append("7");
    }else if(name == "eightButton"){
        this->str.append("8");
        this->list.append("8");
    }else if(name == "nineButton"){
        this->str.append("9");
        this->list.append("9");
    }else if(name == "zeroButton"){
        this->str.append("0");
        this->list.append("0");
    }else if(name == "decButton"){
        this->str.append(".");
        this->list.append(".");
    }else if(name == "addButton"){
        this->str.append("+");
        this->list.append("+");
    }else if(name == "subButton"){
        this->str.append("-");
        this->list.append("-");
    }else if(name == "mulButton"){
        this->str.append("*");
        this->list.append("*");
    }else if(name == "divButton"){
        this->str.append("/");
        this->list.append("/");
    }else if(name == "eqButton"){
        // 显示计算结果
        ui->disLabel->setText(QString::number(this->res));
        // 清空显示字符串
        this->str.clear();
        // 将显示字符串修改为当前计算结果
        this->str.append(QString::number(this->res));
        return;
    }
    // 同步输入显示
    ui->disLabel->setText(this->str);

    // 处理优先级高的运算
    for(int i = 0; i < this->list.length(); i++){
        if(this->list.indexOf("*") != -1){
            this->highPriority("*", this->list.indexOf("*"));
        }else if(this->list.indexOf("/") != -1){
            this->highPriority("/", this->list.indexOf("/"));
        }
    }
    // 处理优先级低的运算
    for(int i = 0; i < this->list.length(); i++){
        if(this->list.indexOf("+") != -1){
            this->lowPriority("+", this->list.indexOf("+"));
        }else if(this->list.indexOf("/") != -1){
            this->lowPriority("-", this->list.indexOf("-"));
        }
    }
}
// 乘除法运算
void MainWidget::highPriority(QString op, int currentIndex){
    if(this->list.length() < 3) return;
    int temp = -1;
    if("*" == op){
        temp = (this->list[currentIndex - 1].toInt()) * (this->list[currentIndex + 1].toInt());
    }else if("/" == op){
        temp = (this->list[currentIndex - 1].toInt()) / (this->list[currentIndex + 1].toInt());
    }
    this->list.removeAt(currentIndex + 1);
    this->list.removeAt(currentIndex);
    this->list.removeAt(currentIndex - 1);
    this->list.append(QString::number(temp));
    this ->res = temp;
//    qDebug() << this->list;
//    qDebug() << this->res;
}
// 加减法运算
void MainWidget::lowPriority(QString op, int currentIndex){
    if(this->list.length() < 3) return;
    int temp = -1;
    if("+" == op){
        temp = (this->list[currentIndex - 1].toInt()) + (this->list[currentIndex + 1].toInt());
    }else if("/" == op){
        temp = (this->list[currentIndex - 1].toInt()) - (this->list[currentIndex + 1].toInt());
    }
    this->list.removeAt(currentIndex + 1);
    this->list.removeAt(currentIndex);
    this->list.removeAt(currentIndex - 1);
    this->list.append(QString::number(temp));
    this ->res = temp;
//    qDebug() << this->list;
//    qDebug() << this->res;
}

