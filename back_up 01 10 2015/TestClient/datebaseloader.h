#ifndef DATEBASELOADER_H
#define DATEBASELOADER_H

#include <QSQL>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QSqlResult>
#include <QObject>
#include <QMessageBox>
#include "test.h"

class DateBaseLoader
{
public:
    DateBaseLoader();
    DateBaseLoader(QString name,QString host,QString user,QString pass,int port);

    bool connect(QString name,QString host,QString user,QString pass,int port);
    QStringList getListTest();
    Test *getTest(QString strTest);

private:
    QSqlDatabase dateBase;
    QSqlQueryModel* model;
    int size_Test;
private:
    QList<int> getRandVariant(int count,int maxIndex);
};

#endif // DATEBASELOADER_H
