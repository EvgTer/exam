#include "horror.h"

Horror::Horror()
    :Game()
{
    ageLimit = "Undefined limit";
}

Horror::Horror(QString name, float price, QString publisher, QString ageLimit)
    :Game(name,price,publisher)
{
    this->setAgeLimit(ageLimit);
}

QString Horror::getAgeLimit() const
{
    return ageLimit;
}

void Horror::setAgeLimit(QString ageLimit)
{
    if(ageLimit.size() <= 0)
        throw "Age limit string is incorrect!";
    this->ageLimit = ageLimit;
}

QString Horror::getGenre() const
{
    return "Horror";
}
