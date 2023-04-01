#include "admin.h"

Admin::Admin()
    :Account()
{

}

Admin::Admin(QString login, QString password)
    :Account(login,password)
{

}

QString Admin::getType() const
{
    return "Admin";
}
