#ifndef DIALOG_ADDADV_H
#define DIALOG_ADDADV_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#include "adventure.h"
#include "horror.h"
#include "mmorpg.h"
#include "sandbox.h"
#include "shooter.h"
namespace Ui {
class Dialog_addAdv;
}

class Dialog_addAdv : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_addAdv(QWidget *parent = nullptr);
    ~Dialog_addAdv();
signals:
    void sendGame(Game* obj);
private slots:
    void on_pushButton_add_clicked();

private:
    Ui::Dialog_addAdv *ui;
    QSqlDatabase db; // DateBase GGStore
    QSqlQuery* myQuery; // for select

};

#endif // DIALOG_ADDADV_H
