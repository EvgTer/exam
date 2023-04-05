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

    QObject::connect(foradv, SIGNAL(sendGame(Game*)),
                     this,SLOT(getGame(Game*)));

    if(db.open()){
        ui->statusbar->showMessage("db is open");
        myQuery = new QSqlQuery(db);
        myQuery1 = new QSqlQuery(db);
        myQuery2 = new QSqlQuery(db);
        myQuery3 = new QSqlQuery(db);
        create_accounts();
        //create_store();
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
       throw "Exception caught: create_accounts member function of class mainwindow";
    }

}

/*void MainWindow::create_store()
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
       //throw "Exception caught: create_store member function of class mainwindow";
    }

}*/

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

        throw "Exception caught: showTable_store member function of class mainwindow";
    }

}

void MainWindow::gamesToUsersLibrary(User* user)
{
        myQuery3->exec("SELECT id, login FROM [Users];");
        myQuery1->exec("SELECT user_id, adventure_id,horror_id,mmorpg_id,sandbox_id,shooter_id FROM [User_Games];");
        while(myQuery3->next()){
            int id = myQuery3->value(0).toInt();
            QString login = myQuery3->value(1).toString();
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

                if(id == user_id){
                    int i = 0;
                    //Adventure
                    myQuery2->exec("SELECT id, name, price, publisher,playersAmount  FROM [Adventures];");
                    while(myQuery2->next()){
                        int id_adv = myQuery2->value(0).toInt();
                        QString name = myQuery2->value(1).toString();
                        float price = myQuery2->value(2).toFloat();
                        QString publisher = myQuery2->value(3).toString();
                        int playersAmount = myQuery2->value(4).toInt();

                        for(int p = 0;p<advlist.size();p++){
                            if(id_adv == advlist[p])//transfer data to vector
                                user->getLibrary().append(new Adventure(name,price,publisher, playersAmount));
                        }
                        i++;
                    }
                    //Horror
                    myQuery2->exec("Select id,name,price,publisher,ageLimit FROM [Horrors];");
                    while (myQuery2->next()) {
                        int id_hor = myQuery2->value(0).toInt();
                        QString name = myQuery2->value(1).toString();
                        float price = myQuery2->value(2).toFloat();
                        QString publisher = myQuery2->value(3).toString();
                        QString ageLimit = myQuery2->value(4).toString();

                        for(int p = 0;p<horlist.size();p++){
                            if(id_hor == horlist[p])//transfer data to vector
                                user->getLibrary().append(new Horror(name,price,publisher, ageLimit));
                        }
                        i++;
                    }

                    //MMORPG
                    myQuery2->exec("Select id,name,price,publisher,rating FROM [MMORPGs];");
                    while (myQuery2->next()) {
                        int id_mmo = myQuery2->value(0).toInt();
                        QString name = myQuery2->value(1).toString();
                        float price = myQuery2->value(2).toFloat();
                        QString publisher = myQuery2->value(3).toString();
                        int rating = myQuery2->value(4).toInt();

                        for(int p = 0;p<mmolist.size();p++){
                            if(id_mmo == mmolist[p])//transfer data to vector
                                user->getLibrary().append(new MMORPG(name,price,publisher,rating ));
                        }
                        i++;
                    }

                    //Sandbox
                    myQuery2->exec("Select id,name,price,publisher FROM [Sandboxes];");
                    while (myQuery2->next()) {
                        int id_sand = myQuery2->value(0).toInt();
                        QString name = myQuery2->value(1).toString();
                        float price = myQuery2->value(2).toFloat();
                        QString publisher = myQuery2->value(3).toString();

                        for(int p = 0;p<sandlist.size();p++){
                            if(id_sand == sandlist[p])//transfer data to vector
                                user->getLibrary().append(new Sandbox(name,price,publisher));
                        }
                        i++;
                    }

                    //Shooter
                    myQuery2->exec("Select id,name,price,publisher,weaponAmount FROM [Shooters];");
                    while (myQuery2->next()) {
                        int id_shoot = myQuery2->value(0).toInt();
                        QString name = myQuery2->value(1).toString();
                        float price = myQuery2->value(2).toFloat();
                        QString publisher = myQuery2->value(3).toString();
                        int weaponAmount = myQuery->value(4).toInt();

                        for(int p = 0;p<shootlist.size();p++){
                            if(id_shoot == shootlist[p])//transfer data to vector
                                user->getLibrary().append(new Shooter(name,price,publisher,weaponAmount));
                        }
                        i++;

                    }
                }
            }
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
                mainUser = (User*)accounts[i];
                try{
                    gamesToUsersLibrary( dynamic_cast<User*>(accounts[i]));

                }
                catch(const char& exept){
                    throw "Error with library table in pushButton_log in mainwindow.cpp";
                }

                return;

            }else if(ui->lineEdit_Login->text() == accounts[i]->getLogin() && ui->lineEdit_password->text() == accounts[i]->getPassword()&& accounts[i]->getType() == "Admin"){
                QMessageBox::about(this,"Oh, no", ui->lineEdit_Login->text() +", you are try ing to log for another type of account(\ntry to change it!");
                return;
            }
        }
    }

    QMessageBox::about(this,"Error" ,"Choose account!\nUser/Admin!");
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
    foradv->show();
}

void MainWindow::getGame(Game *obj)
{
    if (obj->getGenre() == "Adventure") {
        myQuery->prepare("INSERT INTO Adventures(name,price,publisher,playersAmount) VALUES(:name,:price,:publisher,:playersAmount);");
        myQuery->bindValue(":name", obj->getName());
        myQuery->bindValue(":price", obj->getPrice());
        myQuery->bindValue(":publisher", obj->getPublisher());
        //Adventure* adven = dynamic_cast<Adventure*>(obj); //errors
        //Adventure* adven = &(obj);;
        //myQuery->bindValue(":playersAmount", adven->getAmountOfPlayers());

    }else if(obj->getGenre() =="Horror"){
        myQuery->prepare("INSERT INTO [Horrors](name,price,publisher,ageLimit) VALUES(:name,:price,:publisher,:ageLimit);");
        myQuery->bindValue(":name", obj->getName());
        myQuery->bindValue(":price", obj->getPrice());
        myQuery->bindValue(":publisher", obj->getPublisher());
        //Horror* horror = &(obj);
        //myQuery->bindValue(":ageLimit", horror->getAgeLimit());

      }else if(obj->getGenre() =="MMORPG"){
        myQuery->prepare("INSERT INTO [MMORPGs](name,price,publisher,rating) VALUES(:name,:price,:publisher,:rating);");
        myQuery->bindValue(":name", obj->getName());
        myQuery->bindValue(":price", obj->getPrice());
        myQuery->bindValue(":publisher", obj->getPublisher());
        //MMORPG* mmorpf = &(obj);
        //myQuery->bindValue(":rating", mmorpf->getRating());


    }else if(obj->getGenre() =="Sandbox"){
        myQuery->prepare("INSERT INTO [Sandboxes](name,price,publisher) VALUES(:name,:price,:publisher);");
        myQuery->bindValue(":name", obj->getName());
        myQuery->bindValue(":price", obj->getPrice());
        myQuery->bindValue(":publisher", obj->getPublisher());


     }else if(obj->getGenre() =="Shooter"){
        myQuery->prepare("INSERT INTO [Shooters](name,price,publisher,weaponAmount) VALUES(:name,:price,:publisher,:weaponAmount);");
        myQuery->bindValue(":name", obj->getName());
        myQuery->bindValue(":price", obj->getPrice());
        myQuery->bindValue(":publisher", obj->getPublisher());
        //Shooter* shootr = &(obj);
        //myQuery->bindValue(":weaponAmount", shootr->getWeaponAmount());

    }

    if(myQuery->exec()){
        QMessageBox::about(this,"Succes","New game succesfully added to the store!");
        showTable_Store();
    }
    else{
        QMessageBox::about(this,"Error","New game didnt add to the store!");
    }

}


void MainWindow::on_actionMMORPG_triggered()
{
    bal->show();
}


void MainWindow::on_actionHorror_triggered()
{
    del->show();
}

void MainWindow::on_tableWidget_store_itemDoubleClicked(QTableWidgetItem *item)
{
    try{
        Game* game = (Game*)(item);
        mainUser->addGame((Game*)(item));
        myQuery->prepare("SELECT id FROM Users where login = :login");
        myQuery->bindValue(":login", mainUser->getLogin());
        myQuery->exec();
        int userid = myQuery->value(0).toInt();
        if(game->getGenre()== "Adventure"){
            myQuery->prepare("SELECT id FROM [Adventures] where name = :name");
            myQuery->bindValue(":name", game->getName());
            myQuery->exec();

            int id = myQuery->value(0).toInt();
            myQuery->prepare("SELECT adventure_id FROM [User_Games] where user_id = :userid");
            myQuery->bindValue(":userid", userid);
            myQuery->exec();
            QString ids = myQuery->value(0).toString();
            QString newId = ids + "-" + QString::number(id);

            myQuery->prepare("UPDATE [User_Games] set adventure_id = :newids");
            myQuery->bindValue(":newids", newId);

            if(myQuery->exec()){
                QMessageBox::about(this,"Buy", " succesfully added!");
                return;
            }
        }else if(game->getGenre()== "Horror"){
            myQuery->prepare("SELECT id FROM [Horrors] where name = :name");
            myQuery->bindValue(":name", game->getName());
            myQuery->exec();

            int id = myQuery->value(0).toInt();
            myQuery->prepare("SELECT horror_id FROM [User_Games] where user_id = :userid");
            myQuery->bindValue(":userid", userid);
            myQuery->exec();
            QString ids = myQuery->value(0).toString();
            QString newId = ids + "-" + QString::number(id);

            myQuery->prepare("UPDATE [User_Games] set horror_id = :newids");
            myQuery->bindValue(":newids", newId);

            if(myQuery->exec()){
                QMessageBox::about(this,"Buy", " succesfully added!");
                return;
            }
        }else if(game->getGenre() == "MMORPG"){
            myQuery->prepare("SELECT id FROM [MMORPGs] where name = :name");
            myQuery->bindValue(":name", game->getName());
            myQuery->exec();

            int id = myQuery->value(0).toInt();
            myQuery->prepare("SELECT mmorpg_id FROM [User_Games] where user_id = :userid");
            myQuery->bindValue(":userid", userid);
            myQuery->exec();
            QString ids = myQuery->value(0).toString();
            QString newId = ids + "-" + QString::number(id);

            myQuery->prepare("UPDATE [User_Games] set mmorpg_id = :newids");
            myQuery->bindValue(":newids", newId);

            if(myQuery->exec()){
                QMessageBox::about(this,"Buy", " succesfully added!");
                return;
            }
        }else if(game->getGenre() == "Sandbox"){
            myQuery->prepare("SELECT id FROM [Sandboxes] where name = :name");
            myQuery->bindValue(":name", game->getName());
            myQuery->exec();

            int id = myQuery->value(0).toInt();
            myQuery->prepare("SELECT sandbox_id FROM [User_Games] where user_id = :userid");
            myQuery->bindValue(":userid", userid);
            myQuery->exec();
            QString ids = myQuery->value(0).toString();
            QString newId = ids + "-" + QString::number(id);

            myQuery->prepare("UPDATE [User_Games] set sandbox_id = :newids");
            myQuery->bindValue(":newids", newId);

            if(myQuery->exec()){
                QMessageBox::about(this,"Buy", " succesfully added!");
                return;
            }


        }else if(game->getGenre() == "Shooter"){
            myQuery->prepare("SELECT id FROM [Shooters] where name = :name");
            myQuery->bindValue(":name", game->getName());
            myQuery->exec();

            int id = myQuery->value(0).toInt();
            myQuery->prepare("SELECT shooter_id FROM [User_Games] where user_id = :userid");
            myQuery->bindValue(":userid", userid);
            myQuery->exec();
            QString ids = myQuery->value(0).toString();
            QString newId = ids + "-" + QString::number(id);

            myQuery->prepare("UPDATE [User_Games] set shooter_id = :newids");
            myQuery->bindValue(":newids", newId);

            if(myQuery->exec()){
                QMessageBox::about(this,"Buy", " succesfully added!");
                return;
            }
        }

    }
    catch(const char* exept){
        QMessageBox::about(this,"Buy", "Something gone wrong!");
    }

}

