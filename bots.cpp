#include "bots.h"



bots::bots(QWidget *parent)
{
    this->setParent(parent);
    QImage bot(":/images/bot.png");
    setPixmap(QPixmap::fromImage(bot));
    setGeometry(900,58,200,266);
}
