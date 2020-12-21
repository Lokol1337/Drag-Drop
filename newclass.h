#ifndef NEWCLASS_H
#define NEWCLASS_H
#include <QFrame>
#include "label.h"

class QDragEnterEvent;
class QDropEvent;

class newClass: public QFrame
{
public:
    newClass(QWidget *parent = nullptr);
    void DropBot(QWidget *parent = nullptr);
    int CastBotRand();
    label *bufLabel2[5];// возможнные карты к покупке ботом
    label *bufHandLabel2[5];// стол бота
    int money2 = 15;
};

#endif // WINDOW_H
