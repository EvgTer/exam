#include "sandbox.h"

Sandbox::Sandbox()
    :Game()
{

}

Sandbox::Sandbox(QString name, float price, QString publisher)
    :Game(name,price,publisher)
{

}

QString Sandbox::getGenre() const
{
    return "Sandbox";
}
