#ifndef GAME_H
#define GAME_H
#include <QFrame>
#include "playerdesk.h"
#include "botdesk.h"
#include <QTimer>
#include <QDebug>
#include <label.h>
#include <QObject>
#include <QTime>
#include <QDebug>
#include <QTimerEvent>
#include <QPainter>
#include "seconds.h"
#include "gold.h"
#include <QMessageBox>
#include "heroes.h"
#include "bots.h"

class game :public QObject
{
    Q_OBJECT

//public slots:
//    void battle();

protected:
    void timerEvent(QTimerEvent *event) override;

public:
    game(QWidget *parent = nullptr);
    PlayerDesk* Player;
    BotDesk* Bot;
    void play();
    bool start = false;
    int turn = 0;
    int timer,time;
    QWidget* _parent;
    bool kto2[5];
    bool ktoBot2[5];
    int bufCounter1 = 0;
    int bufCounter2 = 0;

    int counter1 = 0;
    int counter2 = 0;
};

#endif // GAME_H
