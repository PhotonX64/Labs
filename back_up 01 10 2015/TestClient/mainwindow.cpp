#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    baseLoader.connect(
                "dateTest",
                "localhost",
                "user",
                "123",
                5432);
    m_pTcpSocket = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString strIp;
    int port;
    DlgConnectToServer *pDlg = new DlgConnectToServer(this);
    pDlg->setModal(true);
    pDlg->exec();
    strIp = pDlg->getIpAdress();
    port = pDlg->getPort().toInt();
    QString sInfo = pDlg->getInfo();
    if(!strIp.isEmpty())// connect
    {
        startClient(strIp,port,sInfo);
    }
    delete pDlg;
}

void MainWindow::startClient(const QString &strHost, int nPort,QString strI)
{
    m_pTcpSocket = new QTcpSocket(this);

    m_pTcpSocket->connectToHost(strHost, nPort);
    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_pTcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
    connect(m_pTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this,         SLOT(slotError(QAbstractSocket::SocketError)));
    if(m_pTcpSocket != NULL)
    {
        ui->textEdit->append("Connect");
        autoIn(strI);
    }
}

void MainWindow::slotReadyRead()
{
    if(m_pTcpSocket == NULL)
        return;
    m_nNextBlockSize = 0;
    QDataStream in(m_pTcpSocket);
    in.setVersion(QDataStream::Qt_5_4);
    for (;;) {
        if (!m_nNextBlockSize) {
            if (m_pTcpSocket->bytesAvailable() < sizeof(qint16)) {
                break;
            }
            in >> m_nNextBlockSize;
        }

        if (m_pTcpSocket->bytesAvailable() < m_nNextBlockSize) {
            break;
        }
        QTime   time;
        QString str;
        in >> time >> str;
        m_nNextBlockSize = 0;
    }


}

void MainWindow::slotError(QAbstractSocket::SocketError err)
{
    QString strError =
            "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                             "The host was not found." :
                             err == QAbstractSocket::RemoteHostClosedError ?
                                 "The remote host is closed." :
                                 err == QAbstractSocket::ConnectionRefusedError ?
                                     "The connection was refused." :
                                     QString(m_pTcpSocket->errorString())
                                     );
    ui->textEdit->setText(strError);
}

void MainWindow::slotConnected()
{
    ui->statusBar->showMessage("Received the connected() signal");
}


void MainWindow::startTest(QString strTestName)
{
    if(m_pTcpSocket == NULL)
        return;
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_4);
    out <<qint16(0)<<(int)MainWindow::StartTest<<QTime::currentTime()<<strTestName;
    out.device()->seek(0);
    //вписываем размер блока на зарезервированное место
    out << (quint16)(arrBlock.size() - sizeof(quint16));
    m_pTcpSocket->write(arrBlock);
}

void MainWindow::finishTets(int result)
{
    if(m_pTcpSocket == NULL)
        return;
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_4);
    out <<qint16(0)<<(int)MainWindow::FinishTest<<QTime::currentTime()<<result;
    out.device()->seek(0);
    //вписываем размер блока на зарезервированное место
    out << (quint16)(arrBlock.size() - sizeof(quint16));
    m_pTcpSocket->write(arrBlock);
}

void MainWindow::closeEvent(QCloseEvent *)
{
    closeProgramm();
}

void MainWindow::closeProgramm()
{
    if(m_pTcpSocket == NULL)
        return;
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_4);
    out <<qint16(0)<<(int)MainWindow::Disconnect;
    out.device()->seek(0);
    //вписываем размер блока на зарезервированное место
    out << (quint16)(arrBlock.size() - sizeof(quint16));
    m_pTcpSocket->write(arrBlock);
}

void MainWindow::on_pushButton_2_clicked() // Test
{
    QString strTestName;
    DlgChoiseTest *pDialog = new DlgChoiseTest();
    pDialog->setModal(true);
    pDialog->setTestCh(baseLoader.getListTest());
    pDialog->setWindowTitle("Выбор теста");
    pDialog->exec();
    strTestName = pDialog->getChoise();
    delete pDialog;
    Test *pTest = baseLoader.getTest(strTestName);

    DlgTest *pDialogT = new DlgTest();

    pDialogT->setModal(true);
    pDialogT->setWindowTitle("Тест");
    pDialogT->setTest(pTest);
    startTest(strTestName);
    pDialogT->exec();
    int res = pDialogT->getResualt();
    finishTets(res);
    delete pDialogT;
    delete pTest;
}

void MainWindow::autoIn(QString info)
{
    if(m_pTcpSocket == NULL)
        return;
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_4);
    out <<qint16(0)<<(int)MainWindow::Connect<<info;
    out.device()->seek(0);
    //вписываем размер блока на зарезервированное место
    out << (quint16)(arrBlock.size() - sizeof(quint16));
    m_pTcpSocket->write(arrBlock);
}
