#ifndef MMORPG_H
#define MMORPG_H

#include "game.h"

class MMORPG : public Game
{
protected:
    int rating;
public:
    MMORPG();
    MMORPG(
            QString name,
            float price,
            QString publisher,
            int rating
            );

    void setRating(int rating);
    int getRating()const;

    QString getGenre()const override;
};

#endif // MMORPG_H
