#ifndef SECONDS_H
#define SECONDS_H
#include <QLabel>
#include <QImage>
#include <QPainter>
#include <QTime>

class seconds :public QLabel
{

public:
    seconds(QWidget *parent = nullptr,int AllMoney = 0,QString text = nullptr);
};

#endif // SECONDS_H
