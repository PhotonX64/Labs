#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <datebaseedit.h>
#include <dlgaddtest.h>
#include <dlgtest.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionAddTest_triggered();

    void on_actionReload_triggered();

    void on_actionRefresh_triggered();

    void on_listWidget_currentRowChanged(int currentRow);

    void on_action_2_triggered();

    void on_action_triggered();

private:
    Ui::MainWindow *ui;
    dateBaseEdit  dateBase;
};

#endif // MAINWINDOW_H
