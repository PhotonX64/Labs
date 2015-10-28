#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dlgconnecttoserver.h>
#include <QTcpSocket>
#include <QTime>
#include <datebaseloader.h>
#include <dlgchoisetest.h>
#include <dlgtest.h>
#include <test.h>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum MessageCmd
    {
        Connect = 1,
        Disconnect,
        StartTest,
        FinishTest
    };
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *m_pTcpSocket;
    qint16 m_nNextBlockSize;
    DateBaseLoader baseLoader;
private:
    void startClient(const QString& strHost,int nPort,QString strI);
    void autoIn(QString info);
    void startTest(QString strTestName);
    void finishTets(int result);
    void closeEvent(QCloseEvent *);
    void closeProgramm();
private slots:
    void slotReadyRead   ();
    void slotError       (QAbstractSocket::SocketError);
    void slotConnected   ();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
