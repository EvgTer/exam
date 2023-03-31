#ifndef USER_H
#define USER_H

#include "account.h"
#include <QSet>
#include <QVector>
#include "game.h"

class User : public Account
{
    float balance;
    QVector<Game*> library;
public:
    User();
    User(
        QString login,
        QString password,
        float balance
        );

    float getBalance()const;
    void addBalance(float money);

    void addGame(Game* obj);
    void sortLibrary();
};

#endif // USER_H
