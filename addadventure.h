#ifndef ADDADVENTURE_H
#define ADDADVENTURE_H

#include <QWidget>

namespace Ui {
class AddAdventure;
}

class AddAdventure : public QWidget
{
    Q_OBJECT

public:
    explicit AddAdventure(QWidget *parent = nullptr);
    ~AddAdventure();

private:
    Ui::AddAdventure *ui;
};

#endif // ADDADVENTURE_H
