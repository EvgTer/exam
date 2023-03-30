#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <QString>

class Account
{
protected:
    QString login;
    QString password;
public:
    Account();
    Account(
            QString login,
            QString password
            );

    QString getLogin()const;
    QString getPassword()const;

    void setLogin(QString login);
    void setPassword(QString password);

    virtual QString getType()const = 0;

};

#endif // ACCOUNT_H
