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
        showTable_Store();
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

void MainWindow::showTable_Store()
{
    int i = 0;
    try{
    //Adventure
    myQuery->exec("SELECT name, price, publisher FROM [Adventures];");
    while(myQuery->next()){
        QString name = myQuery->value(0).toString();
        float price = myQuery->value(1).toFloat();
        QString publisher = myQuery->value(2).toString();

        //transfer data to table
        ui->tableWidget_store->setRowCount(i+1);

        QTableWidgetItem* cellName = new QTableWidgetItem();
        QTableWidgetItem* cellPrice = new QTableWidgetItem();
        QTableWidgetItem* cellGenre = new QTableWidgetItem();
        QTableWidgetItem* cellPublisher = new QTableWidgetItem();

        cellName->setText(name);
        cellPrice->setText(QString().setNum(price));
        cellGenre->setText("Adventure");
        cellPublisher->setText(publisher);

        ui->tableWidget_store->setItem(i,0,cellName);
        ui->tableWidget_store->setItem(i,1,cellPrice);
        ui->tableWidget_store->setItem(i,2,cellGenre);
        ui->tableWidget_store->setItem(i,3,cellPublisher);

        i++;
    }
    //Horror
    myQuery->exec("SELECT name, price, publisher FROM [Horrors];");
    while(myQuery->next()){
        QString name = myQuery->value(0).toString();
        float price = myQuery->value(1).toFloat();
        QString publisher = myQuery->value(2).toString();

        //transfer data to table
        ui->tableWidget_store->setRowCount(i+1);

        QTableWidgetItem* cellName = new QTableWidgetItem();
        QTableWidgetItem* cellPrice = new QTableWidgetItem();
        QTableWidgetItem* cellGenre = new QTableWidgetItem();
        QTableWidgetItem* cellPublisher = new QTableWidgetItem();

        cellName->setText(name);
        cellPrice->setText(QString().setNum(price));
        cellGenre->setText("Horror");
        cellPublisher->setText(publisher);

        ui->tableWidget_store->setItem(i,0,cellName);
        ui->tableWidget_store->setItem(i,1,cellPrice);
        ui->tableWidget_store->setItem(i,2,cellGenre);
        ui->tableWidget_store->setItem(i,3,cellPublisher);
        i++;
    }
    //MMORPG
    myQuery->exec("SELECT name, price, publisher FROM [MMORPGs];");
    while(myQuery->next()){
        QString name = myQuery->value(0).toString();
        float price = myQuery->value(1).toFloat();
        QString publisher = myQuery->value(2).toString();

        //transfer data to table
        ui->tableWidget_store->setRowCount(i+1);

        QTableWidgetItem* cellName = new QTableWidgetItem();
        QTableWidgetItem* cellPrice = new QTableWidgetItem();
        QTableWidgetItem* cellGenre = new QTableWidgetItem();
        QTableWidgetItem* cellPublisher = new QTableWidgetItem();

        cellName->setText(name);
        cellPrice->setText(QString().setNum(price));
        cellGenre->setText("MMORPG");
        cellPublisher->setText(publisher);

        ui->tableWidget_store->setItem(i,0,cellName);
        ui->tableWidget_store->setItem(i,1,cellPrice);
        ui->tableWidget_store->setItem(i,2,cellGenre);
        ui->tableWidget_store->setItem(i,3,cellPublisher);
        i++;
    }
    //Sandbox
    myQuery->exec("SELECT name, price, publisher FROM [Sandboxes];");
    while(myQuery->next()){
        QString name = myQuery->value(0).toString();
        float price = myQuery->value(1).toFloat();
        QString publisher = myQuery->value(2).toString();

        //transfer data to table
        ui->tableWidget_store->setRowCount(i+1);

        QTableWidgetItem* cellName = new QTableWidgetItem();
        QTableWidgetItem* cellPrice = new QTableWidgetItem();
        QTableWidgetItem* cellGenre = new QTableWidgetItem();
        QTableWidgetItem* cellPublisher = new QTableWidgetItem();

        cellName->setText(name);
        cellPrice->setText(QString().setNum(price));
        cellGenre->setText("Sandbox");
        cellPublisher->setText(publisher);

        ui->tableWidget_store->setItem(i,0,cellName);
        ui->tableWidget_store->setItem(i,1,cellPrice);
        ui->tableWidget_store->setItem(i,2,cellGenre);
        ui->tableWidget_store->setItem(i,3,cellPublisher);
        i++;
    }
    //Shooter
    myQuery->exec("SELECT name, price, publisher FROM [Shooters];");
    while(myQuery->next()){
        QString name = myQuery->value(0).toString();
        float price = myQuery->value(1).toFloat();
        QString publisher = myQuery->value(2).toString();

        //transfer data to table
        ui->tableWidget_store->setRowCount(i+1);

        QTableWidgetItem* cellName = new QTableWidgetItem();
        QTableWidgetItem* cellPrice = new QTableWidgetItem();
        QTableWidgetItem* cellGenre = new QTableWidgetItem();
        QTableWidgetItem* cellPublisher = new QTableWidgetItem();

        cellName->setText(name);
        cellPrice->setText(QString().setNum(price));
        cellGenre->setText("Shooter");
        cellPublisher->setText(publisher);

        ui->tableWidget_store->setItem(i,0,cellName);
        ui->tableWidget_store->setItem(i,1,cellPrice);
        ui->tableWidget_store->setItem(i,2,cellGenre);
        ui->tableWidget_store->setItem(i,3,cellPublisher);
        i++;
    }

    }catch(const char* c){

        qDebug() << "Exception caught:" << "showTable_store member function of class mainwindow";
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


                Account* user = accounts[i];

                    myQuery->exec("SELECT id, login FROM [Users];");
                    myQuery1->exec("SELECT user_id, adventure_id,horror_id,mmorpg_id,sandbox_id,shooter_id FROM [User_Games];");
                    while(myQuery->next()){
                        int id = myQuery->value(0).toInt();
                        QString login = myQuery->value(1).toString();
                        while(myQuery1->next()){
                            int user_id = myQuery1->value(0).toInt();
                            QString adventure_id = myQuery1->value(1).toString();
                            QString horror_id = myQuery1->value(2).toString();
                            QString mmorpg_id = myQuery1->value(3).toString();
                            QString sandbox_id = myQuery1->value(4).toString();
                            QString shooter_id = myQuery1->value(5).toString();

                            QStringList advidlist = adventure_id.split("-");
                            QStringList horidlist = horror_id.split("-");
                            QStringList mmoidlist = mmorpg_id.split("-");
                            QStringList sandidlist = sandbox_id.split("-");
                            QStringList shootidlist = shooter_id.split("-");

                            QList<int> advlist;
                            foreach(QString substr, advidlist) {
                                int num = substr.toInt();
                                advlist.append(num);
                            }

                            QList<int> horlist;
                            foreach(QString substr, horidlist) {
                                int num = substr.toInt();
                                horlist.append(num);
                            }

                            QList<int> mmolist;
                            foreach(QString substr, mmoidlist) {
                                int num = substr.toInt();
                                mmolist.append(num);
                            }

                            QList<int> sandlist;
                            foreach(QString substr, sandidlist) {
                                int num = substr.toInt();
                                sandlist.append(num);
                            }

                            QList<int> shootlist;
                            foreach(QString substr, shootidlist) {
                                int num = substr.toInt();
                                shootlist.append(num);
                            }


                            if(user->getLogin() == login){
                                if(id == user_id){

                                    int j = 0;

                                    try{
                                        //Adventure
                                        myQuery2->exec("SELECT id,name, price, publisher FROM [Adventures];");
                                        while(myQuery2->next()){
                                        int adv_id = myQuery2->value(0).toInt();
                                        QString name = myQuery2->value(1).toString();
                                        float price = myQuery2->value(2).toFloat();
                                        QString publisher = myQuery2->value(3).toString();

                                            for(int o = 0; o < advlist.size(); o++){
                                                if (advlist[o] == adv_id){
                                                ui->tableWidget_library->setRowCount(j+1);

                                                QTableWidgetItem* cellName = new QTableWidgetItem();
                                                QTableWidgetItem* cellPrice = new QTableWidgetItem();
                                                QTableWidgetItem* cellGenre = new QTableWidgetItem();
                                                QTableWidgetItem* cellPublisher = new QTableWidgetItem();

                                                cellName->setText(name);
                                                cellPrice->setText(QString().setNum(price));
                                                cellGenre->setText("Adventure");
                                                cellPublisher->setText(publisher);

                                                ui->tableWidget_library->setItem(j,0,cellName);
                                                ui->tableWidget_library->setItem(j,1,cellPrice);
                                                ui->tableWidget_library->setItem(j,2,cellGenre);
                                                ui->tableWidget_library->setItem(j,3,cellPublisher);

                                                j++;

                                                }

                                            }

                                        }

                                    //Horror
                                        myQuery2->exec("SELECT id,name, price, publisher FROM [Horrors];");
                                        while(myQuery2->next()){
                                        int hor_id = myQuery2->value(0).toInt();
                                        QString name = myQuery2->value(1).toString();
                                        float price = myQuery2->value(2).toFloat();
                                        QString publisher = myQuery2->value(3).toString();

                                            for(int o = 0; o < horlist.size(); o++){
                                                if (horlist[o] == hor_id){
                                                ui->tableWidget_library->setRowCount(j+1);

                                                QTableWidgetItem* cellName = new QTableWidgetItem();
                                                QTableWidgetItem* cellPrice = new QTableWidgetItem();
                                                QTableWidgetItem* cellGenre = new QTableWidgetItem();
                                                QTableWidgetItem* cellPublisher = new QTableWidgetItem();

                                                cellName->setText(name);
                                                cellPrice->setText(QString().setNum(price));
                                                cellGenre->setText("Horror");
                                                cellPublisher->setText(publisher);

                                                ui->tableWidget_library->setItem(j,0,cellName);
                                                ui->tableWidget_library->setItem(j,1,cellPrice);
                                                ui->tableWidget_library->setItem(j,2,cellGenre);
                                                ui->tableWidget_library->setItem(j,3,cellPublisher);

                                                j++;

                                                }

                                            }

                                        }


                                    //MMORPG
                                        myQuery2->exec("SELECT id,name, price, publisher FROM [MMORPGs];");
                                        while(myQuery2->next()){
                                        int mmo_id = myQuery2->value(0).toInt();
                                        QString name = myQuery2->value(1).toString();
                                        float price = myQuery2->value(2).toFloat();
                                        QString publisher = myQuery2->value(3).toString();

                                            for(int o = 0; o < mmolist.size(); o++){
                                                if (mmolist[o] == mmo_id){
                                                ui->tableWidget_library->setRowCount(j+1);

                                                QTableWidgetItem* cellName = new QTableWidgetItem();
                                                QTableWidgetItem* cellPrice = new QTableWidgetItem();
                                                QTableWidgetItem* cellGenre = new QTableWidgetItem();
                                                QTableWidgetItem* cellPublisher = new QTableWidgetItem();

                                                cellName->setText(name);
                                                cellPrice->setText(QString().setNum(price));
                                                cellGenre->setText("MMORPG");
                                                cellPublisher->setText(publisher);

                                                ui->tableWidget_library->setItem(j,0,cellName);
                                                ui->tableWidget_library->setItem(j,1,cellPrice);
                                                ui->tableWidget_library->setItem(j,2,cellGenre);
                                                ui->tableWidget_library->setItem(j,3,cellPublisher);

                                                j++;

                                                }

                                            }

                                        }
                                    //Sandbox
                                        myQuery2->exec("SELECT id,name, price, publisher FROM [Sandboxes];");
                                        while(myQuery2->next()){
                                        int sand_id = myQuery2->value(0).toInt();
                                        QString name = myQuery2->value(1).toString();
                                        float price = myQuery2->value(2).toFloat();
                                        QString publisher = myQuery2->value(3).toString();

                                            for(int o = 0; o < sandlist.size(); o++){
                                                if (sandlist[o] == sand_id){
                                                ui->tableWidget_library->setRowCount(j+1);

                                                QTableWidgetItem* cellName = new QTableWidgetItem();
                                                QTableWidgetItem* cellPrice = new QTableWidgetItem();
                                                QTableWidgetItem* cellGenre = new QTableWidgetItem();
                                                QTableWidgetItem* cellPublisher = new QTableWidgetItem();

                                                cellName->setText(name);
                                                cellPrice->setText(QString().setNum(price));
                                                cellGenre->setText("Sandbox");
                                                cellPublisher->setText(publisher);

                                                ui->tableWidget_library->setItem(j,0,cellName);
                                                ui->tableWidget_library->setItem(j,1,cellPrice);
                                                ui->tableWidget_library->setItem(j,2,cellGenre);
                                                ui->tableWidget_library->setItem(j,3,cellPublisher);

                                                j++;

                                                }

                                            }

                                        }
                                    //Shooter
                                        myQuery2->exec("SELECT id,name, price, publisher FROM [Sandboxes];");
                                        while(myQuery2->next()){
                                        int shoot_id = myQuery2->value(0).toInt();
                                        QString name = myQuery2->value(1).toString();
                                        float price = myQuery2->value(2).toFloat();
                                        QString publisher = myQuery2->value(3).toString();

                                            for(int o = 0; o < shootlist.size(); o++){
                                                if (shootlist[o] == shoot_id){
                                                ui->tableWidget_library->setRowCount(j+1);

                                                QTableWidgetItem* cellName = new QTableWidgetItem();
                                                QTableWidgetItem* cellPrice = new QTableWidgetItem();
                                                QTableWidgetItem* cellGenre = new QTableWidgetItem();
                                                QTableWidgetItem* cellPublisher = new QTableWidgetItem();

                                                cellName->setText(name);
                                                cellPrice->setText(QString().setNum(price));
                                                cellGenre->setText("Shooter");
                                                cellPublisher->setText(publisher);

                                                ui->tableWidget_library->setItem(j,0,cellName);
                                                ui->tableWidget_library->setItem(j,1,cellPrice);
                                                ui->tableWidget_library->setItem(j,2,cellGenre);
                                                ui->tableWidget_library->setItem(j,3,cellPublisher);

                                                j++;

                                                }

                                            }

                                        }

                                    }catch(const char* c){

                                        qDebug() << "Exception caught:" << "showTable_library part function of pushButton_log of class mainwindow";
                                    }



                                }
                                throw "Error id != user_id in showTable_Library";
                            }
                        }
                    }





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


void MainWindow::on_actionAdventure_triggered()
{

}

