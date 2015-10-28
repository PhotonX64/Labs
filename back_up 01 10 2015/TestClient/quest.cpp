#include "quest.h"

Quest::Quest()
{
    nLast = 0;
}

Quest::Quest(QString strQuestText)
{
    this->strQuestText = strQuestText;
    nLast = 0;
}

Quest::~Quest()
{
}

void Quest::setQuestText(QString str)
{
    this->strQuestText = str;
}

QString Quest::getQuestText()
{
    return this->strQuestText;
}

void Quest::addAnswer(VarAnswer *pNew)
{
    if(nLast == 8)
        return;
    this->listAnswer.append(pNew);
    nLast++;
}

VarAnswer *Quest::getAnswer(int index)
{
    if(index >= 8)
        return NULL;
    return this->listAnswer.at(index);
}

int Quest::getSizeAnswer()
{
    return 8;
}

