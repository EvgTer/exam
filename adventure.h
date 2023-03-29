#ifndef ADVENTURE_H
#define ADVENTURE_H

#include "game.h"
#include <QTime>
class Adventure : public Game
{
protected:
    int amountOfPlayers;
    QTime avgTimeToEnd;
public:
    Adventure();
    Adventure(
            QString name,
            float price,
            QString publisher,
            int amountOfPlayers,
            QTime avgTimeToEnd
            );

    void setAmountOfPlayers(int amountOfPlayers);
    void setAvgTimeToEnd(QTime avgTimeToEnd);

    int getAmountOfPlayers()const;
    QTime getAvgTimeToEnd()const;

    QString getGenre()const override;
};

#endif // ADVENTURE_H
