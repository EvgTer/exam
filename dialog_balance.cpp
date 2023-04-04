#include "dialog_balance.h"
#include "ui_dialog_balance.h"

Dialog_balance::Dialog_balance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_balance)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("GGStore.db");
    if(db.open()){
        myQuery = new QSqlQuery(db);
    }

}

Dialog_balance::~Dialog_balance()
{
    delete ui;
}

void Dialog_balance::on_pushButton_show_clicked()
{
    QString name = ui->lineEdit_login->text();

    myQuery->exec("SELET login, balance from [Users];");
    while(myQuery->next()){
        QString login = myQuery->value(0).toString();
        float balance = myQuery->value(1).toFloat();
        if(name == login){
            ui->label_amount->setText(QString().setNum(balance));
            return;
        }
    }
}


void Dialog_balance::on_pushButton_clicked()
{
    QString name = ui->lineEdit_login->text();

    myQuery->exec("SELET login, balance from [Users];");
    while(myQuery->next()){
        QString login = myQuery->value(0).toString();
        float balance = myQuery->value(1).toFloat();
        if(name == login){
            float balance1 = ui->doubleSpinBox->value();
            myQuery->prepare("UPDATE [Users] SET balance = :balance WHERE login = :login;");
            myQuery->bindValue(":balance", balance + balance1);
            myQuery->bindValue(":login", login);
            if(myQuery->exec()){
                QMessageBox::about(this,"Add"," you succesfully increased your balance!");
                ui->label_amount->setText(QString().setNum(balance + balance1));
            }
            else{
                QMessageBox::about(this,"Add"," error with exec!");

            }
        }
    }

}

