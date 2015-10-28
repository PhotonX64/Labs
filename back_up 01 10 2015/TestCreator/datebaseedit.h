#ifndef DATEBASEEDIT_H
#define DATEBASEEDIT_H

#include <QSQL>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QSqlResult>
#include <QDebug>
#include <QMessageBox>

class dateBaseEdit
{
public:
    dateBaseEdit();
    bool connectTodateBase(QString strName,
                           QString strHost,
                           QString strUser,
                           QString strPasword,
                           int nPort);
    QStringList getSubject();
    void addSubject(QString strName);
    bool deleteSubject(QString strName);
    void addTestInSubject(
            QString strNameSubject,
            QString strQuest,
            QStringList strVar,
            QString strTrue
            );
    void deleteTestInSubject(
            QString strNameSubj,
            int num
            );
    QSqlQueryModel *refreshTest(QString strTest);
    void initTable();
    bool setSQLqueru(QString strQueru);
    QString strSubName ;
    QSqlDatabase dateBase;
    QSqlQueryModel* model;
};

#endif // DATEBASEEDIT_H
