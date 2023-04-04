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

#include "dialog_addadv.h"
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

    void showTable_Store();
    void showTable_Library();

    void gamesToUsersLibrary(User* user);

private slots:

    void on_pushButton_log_clicked();

    void on_pushButton_sign_clicked();

    void on_actionAdventure_triggered();

    void getGame(Game* obj);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db; // DateBase GGStore
    QSqlQuery* myQuery; // for select
    QSqlQuery* myQuery1; // for select showTable_Library;
    QSqlQuery* myQuery2; // for select showTable_Library;
    QSqlQuery* myQuery3; // for select showTable_Library;

    QVector<Account*> accounts;
    QVector<Game*> store;
    Dialog_addAdv* foradv;
};
#endif // MAINWINDOW_H
