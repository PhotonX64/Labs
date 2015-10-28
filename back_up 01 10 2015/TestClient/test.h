#ifndef TEST_H
#define TEST_H

#include <quest.h>
#include <QList>

class Test
{
public:
    Test();
    ~Test();

    void addQuest(Quest *pNew);
    int getCount();
    Quest *getQuest(int index);
private:
    int count;
    int trueAnswer;
    QList<Quest*> arrQuest;
};

#endif // TEST_H
