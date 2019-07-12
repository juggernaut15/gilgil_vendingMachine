#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeMoney(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::checkMoney(){
    if(money >= 200){
        ui->pbCoke->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
    }
    else if(money >= 150){
        ui->pbCoke->setEnabled(false);
        ui->pbTea->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
    }
    else if(money >= 100){
        ui->pbCoke->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCoffee->setEnabled(true);
    }
    else {
        ui->pbCoke->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCoffee->setEnabled(false);
    }
}
void Widget::changeMoney(int n){
    money += n;
    ui ->lcdNumber->display(money);
    checkMoney();
}
void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox msg;
    QString reset;
    int num10=0, num50=0, num100=0, num500=0;
    int m = money;
    money = 0;
    changeMoney(0);

    money = 0;
    while(m / 500 != 0){
        num500++;
        m -= 500;
    }
    while(m / 100 != 0){
        num100++;
        m -= 100;
    }
    while(m / 50 != 0){
        num50++;
        m -= 50;
    }
    while(m / 10 != 0){
        num10++;
        m -= 10;
    }

    reset.sprintf("500 : %d\n100 : %d\n50 : %d\n10 : %d",num500, num100, num50, num10);
    msg.information(nullptr, "reset", reset);
}
