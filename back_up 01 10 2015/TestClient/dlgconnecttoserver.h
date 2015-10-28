#ifndef DLGCONNECTTOSERVER_H
#define DLGCONNECTTOSERVER_H

#include <QString>
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class DlgConnectToServer;
}

class DlgConnectToServer : public QDialog
{
    Q_OBJECT

public:
    explicit DlgConnectToServer(QWidget *parent = 0);
    ~DlgConnectToServer();

private slots:
    void on_pushButtonConnect_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::DlgConnectToServer *ui;

private:
    QString strIp;
    QString strPort;
    QString strInfo;

public:
    QString getIpAdress();
    QString getPort();
    QString getInfo();
private:
    int cheakValues();
};

#endif // DLGCONNECTTOSERVER_H
