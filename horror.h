#ifndef HORROR_H
#define HORROR_H

#include "game.h"

class Horror : public Game
{
protected:
    QString ageLimit;
public:
    Horror();
    Horror(
           QString name,
           float price,
           QString publisher,
           QString ageLimit
           );

    QString getAgeLimit()const;
    void setAgeLimit(QString ageLimit);

    void show()const override;
    QString getGenre()const override;
};

#endif // HORROR_H
