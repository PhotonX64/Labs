#include "datebaseloader.h"
#include <qdebug.h>
DateBaseLoader::DateBaseLoader()
{
    model = new QSqlQueryModel();
}

DateBaseLoader::DateBaseLoader(QString name, QString host, QString user, QString pass, int port)
{
    connect(name,host,user,pass,port);
    model = new QSqlQueryModel();
}

bool DateBaseLoader::connect(QString name, QString host, QString user, QString pass, int port)
{
    this->dateBase = QSqlDatabase::addDatabase("QSQLITE");
    this->dateBase.setDatabaseName(name);
    this->dateBase.setHostName(host);
    this->dateBase.setUserName(user);
    this->dateBase.setPassword(pass);
    this->dateBase.setPort(port);

    if(!this->dateBase.open())
    {
        QMessageBox::warning(NULL,"Open error datebase",this->dateBase.lastError().text());
        return false;
    }
    return true;
}

QStringList DateBaseLoader::getListTest()
{
    model->setQuery("SELECT * FROM \"Subj\"");
    QStringList list;
    int cntRow = model->rowCount();
    for(int i=0;i<cntRow;i++)
    {
        list.append(model->data(model->index(i,0)).toString());
    }
    return list;
}

Test *DateBaseLoader::getTest(QString strTest)
{
    model->setQuery("SELECT * FROM \"" + strTest + "\"");
        int rowCnt = model->rowCount();
        QList<int> lRnd = getRandVariant(3, rowCnt);
        Test *pNew = new Test();
        foreach(int i,lRnd)
        {
            Quest *pQuest = new Quest();
            pQuest->setQuestText(model->data(model->index(i,0)).toString());
            for(int k=0;k<8;k++)
            {
                VarAnswer *pVar = new VarAnswer();
                pVar->setAnswerText(model->data(model->index(i,k+1)).toString());
                pVar->setIsTrue(false);
                pQuest->addAnswer(pVar);
            }
            QString strAnswerTrue = model->data(model->index(i,9)).toString();
            QStringList lAnsw = strAnswerTrue.split(",");
            foreach (QString var, lAnsw)
            {
                pQuest->getAnswer(var.toInt())->setIsTrue(true);
            }
            pNew->addQuest(pQuest);
        }
        return pNew;
}

QList<int> DateBaseLoader::getRandVariant(int count, int maxIndex)
{
    QList<int> lVRand;
    if(count > maxIndex)
        return lVRand;
    int rndIndex = 0;
    bool bAdd = false;
    while(lVRand.size() != count)
    {
        bAdd = true;
        rndIndex = qrand() % maxIndex;
        foreach (int index, lVRand) {
            if(index == rndIndex)
                bAdd = false;
        }
        if(bAdd)
            lVRand.append(rndIndex);
    }
    return lVRand;
}

