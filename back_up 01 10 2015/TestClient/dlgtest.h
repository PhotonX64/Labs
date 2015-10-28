#ifndef DLGTEST_H
#define DLGTEST_H

#include <QDialog>
#include <widgtest.h>
#include <test.h>
#include <QHBoxLayout>

namespace Ui {
class DlgTest;
}

class DlgTest : public QDialog
{
    Q_OBJECT

public:
    explicit DlgTest(QWidget *parent = 0);
    ~DlgTest();
    void setTest(Test *pTest);
    int getResualt();
private slots:
    void on_pushButtonBack_clicked();

    void on_pushButtonForvard_clicked();

    void on_pushButton_clicked();

private:
    Ui::DlgTest *ui;
    Test *pTest;
    int curentPage = 0;
    int cntPage;
    int result;
    QList<WidgTest *> listWidget;

private:
    void initTestView();


};

#endif // DLGTEST_H
