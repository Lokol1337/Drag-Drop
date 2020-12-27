#include "heroes.h"

heroes::heroes(QWidget *parent)
{
    this->setParent(parent);
    QImage player(":/images/player.png");
    setPixmap(QPixmap::fromImage(player));
    setGeometry(900,700,200,246);
}
