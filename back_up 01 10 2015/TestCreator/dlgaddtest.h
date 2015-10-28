#ifndef DLGADDTEST_H
#define DLGADDTEST_H

#include <QDialog>
#include <QTextEdit>
#include <QRadioButton>

namespace Ui {
class DlgAddTest;
}

class DlgAddTest : public QDialog
{
    Q_OBJECT

public:
    explicit DlgAddTest(QWidget *parent = 0);
    ~DlgAddTest();

    QString getStrText();
    QStringList getVar();
    QString getIsTrue();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::DlgAddTest *ui;
    QList<QTextEdit *> listVar;
    QList<QRadioButton *> listBut;
    QString strText;
    QStringList varl;
    QString strIsTrue;
};

#endif // DLGADDTEST_H
