#ifndef SANDBOX_H
#define SANDBOX_H

#include "game.h"

class Sandbox : public Game
{

public:
    Sandbox();
    Sandbox(
            QString name,
            float price,
            QString publisher
            );

    QString getGenre()const override;
};

#endif // SANDBOX_H
