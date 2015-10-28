#include "datebaseedit.h"

dateBaseEdit::dateBaseEdit()
{
    this->model = NULL;
    strSubName = "Subj";
}

bool dateBaseEdit::connectTodateBase(QString strName, QString strHost,
                                     QString strUser, QString strPasword,
                                     int nPort)
{
    if(this->model == NULL)
    {
        this->model = new QSqlQueryModel();
    }
    this->dateBase = QSqlDatabase::addDatabase("QSQLITE");
    this->dateBase.setDatabaseName(strName);
    this->dateBase.setHostName(strHost);
    this->dateBase.setUserName(strUser);
    this->dateBase.setPort(nPort);
    this->dateBase.setPassword(strPasword);
    if(!this->dateBase.open())
    {
        QMessageBox::critical(NULL,"Error",this->dateBase.lastError().text());
        return false;
    }

    return true;
}

QStringList dateBaseEdit::getSubject()
{
    QString strQuery =
            "SELECT * FROM \""+this->strSubName+"\"";
    model->setQuery(strQuery);
    QStringList strList;
    int cnt = model->rowCount();
    for(int i=0;i<cnt;i++)
    {
        strList << model->data(model->index(i,0)).toString();
    }
    return strList;
}

void dateBaseEdit::addSubject(QString strName)
{
    QString strQuery=
            "INSERT INTO \"" +
            this->strSubName + "\"(name) VALUES ('" + strName +"')";
    setSQLqueru(strQuery);
    QString strCreate = "CREATE TABLE \"" + strName + "\" "
                                                      "(\"Quest\" varchar(300),"
                                                      "\"varanswer1\" varchar(300),"
                                                      "\"varanswer2\" varchar(300),"
                                                      "\"varanswer3\" varchar(300),"
                                                      "\"varanswer4\" varchar(300),"
                                                      "\"varanswer5\" varchar(300),"
                                                      "\"varanswer6\" varchar(300),"
                                                      "\"varanswer7\" varchar(300),"
                                                      "\"varanswer8\" varchar(300),"
                                                      "\"answertrue\" varchar(50))";
    setSQLqueru(strCreate);
}

bool dateBaseEdit::deleteSubject(QString strName)
{
    QString strQuery =
            "DELETE FROM  \"" + this->strSubName +"\"  WHERE  \"Test\" = '" + strName +"'";
    setSQLqueru(strQuery);
    QString strQ = "DROP TABLE \"" + strName + "\"";
    setSQLqueru(strQ);
}

void dateBaseEdit::addTestInSubject(QString strNameSubject, QString strQuest, QStringList strVar, QString strTrue)
{
    QString strQ =
            "INSERT INTO \""+strNameSubject+"\"(Quest, varanswer1, varanswer2, varanswer3, varanswer4, varanswer5, varanswer6 ,varanswer7 , varanswer8 , answertrue) VALUES('" + strQuest + "', '" + strVar.at(0) + "', '" + strVar.at(1) + "', '" + strVar.at(2) + "', '" + strVar.at(3) + "', '" + strVar.at(4) + "', '" + strVar.at(5) + "', '" + strVar.at(6) + "', '" + strVar.at(7) + "', '" + strTrue + "')";
    qDebug() << strQ;
    setSQLqueru(strQ);
}

void dateBaseEdit::deleteTestInSubject(QString strNameSubj, int num)
{

}

QSqlQueryModel *dateBaseEdit::refreshTest(QString strTest)
{
    QSqlQueryModel *pM = new QSqlQueryModel();
    pM->setQuery("SELECT * FROM \"" + strTest + "\"");
    return pM;
}

void dateBaseEdit::initTable()
{
    QString str = "CREATE TABLE \"Subj\" (name VARCHAR(100))";
    setSQLqueru(str);
}

bool dateBaseEdit::setSQLqueru(QString strQueru)
{
    QSqlQuery query;
    if(!query.exec(strQueru))
    {

        QMessageBox::warning(NULL,"Error","error SQL command " + query.lastError().text());
        return false;
    }
    return true;
}

