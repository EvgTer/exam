#include "adventure.h"

Adventure::Adventure()
    :Game()
{
    amountOfPlayers = 1;
}

Adventure::Adventure(QString name, float price, QString publisher, int amountOfPlayers)
    :Game(name,price,publisher)
{
    this->setAmountOfPlayers(amountOfPlayers);
}

void Adventure::setAmountOfPlayers(int amountOfPlayers)
{
    if(amountOfPlayers <= 0)
        throw "Amount of players is incorrect!";
    this->amountOfPlayers = amountOfPlayers;
}


int Adventure::getAmountOfPlayers() const
{
    return amountOfPlayers;
}

QString Adventure::getGenre() const
{
    return "Adventure";
}
