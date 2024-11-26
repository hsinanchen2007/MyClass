#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    // ע�ᰴť�����¼�
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
// ������ť����¼�
void MainWidget::btnClick(){
    // ��ȡ�����¼��Ķ���
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    // ���ݵ�ǰ��������Ӧ�Ĵ���
    QString name = btn->objectName();
    if(name == "acButton"){
        // �����ʾ�ַ���
        this->str.clear();
        // �������
        this->list.clear();
        // ��ս��
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
        // ��ʾ������
        ui->disLabel->setText(QString::number(this->res));
        // �����ʾ�ַ���
        this->str.clear();
        // ����ʾ�ַ����޸�Ϊ��ǰ������
        this->str.append(QString::number(this->res));
        return;
    }
    // ͬ��������ʾ
    ui->disLabel->setText(this->str);

    // �������ȼ��ߵ�����
    for(int i = 0; i < this->list.length(); i++){
        if(this->list.indexOf("*") != -1){
            this->highPriority("*", this->list.indexOf("*"));
        }else if(this->list.indexOf("/") != -1){
            this->highPriority("/", this->list.indexOf("/"));
        }
    }
    // �������ȼ��͵�����
    for(int i = 0; i < this->list.length(); i++){
        if(this->list.indexOf("+") != -1){
            this->lowPriority("+", this->list.indexOf("+"));
        }else if(this->list.indexOf("/") != -1){
            this->lowPriority("-", this->list.indexOf("-"));
        }
    }
}
// �˳�������
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
// �Ӽ�������
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

