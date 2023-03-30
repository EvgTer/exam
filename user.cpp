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

void User::sortLibrary()
{
    std::sort(library.begin(), library.end(), [](Game* a, Game* b) {
               if (a->getName() != b->getName()) {
                   return a->getName() < b->getName();
               } else {
                   return a->getPrice() < b->getPrice();
               }
           });
}
