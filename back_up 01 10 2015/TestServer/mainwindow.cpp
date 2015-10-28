#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pLineInf = new QLineEdit();
    pLineInf->setReadOnly(true);
    ui->mainToolBar->addWidget(pLineInf);
}

MainWindow::~MainWindow()
{
    delete ui;
    foreach (ItemCLient *var, lClient) {
        var->getSocket()->close();
    }
    lClient.clear();
}

void MainWindow::sendMessageToClient(QTcpSocket *pSocket, const QString &str)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_4);
    out << qint16(0) << str;

    out.device()->seek(0);
    out << qint16(arrBlock.size() - sizeof(qint16));

    pSocket->write(arrBlock);
}

void MainWindow::updateTableWidget()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setRowCount(this->lClient.size());

    QStringList lLabel;
    lLabel << "Студент" << "Группа" << "Тест" << "Начало теста" << "Конец теста" <<"Результат";

    ui->tableWidget->setHorizontalHeaderLabels(lLabel);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->tableWidget->verticalHeader()->setVisible(true);

    ui->tableWidget->setColumnWidth(0,150);
    ui->tableWidget->setColumnWidth(1,100);
    ui->tableWidget->setColumnWidth(2,100);
    ui->tableWidget->setColumnWidth(3,100);
    ui->tableWidget->setColumnWidth(4,100);
    ui->tableWidget->setColumnWidth(5,100);

    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    int r = 0;
    foreach (ItemCLient *var, lClient) {
        ui->tableWidget->setItem(r,0,new QTableWidgetItem(var->getName() + " " + var->getFIO()));
        ui->tableWidget->setItem(r,1,new QTableWidgetItem(var->getGroup()));
        ui->tableWidget->setItem(r,2,new QTableWidgetItem(var->getStrName()));
        ui->tableWidget->setItem(r,3,new QTableWidgetItem(var->getStartTime().toString()));
        ui->tableWidget->setItem(r,4,new QTableWidgetItem(var->getFinishTime().toString()));
        if(var->getResult() == -1)
            ui->tableWidget->setItem(r,5,new QTableWidgetItem(" "));
        else
            ui->tableWidget->setItem(r,5,new QTableWidgetItem(QString::number(var->getResult())));
        r++;
    }
}

void MainWindow::writeLog(ItemCLient *var)
{
    QFile *pFile = new QFile("log/Log_"+QDate::currentDate().toString()+".txt");
    if(!pFile->open(QIODevice::Append | QIODevice::Text))
    {
        return;
    }
    QTextStream out(pFile);
    out <<"\n" + var->getFIO() + " " + var->getName() + "  " + var->getStrName() + " " +
           var->getStartTime().toString() + " " + var->getFinishTime().toString() +
           " " + QString::number(var->getResult()) + "\n";
    pFile->close();
    delete pFile;
}

void MainWindow::slotNewConnection()
{
    QTcpSocket *pClientSocket = m_ptcpServer->nextPendingConnection();
    connect(pClientSocket, SIGNAL(disconnected()),
            pClientSocket, SLOT(deleteLater()));
    connect(pClientSocket, SIGNAL(readyRead()),
            this,          SLOT(slotReadClient()));
}

void MainWindow::slotReadClient()
{
    QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    int mod;

    if(pClientSocket == NULL)
    {
        ui->statusBar->showMessage("ERROR NULL SOCKET!!!");
        return;
    }
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_5_3);
    for (;;) {
        if(nextBlockData == 0)
        {
            if(pClientSocket->bytesAvailable() < (int)sizeof(qint16))
            {
                break;
            }
            in >> nextBlockData;
        }
        if(pClientSocket->bytesAvailable() < nextBlockData)
            break;
        else
        {
            nextBlockData = 0;
            in >> mod;

            if(mod == MainWindow::Connect)
            {
                QString strInfo;
                in >> strInfo;
                QStringList lStr = strInfo.split(",");
                foreach (ItemCLient *var, lClient) {
                    if(var->getSocket() == pClientSocket)
                        return;
                }
                ItemCLient *pNew = new ItemCLient(lStr[0],lStr[1],lStr[2]);
                pNew->setSocket(pClientSocket);
                lClient.append(pNew);
                updateTableWidget();
            }
            else if(mod == MainWindow::Disconnect)
            {
                foreach (ItemCLient *var, lClient) {
                    if(var->getSocket() == pClientSocket)
                    {
                        lClient.removeAll(var);
                        break;
                    }
                }
                updateTableWidget();
            }
            else if(mod == MainWindow::StartTest)
            {
                QString strInfo;
                QTime startD;
                in >> startD >>strInfo;
                foreach (ItemCLient *var, lClient) {
                    if(var->getSocket() == pClientSocket)
                    {
                        var->setTestName(strInfo);
                        var->setStartTime(startD);
                        updateTableWidget();
                    }
                }
            }
            else if(mod == MainWindow::FinishTest)
            {
                int result;
                QTime finishD;
                in >> finishD >> result;
                foreach (ItemCLient *var, lClient) {
                    if(var->getSocket() == pClientSocket)
                    {
                        var->setResult(result);
                        var->setFinishTime(finishD);
                        writeLog(var);
                        updateTableWidget();
                    }
                }
            }
            else if(mod == MainWindow::Disconnect)
            {
                foreach (ItemCLient *var, lClient) {
                    if(var->getSocket() == pClientSocket)
                    {
                        pClientSocket->close();
                        lClient.removeAll(var);
                    }
                }
            }
        }
    }
}

void MainWindow::startServer(QString strIp, int nPort)
{
    this->m_ptcpServer = new QTcpServer(this);
    //QHostAddress::Any
    if (!m_ptcpServer->listen(QHostAddress(strIp), nPort)) {
        QMessageBox::critical(0,
                              "Server Error",
                              "Unable to start the server:"
                              + m_ptcpServer->errorString()
                              );
        m_ptcpServer->close();
        return;
    }
    connect(m_ptcpServer, SIGNAL(newConnection()),
            this,         SLOT(slotNewConnection()));
    this->nextBlockData = 0;
    this->bitArray.clear();
    QString strPort;
    strPort = QString::number((int)m_ptcpServer->serverPort());
    strIp = m_ptcpServer->serverAddress().toString();
    pLineInf->setText("IP: " + strIp + " Port: " + strPort );
}

void MainWindow::on_actionStart_triggered()
{
    DlgConnect *pD = new DlgConnect();
    pD->setModal(true);
    pD->setWindowTitle("Start server");
    pD->exec();
    QString strI = pD->getIp();
    int p = pD->getPort();
    if(!strI.isEmpty())
    {
        startServer(strI,p);
    }
}

void MainWindow::on_actionFinish_triggered()
{
    this->m_ptcpServer->close();
}
