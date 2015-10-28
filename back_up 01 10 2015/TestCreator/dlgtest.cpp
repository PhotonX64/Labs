#include "dlgtest.h"
#include "ui_dlgtest.h"

DlgTest::DlgTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgTest)
{
    ui->setupUi(this);
}

DlgTest::~DlgTest()
{
    delete ui;
}

QString DlgTest::getNameTest()
{
    return this->strName;
}

void DlgTest::on_pushButton_add_clicked()
{
    QString str = ui->lineEdit->text();
    if(str.isEmpty())
        return;
    this->strName = str;
    close();
}

void DlgTest::on_pushButton_close_clicked()
{
    close();
}
