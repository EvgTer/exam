#include "shooter.h"

Shooter::Shooter()
    :Game()
{
    this->weaponAmount = 0;
}

void Shooter::setWeaponAmount(int weaponAmount)
{
    if(weaponAmount <= 0)
        throw "Amount of weapon is incorrect!";
    this->weaponAmount = weaponAmount;
}

int Shooter::getWeaponAmount() const
{
    return weaponAmount;
}

Shooter::Shooter(QString name, float price, QString publisher, int weaponAmount)
    :Game(name,price,publisher)
{
    this->weaponAmount = weaponAmount;
}

QString Shooter::getGenre() const
{
    return "Shooter";
}
