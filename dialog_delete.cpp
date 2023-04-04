#include "dialog_delete.h"
#include "ui_dialog_delete.h"

Dialog_delete::Dialog_delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_delete)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("GGStore.db");
    if(db.open()){
        myQuery = new QSqlQuery(db);
    }

}

Dialog_delete::~Dialog_delete()
{
    delete ui;
}

void Dialog_delete::on_pushButton_del_clicked()
{
    QString name = ui->lineEdit_name->text();

    try{
    //Adventure
    myQuery->exec("SELECT name FROM [Adventures];");
    while(myQuery->next()){
        QString nameG = myQuery->value(0).toString();

        if(name == nameG){
            myQuery->prepare("DELETE FROM [Adventures] where name = :nameG;");
            myQuery->bindValue(":nameG", name);
            if(myQuery->exec()){
                QMessageBox::about(this,"Delete",name + " succesfuly deleted!");
            }
            else{
                QMessageBox::about(this,"Delete",name + " deleting went wrong!");
            }
            return;
        }

    }
    //Horror
    myQuery->exec("SELECT name FROM [Horrors];");
    while(myQuery->next()){
        QString nameG = myQuery->value(0).toString();

        if(name == nameG){
            myQuery->prepare("DELETE FROM [Horrors] where name = :nameG;");
            myQuery->bindValue(":nameG", name);
            if(myQuery->exec()){
                QMessageBox::about(this,"Delete",name + " succesfuly deleted!");
            }
            else{
                QMessageBox::about(this,"Delete",name + " deleting went wrong!");
            }
            return;
        }

    }
    //MMORPG
    myQuery->exec("SELECT name FROM [MMORPGs];");
    while(myQuery->next()){
        QString nameG = myQuery->value(0).toString();

        if(name == nameG){
            myQuery->prepare("DELETE FROM [MMORPGs] where name = :nameG;");
            myQuery->bindValue(":nameG", name);
            if(myQuery->exec()){
                QMessageBox::about(this,"Delete",name + " succesfuly deleted!");
            }
            else{
                QMessageBox::about(this,"Delete",name + " deleting went wrong!");
            }
            return;
        }

    }
    //Sandbox
    myQuery->exec("SELECT name FROM [Sandboxes];");
    while(myQuery->next()){
        QString nameG = myQuery->value(0).toString();

        if(name == nameG){
            myQuery->prepare("DELETE FROM [Sandboxes] where name = :nameG;");
            myQuery->bindValue(":nameG", name);
            if(myQuery->exec()){
                QMessageBox::about(this,"Delete",name + " succesfuly deleted!");
            }
            else{
                QMessageBox::about(this,"Delete",name + " deleting went wrong!");
            }
            return;
        }

    }
    //Shooter
    myQuery->exec("SELECT name FROM [Shooters];");
    while(myQuery->next()){
        QString nameG = myQuery->value(0).toString();

        if(name == nameG){
            myQuery->prepare("DELETE FROM [Shooters] where name = :nameG;");
            myQuery->bindValue(":nameG", name);
            if(myQuery->exec()){
                QMessageBox::about(this,"Delete",name + " succesfuly deleted!");
            }
            else{
                QMessageBox::about(this,"Delete",name + " deleting went wrong!");
            }
            return;
        }

    }

    }catch(const char* c){

        throw "Exception caught: pushButton_del member function of class dialog_delete";
    }



}

