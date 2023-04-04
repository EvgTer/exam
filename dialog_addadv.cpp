#include "dialog_addadv.h"
#include "ui_dialog_addadv.h"

Dialog_addAdv::Dialog_addAdv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_addAdv)
{
    ui->setupUi(this);
}

Dialog_addAdv::~Dialog_addAdv()
{
    delete ui;
}

void Dialog_addAdv::on_pushButton_add_clicked()
{
    if(ui->radioButton_adv->isChecked() == true){

        QString name = ui->lineEdit_name->text();
        float price = ui->doubleSpinBox->value();
        QString publisher = ui->lineEdit_pub->text();
        int players = ui->lineEdit_extra->text().toInt();

        emit sendGame(new Adventure(name,price,publisher,players));

    }else if(ui->radioButton_hor->isChecked() == true){

        QString name = ui->lineEdit_name->text();
        float price = ui->doubleSpinBox->value();
        QString publisher = ui->lineEdit_pub->text();
        QString limit = ui->lineEdit_extra->text();

        emit sendGame(new Horror(name,price,publisher,limit));

    }else if(ui->radioButton_mmo->isChecked() == true){

        QString name = ui->lineEdit_name->text();
        float price = ui->doubleSpinBox->value();
        QString publisher = ui->lineEdit_pub->text();
        int rating = ui->lineEdit_extra->text().toInt();

        emit sendGame(new MMORPG(name,price,publisher,rating));

    }else if(ui->radioButton_sand->isChecked() == true){

        QString name = ui->lineEdit_name->text();
        float price = ui->doubleSpinBox->value();
        QString publisher = ui->lineEdit_pub->text();

        emit sendGame(new Sandbox(name,price,publisher));

    }else if(ui->radioButton_shoot->isChecked() == true){
        QString name = ui->lineEdit_name->text();
        float price = ui->doubleSpinBox->value();
        QString publisher = ui->lineEdit_pub->text();

        int weapon = ui->lineEdit_extra->text().toInt();

        emit sendGame(new Shooter(name,price,publisher,weapon));

    }

    throw "Error with pushButton add Game";
}

