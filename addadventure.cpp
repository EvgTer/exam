#include "addadventure.h"
#include "ui_addadventure.h"

AddAdventure::AddAdventure(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddAdventure)
{
    ui->setupUi(this);
}

AddAdventure::~AddAdventure()
{
    delete ui;
}
