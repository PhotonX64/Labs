#include "varanswer.h"

VarAnswer::VarAnswer()
{
    this->strAnswer = "";
    this->isTrue = false;
}

VarAnswer::VarAnswer(QString strText, bool isTrue)
{
    this->strAnswer = strText;
    this->isTrue = isTrue;
}

QString VarAnswer::getAnswerText()
{
    return this->strAnswer;
}

bool VarAnswer::getIsTrue()
{
    return this->isTrue;
}

void VarAnswer::setAnswerText(QString strText)
{
    this->strAnswer = strText;
}

void VarAnswer::setIsTrue(bool isTrue)
{
    this->isTrue = isTrue;
}

