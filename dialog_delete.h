#ifndef DIALOG_DELETE_H
#define DIALOG_DELETE_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class Dialog_delete;
}

class Dialog_delete : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_delete(QWidget *parent = nullptr);
    ~Dialog_delete();

private slots:
    void on_pushButton_del_clicked();

private:
    Ui::Dialog_delete *ui;
    QSqlDatabase db; // DateBase GGStore
    QSqlQuery* myQuery; // for select

};

#endif // DIALOG_DELETE_H
