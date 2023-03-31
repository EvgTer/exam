#include "user.h"



User::User()
    :Account()
{
    balance = 0;
}

float User::getBalance() const
{
    return balance;
}

void User::addBalance(float money)
{
    if(money <= 0)
        throw "Money you want to add is incorrect!";
    this->balance += money;
}

User::User(QString login, QString password, float balance)
    :Account(login,password)
{
    this->balance = balance;
}

void User::addGame(Game* obj)
{
    if(balance -= obj->getPrice() < 0)
        throw "You haven`t got enough money to buy this game!";
    else{
    balance -= obj->getPrice();
    library.push_back(obj);
    }
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
