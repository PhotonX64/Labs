#ifndef DLGCHOISETEST_H
#define DLGCHOISETEST_H

#include <QDialog>

namespace Ui {
class DlgChoiseTest;
}

class DlgChoiseTest : public QDialog
{
    Q_OBJECT

public:
    explicit DlgChoiseTest(QWidget *parent = 0);
    ~DlgChoiseTest();
    void setTestCh(QStringList textL);
    QString getChoise();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DlgChoiseTest *ui;
    QString chT;
};

#endif // DLGCHOISETEST_H
