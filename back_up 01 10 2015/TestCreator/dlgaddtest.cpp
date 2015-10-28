#include "dlgaddtest.h"
#include "ui_dlgaddtest.h"

DlgAddTest::DlgAddTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgAddTest)
{
    ui->setupUi(this);
    listVar.append(ui->textEdit_2);
    listVar.append(ui->textEdit_3);
    listVar.append(ui->textEdit_4);
    listVar.append(ui->textEdit_5);
    listVar.append(ui->textEdit_6);
    listVar.append(ui->textEdit_7);
    listVar.append(ui->textEdit_8);
    listVar.append(ui->textEdit_9);
    listBut.append(ui->radioButton);
    listBut.append(ui->radioButton_2);
    listBut.append(ui->radioButton_3);
    listBut.append(ui->radioButton_4);
    listBut.append(ui->radioButton_5);
    listBut.append(ui->radioButton_6);
    listBut.append(ui->radioButton_7);
    listBut.append(ui->radioButton_8);
    for(int i=0;i<listBut.size();i++)
    {
        listBut[i]->setAutoExclusive(false);
        listBut[i]->setText("Верный");
    }
}

DlgAddTest::~DlgAddTest()
{
    delete ui;
}

QString DlgAddTest::getStrText()
{
    return this->strText;
}

QStringList DlgAddTest::getVar()
{
    return this->varl;
}

QString DlgAddTest::getIsTrue()
{
    return this->strIsTrue;
}

void DlgAddTest::on_pushButton_2_clicked()
{
    close();
}

void DlgAddTest::on_pushButton_clicked()
{
    this->strText = ui->textEdit->document()->toPlainText();
    for(int i=0;i<8;i++)
    {
        varl << listVar[i]->document()->toPlainText();
        if(listBut[i]->isChecked())
        {
            if(this->strIsTrue.size() == 0)
                 this->strIsTrue.append(QString::number(i));
            else
            {
                 this->strIsTrue.append("," + QString::number(i));
            }
        }
    }
    close();
}

void DlgAddTest::on_tabWidget_currentChanged(int index)
{
    listVar[index]->setFocus();
}
