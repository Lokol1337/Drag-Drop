#ifndef GAME_H
#define GAME_H
#include <QFrame>
#include "dragwidget.h"
#include "newclass.h"
#include <QTimer>
#include <QDebug>
#include <label.h>
#include <QObject>
#include "newclass.h"
#include "dragwidget.h"
#include <QTime>
#include <QDebug>
#include <QTimerEvent>
#include <QPainter>
#include "seconds.h"
#include "gold.h"

class game :public QObject
{
    Q_OBJECT

//public slots:
//    void battle();

protected:
    void timerEvent(QTimerEvent *event) override;

public:
    game(QWidget *parent = nullptr);
    DragWidget* Player;
    newClass* Bot;
    void play();
    int turn = 0;
    int timer,time;
    QWidget* _parent;
};

#endif // GAME_H
