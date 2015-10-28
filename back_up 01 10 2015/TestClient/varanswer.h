#ifndef VARANSWER_H
#define VARANSWER_H

#include <QString>

class VarAnswer
{
public:
    VarAnswer();
    VarAnswer(QString strText,bool isTrue);

    QString getAnswerText();
    bool getIsTrue();

    void setAnswerText(QString strText);
    void setIsTrue(bool isTrue);

private:
    QString strAnswer;
    bool isTrue;
};

#endif // VARANSWER_H
