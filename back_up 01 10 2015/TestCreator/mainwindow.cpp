#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dateBase.connectTodateBase(
                "dateTest",
                "localhost",
                "user",
                "123",
                5432
                );
   //dateBase.initTable();
   on_actionReload_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAddTest_triggered()
{
    DlgAddTest *pAdd = new DlgAddTest();
    pAdd->setModal(true);
    pAdd->exec();
    QString strN = pAdd->getStrText();
    if(strN.isEmpty())
        return;
    QStringList list = pAdd->getVar();
    QString strT = pAdd->getIsTrue();
    QString name = ui->listWidget->item(ui->listWidget->currentRow())->text();
    dateBase.addTestInSubject(name,strN,list,strT);
    on_actionRefresh_triggered();
}

void MainWindow::on_actionReload_triggered()
{
    ui->listWidget->blockSignals(true);
    ui->listWidget->clear();
    QStringList list = dateBase.getSubject();
    foreach (QString var, list) {
        ui->listWidget->addItem(var);
    }
    ui->listWidget->blockSignals(false);
}

void MainWindow::on_actionRefresh_triggered()
{
    if(ui->listWidget->currentRow() >= 0)
    {
        QString str = ui->listWidget->item(ui->listWidget->currentRow())->text();
        if(!str.isEmpty())
            ui->tableView->setModel(dateBase.refreshTest(str));
    }
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    QString str = ui->listWidget->item(currentRow)->text();
    if(!str.isEmpty())
        ui->tableView->setModel(dateBase.refreshTest(str));
}

void MainWindow::on_action_2_triggered()
{
    dateBase.initTable();
}

void MainWindow::on_action_triggered()
{
    DlgTest *pDialog = new DlgTest();
    pDialog->setModal(true);
    pDialog->exec();
    QString strN = pDialog->getNameTest();
    if(!strN.isEmpty())
        dateBase.addSubject(strN);
    delete pDialog;
    on_actionReload_triggered();
}
