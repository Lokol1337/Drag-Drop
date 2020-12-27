#ifndef GOLD_H
#define GOLD_H
#include <QLabel>
#include <QImage>
#include <QPainter>
#include <QTime>

class gold :public QLabel
{
public:
    gold(QWidget *parent = nullptr,int AllMoney = 0);

};

#endif // GOLD_H
