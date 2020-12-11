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

};

#endif // WINDOW_H
