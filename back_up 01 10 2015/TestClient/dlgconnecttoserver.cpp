#include "dlgconnecttoserver.h"
#include "ui_dlgconnecttoserver.h"

DlgConnectToServer::DlgConnectToServer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgConnectToServer)
{
    ui->setupUi(this);
}

DlgConnectToServer::~DlgConnectToServer()
{
    delete ui;
}

void DlgConnectToServer::on_pushButtonConnect_clicked()
{
    this->strIp = ui->lineEditIP->text();
    this->strPort = ui->lineEditPort->text();

    int nError = cheakValues();
    if(nError == 0)
    {
        if(ui->lineEditIP_2->text().isEmpty())
        {
            QMessageBox::warning(NULL,"Error","Empty Line");
        }
        else if(ui->lineEditIP_3->text().isEmpty())
        {
            QMessageBox::warning(NULL,"Error","Empty Line");
        }
        else if(ui->lineEditIP_4->text().isEmpty())
        {
            QMessageBox::warning(NULL,"Error","Empty Line");
        }
        this->strInfo = ui->lineEditIP_2->text() + "," + ui->lineEditIP_3->text() + "," + ui->lineEditIP_4->text();
        this->close();
    }
    else
    {
        QString strErrorText;
        switch (nError) {
        case -1:
            strErrorText = "Error input port";
            break;
        case -2:
            strErrorText = "Empty Ip Addres";
            break;
        case -3:
            strErrorText = "Empty Port";
            break;
        case -4:
            strErrorText = "Error IpAddres";
            break;
        default:
            break;
        }
        QMessageBox::warning(NULL,"Error",strErrorText);
    }

}

void DlgConnectToServer::on_pushButtonClose_clicked()
{
    this->close();
}

QString DlgConnectToServer::getIpAdress()
{
    return this->strIp;
}

QString DlgConnectToServer::getPort()
{
    return this->strPort;
}

QString DlgConnectToServer::getInfo()
{
    return this->strInfo;
}

int DlgConnectToServer::cheakValues()
{
    if(this->strPort.isEmpty())
    {
        return -3; // empty port
    }
    bool isCh = false;
    this->strPort.toInt(&isCh);
    if(!isCh)
    {
        return -1;// eror port
    }

    isCh = false;

    if(this->strIp.isEmpty())
    {
        return -2;// empty
    }
    return 0;
}
