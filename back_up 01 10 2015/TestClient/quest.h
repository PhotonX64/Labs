#ifndef QUEST_H
#define QUEST_H

#include <QString>
#include <varanswer.h>
#include <QList>

class Quest
{
public:
    Quest();
    Quest(QString strQuestText);
    ~Quest();

    void setQuestText(QString str);
    QString getQuestText();

    void addAnswer(VarAnswer *pNew);
    VarAnswer *getAnswer(int index);

    inline int getSizeAnswer();
private:
    QString strQuestText;
    QList<VarAnswer*> listAnswer;
    int nLast;

};

#endif // QUEST_H
