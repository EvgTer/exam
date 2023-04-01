#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_logo->setStyleSheet("image: url(:/logo/GGStore_LOGO.jpg);");

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("GGStore.db");

    if(db.open()){
        ui->statusbar->showMessage("db is open");
        myQuery = new QSqlQuery(db);
        create_accounts();
        create_store();
    }
    else
        ui->statusbar->showMessage("db is not open");
}

MainWindow::~MainWindow()
{
    delete ui;
    db.close();
}

void MainWindow::create_accounts()
{
    try {
            myQuery->exec("SELECT login, password, balance FROM [Users];");
            while (myQuery->next()) {
            QString login = myQuery->value(0).toString();
            QString password = myQuery->value(1).toString();
            float balance = myQuery->value(2).toFloat();

            accounts.append(new User(login, password, balance));
            }


            myQuery->exec("SELECT login, password FROM [Admins];");
            while (myQuery->next()) {
            QString login = myQuery->value(0).toString();
            QString password = myQuery->value(1).toString();

            accounts.append(new Admin(login, password));
            }


    } catch (std::exception& e) {
        // Handle the exception here, for example by printing an error message
        qDebug() << "Exception caught:" << "create_accounts member function of class mainwindow";
    }

}

void MainWindow::create_store()
{
    try {
            //Adventure
            myQuery->exec("Select name,price,publisher,playersAmount FROM [Adventures];");
            while (myQuery->next()) {
            QString name = myQuery->value(0).toString();
            float price = myQuery->value(1).toFloat();
            QString publisher = myQuery->value(2).toString();
            int playersAmount = myQuery->value(3).toInt();
            store.append(new Adventure(name,price,publisher,playersAmount));
            }

            //Horror
            myQuery->exec("Select name,price,publisher,ageLimit FROM [Horrors];");
            while (myQuery->next()) {
            QString name = myQuery->value(0).toString();
            float price = myQuery->value(1).toFloat();
            QString publisher = myQuery->value(2).toString();
            QString ageLimit = myQuery->value(3).toString();
            store.append(new Horror(name,price,publisher,ageLimit));
            }

            //MMORPG
            myQuery->exec("Select name,price,publisher,rating FROM [MMORPGs];");
            while (myQuery->next()) {
            QString name = myQuery->value(0).toString();
            float price = myQuery->value(1).toFloat();
            QString publisher = myQuery->value(2).toString();
            int rating = myQuery->value(3).toInt();
            store.append(new MMORPG(name,price,publisher,rating));
            }

            //Sandbox
            myQuery->exec("Select name,price,publisher FROM [Sandboxes];");
            while (myQuery->next()) {
            QString name = myQuery->value(0).toString();
            float price = myQuery->value(1).toFloat();
            QString publisher = myQuery->value(2).toString();
            store.append(new Sandbox(name,price,publisher));
            }

            //Shooter
            myQuery->exec("Select name,price,publisher,weaponAmount FROM [Shooters];");
            while (myQuery->next()) {
            QString name = myQuery->value(0).toString();
            float price = myQuery->value(1).toFloat();
            QString publisher = myQuery->value(2).toString();
            int weaponAmount = myQuery->value(3).toInt();
            store.append(new Shooter(name,price,publisher,weaponAmount));
            }

    } catch (const char* ex) {
        // Handle the exception here, for example by printing an error message
        qDebug() << "Exception caught:" << "create_store member function of class mainwindow";
    }

}


void MainWindow::on_pushButton_log_clicked()
{
    if(ui->radioButton_admin->isChecked() == true){
        for (int i = 0; i < accounts.size(); ++i) {
            if(ui->lineEdit_Login->text() == accounts[i]->getLogin() && ui->lineEdit_password->text() == accounts[i]->getPassword() && accounts[i]->getType() == "Admin"){

                QMessageBox::about(this,"Succes",ui->lineEdit_Login->text() +", you successfully logged in as admin!");
                return;
            }
            else if(ui->lineEdit_Login->text() == accounts[i]->getLogin() && ui->lineEdit_password->text() == accounts[i]->getPassword()&& accounts[i]->getType() == "User"){
                QMessageBox::about(this,"Oh, no", ui->lineEdit_Login->text() +", you are try ing to log for another type of account(\ntry to change it!");
                return;
            }
        }
    }else if(ui->radioButton_user->isChecked() == true){
        for (int i = 0; i < accounts.size(); ++i) {
            if(ui->lineEdit_Login->text() == accounts[i]->getLogin() && ui->lineEdit_password->text() == accounts[i]->getPassword()&& accounts[i]->getType() == "User"){

                QMessageBox::about(this,"Succes", ui->lineEdit_Login->text() +", you successfully logged in as user!");
                return;
            }
            else if(ui->lineEdit_Login->text() == accounts[i]->getLogin() && ui->lineEdit_password->text() == accounts[i]->getPassword()&& accounts[i]->getType() == "Admin"){
                QMessageBox::about(this,"Oh, no", ui->lineEdit_Login->text() +", you are try ing to log for another type of account(\ntry to change it!");
                return;
            }
        }

    }

    QMessageBox::about(this,"Error" ,tr("Incorrect login or password!\nPlease try again!"));
}


void MainWindow::on_pushButton_sign_clicked()
{
    if(ui->radioButton_admin->isChecked() == true){
        for (int i = 0; i < accounts.size(); ++i) {
            if(ui->lineEdit_Login->text() == accounts[i]->getLogin()){
                QMessageBox::about(this,"add Admin", ui->lineEdit_Login->text() + " account with such login already excist!");
                return;
            }
            else{
                accounts.append(new Admin(ui->lineEdit_Login->text(), ui->lineEdit_password->text()));

                myQuery->prepare("INSERT INTO [Admins](login, password) Values (:login,:password)");
                myQuery->bindValue(":login", ui->lineEdit_Login->text());
                myQuery->bindValue(":password", ui->lineEdit_password->text());

                myQuery->exec();

                QMessageBox::about(this,"add Admin", ui->lineEdit_Login->text() + " saved!");
                return;
            }

        }

    }else if(ui->radioButton_user->isChecked() == true){
            for (int i = 0; i < accounts.size(); ++i) {
                if(ui->lineEdit_Login->text() == accounts[i]->getLogin()){
                    QMessageBox::about(this,"add User", ui->lineEdit_Login->text() + " account with such login already excist!");
                    return;
                }else{
                    accounts.append(new User(ui->lineEdit_Login->text(), ui->lineEdit_password->text(),0));

                    myQuery->prepare("INSERT INTO [Users](login, password) Values (:login,:password)");
                    myQuery->bindValue(":login", ui->lineEdit_Login->text());
                    myQuery->bindValue(":password", ui->lineEdit_password->text());
                    myQuery->exec();

                    QMessageBox::about(this,"add User", ui->lineEdit_Login->text() + " saved!");
                    return;
                }

            }

        }

}

