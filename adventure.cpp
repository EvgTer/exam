#include "adventure.h"

Adventure::Adventure()
    :Game()
{
    amountOfPlayers = 1;
    avgTimeToEnd = QTime(1,0,0);
}

Adventure::Adventure(QString name, float price, QString publisher, int amountOfPlayers, QTime avgTimeToEnd)
    :Game(name,price,publisher)
{
    this->setAmountOfPlayers(amountOfPlayers);
    this->setAvgTimeToEnd(avgTimeToEnd);
}

void Adventure::setAmountOfPlayers(int amountOfPlayers)
{
    if(amountOfPlayers <= 0)
        throw "Amount of players is incorrect!";
    this->amountOfPlayers = amountOfPlayers;
}

void Adventure::setAvgTimeToEnd(QTime avgTimeToEnd)
{
    if(avgTimeToEnd <= QTime(0,0,0))
        throw "Average time to end is incorrect!";
    this->avgTimeToEnd = avgTimeToEnd;
}

int Adventure::getAmountOfPlayers() const
{
    return amountOfPlayers;
}

QTime Adventure::getAvgTimeToEnd() const
{
    return avgTimeToEnd;
}

QString Adventure::getGenre() const
{
    return "Adventure";
}
