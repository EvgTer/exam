#ifndef ADVENTURE_H
#define ADVENTURE_H

#include "game.h"
class Adventure : public Game
{
protected:
    int amountOfPlayers;
public:
    Adventure();
    Adventure(
            QString name,
            float price,
            QString publisher,
            int amountOfPlayers
            );

    void setAmountOfPlayers(int amountOfPlayers);

    int getAmountOfPlayers()const;

    QString getGenre()const override;
};

#endif // ADVENTURE_H
