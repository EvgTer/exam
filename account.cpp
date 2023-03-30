#include "account.h"

Account::Account()
{
    login = "Undefined!";
    password = "Undefined!";
}

Account::Account(QString login, QString password)
{
    this->setLogin(login);
    this->setPassword(password);
}

QString Account::getLogin() const
{
    return login;
}

QString Account::getPassword() const
{
    return password;
}

void Account::setLogin(QString login)
{
    if(login.size() <= 0)
        throw "Login is incorrect!";
    this->login = login;
}

void Account::setPassword(QString password)
{
    if(password.size() <= 0)
        throw "Password is incorrect!";
    this->password = password;
}
