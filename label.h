#ifndef LABEL_H
#define LABEL_H
#include <QLabel>
#include <QString>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>


class label
         :QLabel
{
public:
    QString name;
    int c;
    int h;
    int d;

    label(QString cardName, int cost, int health, int damage,int x,QWidget *parent = nullptr, int y = 400);
    label(QWidget *parent = nullptr);
    void change(int cost, int health, int damage,int x, int y);
   // label(QWidget *parent = nullptr,QMouseEvent *event = nullptr);
    void moveLabel(int x,int y);
    //void mousePressEvent(QMouseEvent *event);
};

#endif // LABEL_H
