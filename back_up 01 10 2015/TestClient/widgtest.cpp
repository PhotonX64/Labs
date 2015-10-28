#include "widgtest.h"
#include "ui_widgtest.h"

#include <QDebug>

WidgTest::WidgTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgTest)
{
    ui->setupUi(this);
    listRadBut.append(ui->radioButton);
    listRadBut.append(ui->radioButton_2);
    listRadBut.append(ui->radioButton_3);
    listRadBut.append(ui->radioButton_4);
    listRadBut.append(ui->radioButton_5);
    listRadBut.append(ui->radioButton_6);
    listRadBut.append(ui->radioButton_7);
    listRadBut.append(ui->radioButton_8);
    for(int i=0;i<8;i++)
    {
        listRadBut[i]->setVisible(false);
    }
}

WidgTest::~WidgTest()
{
    delete ui;
}

void WidgTest::setTextQuest(QString str)
{
    ui->textEdit->setText(str);
}

void WidgTest::setVarAnsw(QString str, int index,bool isTrue)
{
    listRadBut[index]->setText(str);
    listRadBut[index]->setVisible(true);
    if(isTrue)
        listAnsw.append(index);
}

bool WidgTest::isTrue()
{
   int ct = 0;
   QList<int> lTrue;
   QList<int> lAnsw;
   int vis = 0;
   for(int i=0;i<listRadBut.size();i++)
   {
       if(listRadBut[i]->isVisible())
           vis++;
   }
   for(int i=0;i<vis;i++)
   {
       if(listRadBut[i]->isChecked())
           lAnsw.append(1);
       else
           lAnsw.append(0);
   }
   for(int i=0;i<vis;i++)
   {
        if(i == listAnsw[ct])
        {
            lTrue.append(1);
            ct ++;
        }
        else
        {
            lTrue.append(0);
        }
   }
   qDebug() << "----------------------"<<vis;
   for(int i=0;i<vis;i++)
   {
       qDebug() << lTrue[i] << lAnsw[i];
       if(lTrue[i] != lAnsw[i])
       {
           return false;
       }
   }
   qDebug() << "----------------------";
   return true;
}
