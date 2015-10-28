#ifndef ITEMCLIENT_H
#define ITEMCLIENT_H

#include <QTime>
#include <QString>
#include <QTcpSocket>

class ItemCLient
{
public:
    ItemCLient(QString strN,QString strF,QString strG);
private:
    QString strName;
    QString sreFIO;
    QString strGroup;
    QTcpSocket *pSocket;
    QTime startTest;
    QTime finishTest;
    int result;
    QString strTestName;
public:
    QString getName();
    QString getFIO();
    QString getGroup();

    void setStartTime(QTime in);
    void setFinishTime(QTime in);
    void setResult(int r);
    void setTestName(QString strName);

    QTime getStartTime();
    QTime getFinishTime();
    int getResult();
    QString getStrName();

    void setSocket(QTcpSocket *p);
    QTcpSocket *getSocket();
};

#endif // ITEMCLIENT_H
