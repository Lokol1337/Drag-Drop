#ifndef GAME_H
#define GAME_H
#include <QFrame>
#include "dragwidget.h"
#include "newclass.h"
#include <QTimer>
#include <QDebug>
#include <label.h>
#include <QObject>


class game :public QObject
{
    Q_OBJECT
public slots:
   //void play2();

public:
   label *bufMAG[5];
   label *bufGame[5];
   label *bufMAGBot[5];
   label *bufGameBot[5];
   int money,moneyBot;
   int k = 0;
    game();
    void play(DragWidget *hand = nullptr,newClass *botHand = nullptr);

};

#endif // GAME_H
