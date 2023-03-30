#ifndef SHOOTER_H
#define SHOOTER_H

#include "game.h"

class Shooter : public Game
{
    int weaponAmount;
public:
    Shooter();
    Shooter(
            QString name,
            float price,
            QString publisher,
            int weaponAmount
            );

    void setWeaponAmount(int weaponAmount);
    int getWeaponAmount()const;

    QString getGenre() const override;
};

#endif // SHOOTER_H
