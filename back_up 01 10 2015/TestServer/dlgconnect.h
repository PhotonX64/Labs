#ifndef DLGCONNECT_H
#define DLGCONNECT_H

#include <QDialog>
#include <QNetworkInterface>

namespace Ui {
class DlgConnect;
}

class DlgConnect : public QDialog
{
    Q_OBJECT

public:
    explicit DlgConnect(QWidget *parent = 0);
    ~DlgConnect();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DlgConnect *ui;
    QString strIp;
    int port;
public:
    int getPort();
    QString getIp();
};

#endif // DLGCONNECT_H
