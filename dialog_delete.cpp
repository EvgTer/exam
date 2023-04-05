#include "dialog_delete.h"
#include "ui_dialog_delete.h"

Dialog_delete::Dialog_delete(QWidget *parent) :
    QDialog(parent),
   ui(new Ui::Dialog_delete)
{
    ui->setupUi(this);
}

Dialog_delete::~Dialog_delete()
{
    delete ui;
}

void Dialog_delete::on_pushButton_del_clicked()
{
    QString name = ui->lineEdit_name->text();

    emit sendDel(name);
}

