#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTime>
#include <QMessageBox>
#include <QBitmap>
#include <QByteArray>
#include <itemclient.h>
#include <dlgconnect.h>
#include <QLineEdit>
#include <QFile>
#include <QDate>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    enum MessageCmd
    {
        Connect = 1,
        Disconnect,
        StartTest,
        FinishTest
    };

    Ui::MainWindow *ui;
    QTcpServer* m_ptcpServer;
    qint16 nextBlockData;
    QByteArray bitArray;
private:
    void sendMessageToClient(QTcpSocket* pSocket, const QString& str);
    QList<ItemCLient*> lClient;
    QLineEdit *pLineInf;
    void updateTableWidget();
    void writeLog(ItemCLient *var);
public slots:
    virtual void slotNewConnection();
    void slotReadClient();

public:
    void startServer(QString strIp, int nPort);
private slots:
    void on_actionStart_triggered();
    void on_actionFinish_triggered();
};

#endif // MAINWINDOW_H
