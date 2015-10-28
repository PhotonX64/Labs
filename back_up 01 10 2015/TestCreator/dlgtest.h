#ifndef DLGTEST_H
#define DLGTEST_H

#include <QDialog>

namespace Ui {
class DlgTest;
}

class DlgTest : public QDialog
{
    Q_OBJECT

public:
    explicit DlgTest(QWidget *parent = 0);
    ~DlgTest();
    QString getNameTest();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::DlgTest *ui;
    QString strName;
};

#endif // DLGTEST_H
