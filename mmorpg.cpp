#include "mmorpg.h"

MMORPG::MMORPG()
    :Game()
{
    this->rating = 0;
}

MMORPG::MMORPG(QString name, float price, QString publisher, int rating)
    :Game(name,price,publisher)
{
    this->setRating(rating);
}

void MMORPG::setRating(int rating)
{
    if(rating <= 0)
        throw "Rating is incorrect!";
    this->rating = rating;
}

int MMORPG::getRating() const
{
    return rating;
}

QString MMORPG::getGenre() const
{
    return "MMORPG";
}
