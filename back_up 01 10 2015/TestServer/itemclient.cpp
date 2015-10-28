#include "itemclient.h"

ItemCLient::ItemCLient(QString strN, QString strF, QString strG)
{
    this->strName = strN;
    this->sreFIO = strF;
    this->strGroup = strG;
    this->pSocket = NULL;
    this->result = -1;
}

QString ItemCLient::getName()
{
    return this->strName;
}

QString ItemCLient::getFIO()
{
    return this->sreFIO;
}

QString ItemCLient::getGroup()
{
    return this->strGroup;
}

void ItemCLient::setStartTime(QTime in)
{
    this->startTest = in;
}

void ItemCLient::setFinishTime(QTime in)
{
    this->finishTest = in;
}

void ItemCLient::setResult(int r)
{
    this->result = r;
}

void ItemCLient::setTestName(QString strName)
{
    this->strTestName = strName;
}

QTime ItemCLient::getStartTime()
{
    return startTest;
}

QTime ItemCLient::getFinishTime()
{
    return finishTest;
}

int ItemCLient::getResult()
{
    return result;
}

QString ItemCLient::getStrName()
{
    return this->strTestName;
}

void ItemCLient::setSocket(QTcpSocket *p)
{
    this->pSocket = p;
}

QTcpSocket *ItemCLient::getSocket()
{
    return this->pSocket;
}

