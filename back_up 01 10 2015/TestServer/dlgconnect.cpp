#include "dlgconnect.h"
#include "ui_dlgconnect.h"

DlgConnect::DlgConnect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgConnect)
{
    ui->setupUi(this);
    QList<QHostAddress> list =  QNetworkInterface::allAddresses();
    foreach (QHostAddress var, list) {
       if(var.toString().startsWith("192.168."))
       {
           ui->lineEdit->setText(var.toString());
       }
    }
    ui->lineEdit_2->setText("2324");
}

DlgConnect::~DlgConnect()
{
    delete ui;
}

void DlgConnect::on_pushButton_clicked()
{
    this->strIp = ui->lineEdit->text();
    this->port = ui->lineEdit_2->text().toInt();
    close();
}

void DlgConnect::on_pushButton_2_clicked()
{
    close();
}

int DlgConnect::getPort()
{
    return this->port;
}

QString DlgConnect::getIp()
{
    return this->strIp;
}
