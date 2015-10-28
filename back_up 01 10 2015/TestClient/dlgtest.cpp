#include "dlgtest.h"
#include "ui_dlgtest.h"
#include <qdebug.h>

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

void DlgTest::setTest(Test *pTest)
{
    this->pTest = pTest;
    initTestView();
}

int DlgTest::getResualt()
{
    return this->result;
}

void DlgTest::initTestView()
{
    int count = this->pTest->getCount();
    ui->label->setText("1/" + QString::number(count));
    qDebug() << count;
    cntPage = count;
    for(int i=0;i<count;i++)
    {
        WidgTest *pNew = new WidgTest();
        Quest * pQ = pTest->getQuest(i);
        pNew->setTextQuest(pQ->getQuestText());
        for(int k=0;k<8;k++)
        {
            if(!pQ->getAnswer(k)->getAnswerText().isEmpty())
                pNew->setVarAnsw(pQ->getAnswer(k)->getAnswerText(),k,
                                 pQ->getAnswer(k)->getIsTrue()
                                 );
        }
        QWidget *w = new QWidget();
        QHBoxLayout *l = new QHBoxLayout();
        l->addWidget(pNew);
        l->setMargin(0);
        w->setLayout(l);
        listWidget.append(pNew);
        ui->stackedWidget->addWidget(w);
    }
    ui->stackedWidget->setCurrentIndex(0);
}


void DlgTest::on_pushButtonBack_clicked()
{
    if(curentPage == 0)
        curentPage = cntPage - 1;
    else
    {
        curentPage --;
    }
    ui->label->setText(QString::number(curentPage+1)+"/" +QString::number(pTest->getCount()));
    ui->stackedWidget->setCurrentIndex(curentPage);
}

void DlgTest::on_pushButtonForvard_clicked()
{
    if(curentPage == cntPage - 1)
        curentPage = 0;
    else
    {
        curentPage ++;
    }
    ui->label->setText(QString::number(curentPage+1)+"/" +QString::number(pTest->getCount()));
    ui->stackedWidget->setCurrentIndex(curentPage);
}

void DlgTest::on_pushButton_clicked()
{
    this->result = 0;
    for(int i =0 ; i < pTest->getCount(); i++)
    {
        ui->stackedWidget->setCurrentIndex(i);
        if(listWidget[i]->isTrue())
        {
            this->result ++;
        }
    }
    close();
}
