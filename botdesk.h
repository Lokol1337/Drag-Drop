#ifndef BotDesk_H
#define BotDesk_H
#include <QFrame>
#include "label.h"

class QDragEnterEvent;
class QDropEvent;

class BotDesk: public QFrame
{
public:
    BotDesk(QWidget *parent = nullptr);
    void DropBot(QWidget *parent = nullptr);
    int CastBotRand();
    label *bufLabel2[5];// возможнные карты к покупке ботом
    label *bufHandLabel2[5];// стол бота
    int money2 = 15;

    bool ktoBot[5];
};

#endif // WINDOW_H
