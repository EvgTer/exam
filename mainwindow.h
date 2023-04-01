#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//system
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDialog>

//Accounts
#include "user.h"
#include "admin.h"

//Games
#include "adventure.h"
#include "horror.h"
#include "mmorpg.h"
#include "sandbox.h"
#include "shooter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void create_accounts();
    void create_store();

private slots:

    void on_pushButton_log_clicked();

    void on_pushButton_sign_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db; // DateBase GGStore
    QSqlQuery* myQuery; // for select

    QVector<Account*> accounts;
    QVector<Game*> store;

};
#endif // MAINWINDOW_H
