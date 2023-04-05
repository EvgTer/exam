#include "dialog_balance.h"
#include "ui_dialog_balance.h"

Dialog_balance::Dialog_balance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_balance)
{
    ui->setupUi(this);
}

Dialog_balance::~Dialog_balance()
{
    delete ui;
}

/*void Dialog_balance::on_pushButton_show_clicked()
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
}*/


void Dialog_balance::on_pushButton_clicked()
{

    QString name = QString(ui->lineEdit_login->text());
    float balance = ui->doubleSpinBox->value();

    emit sendBalance(name, balance);
}

