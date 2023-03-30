#ifndef USER_H
#define USER_H

#include "account.h"
#include <QSet>
#include <QVector>
#include "game.h"

class User : public Account
{
    QVector<Game*> library;
public:
    User();
    User(
        QString login,
        QString password
        );
    void addGame(Game* obj);
    void sortLibrary();
};

#endif // USER_H
