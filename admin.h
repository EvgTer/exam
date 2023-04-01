#ifndef ADMIN_H
#define ADMIN_H

#include "account.h"

class Admin : public Account
{
public:
    Admin();
    Admin(
          QString login,
          QString password
          );

    QString getType()const override;

};

#endif // ADMIN_H
