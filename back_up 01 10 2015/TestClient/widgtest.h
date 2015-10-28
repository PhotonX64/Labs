#ifndef WIDGTEST_H
#define WIDGTEST_H

#include <QWidget>
#include <QRadioButton>

namespace Ui {
class WidgTest;
}

class WidgTest : public QWidget
{
    Q_OBJECT

public:
    explicit WidgTest(QWidget *parent = 0);
    ~WidgTest();
    void setTextQuest(QString str);
    void setVarAnsw(QString str,int index,bool isTrue);
    bool isTrue();
private:
    Ui::WidgTest *ui;
    QList<QRadioButton*> listRadBut;
    QList<int> listAnsw;
};

#endif // WIDGTEST_H
