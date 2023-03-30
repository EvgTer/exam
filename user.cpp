#include "user.h"



User::User()
    :Account()
{

}

User::User(QString login, QString password)
    :Account(login,password)
{

}

void User::addGame(Game* obj)
{
    library.push_back(obj);
}
