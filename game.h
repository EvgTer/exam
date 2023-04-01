#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <QString>

class Game
{
protected:
    QString name;
    float price;
    QString publisher;
public:
    Game();
    Game(
        QString name,
        float price,
        QString publisher
        );

    QString getName()const;
    float getPrice()const;
    QString getPublisher()const;

    void setName(QString name);
    void setPrice(float price);
    void setPublisher(QString publisher);

    virtual QString getGenre()const = 0;

    //bool operator <(const Game& obj)const;

};

#endif // GAME_H
