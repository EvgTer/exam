#include "game.h"

Game::Game()
{
    this->name = "undefined Name";
    this->price = -1;
    this->publisher = "undefined Publisher";
}

Game::Game(QString name, float price, QString publisher)
{
    this->setName(name);
    this->setPrice(price);
    this->setPublisher(publisher);
}

QString Game::getName() const
{
    return name;
}

float Game::getPrice() const
{
    return price;
}

QString Game::getPublisher() const
{
    return publisher;
}

void Game::setName(QString name)
{
    if(name.size() <= 0)
        throw "Name string is incorrect";
    this->name = name;
}

void Game::setPrice(float price)
{
    if(price <= 0)
        throw "Price is incorrect";
    this->price = price;
}

void Game::setPublisher(QString publisher)
{
    if(publisher.size() <= 0)
        throw "Publisher string is incorrect";
    this->publisher = publisher;
}

/*bool Game::operator <(const Game& obj) const
{
    if (this->name < obj.name)
        return true;
    else if(this->price < obj.price)
        return true;
    else
        return false;
}*/
