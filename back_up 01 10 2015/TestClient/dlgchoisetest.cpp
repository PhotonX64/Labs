#include "dlgchoisetest.h"
#include "ui_dlgchoisetest.h"

DlgChoiseTest::DlgChoiseTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgChoiseTest)
{
    ui->setupUi(this);
}

DlgChoiseTest::~DlgChoiseTest()
{
    delete ui;
}

void DlgChoiseTest::setTestCh(QStringList textL)
{
    ui->listWidget->clear();
    foreach (QString var, textL) {
       ui->listWidget->addItem(var);
    }
}

QString DlgChoiseTest::getChoise()
{
    return this->chT;
}

void DlgChoiseTest::on_pushButton_clicked()
{
   if(ui->listWidget->currentItem() != NULL)
   {
       chT = ui->listWidget->currentItem()->text();
   }
   close();
}

void DlgChoiseTest::on_pushButton_2_clicked()
{
    close();
}
