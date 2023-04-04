#ifndef DIALOG_BALANCE_H
#define DIALOG_BALANCE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QString>
namespace Ui {
class Dialog_balance;
}

class Dialog_balance : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_balance(QWidget *parent = nullptr);
    ~Dialog_balance();

private slots:

    void on_pushButton_show_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog_balance *ui;
    QSqlDatabase db; // DateBase GGStore
    QSqlQuery* myQuery; // for select

};

#endif // DIALOG_BALANCE_H
