#include "label.h"


label::label(QString cardName, int cost, int health, int damage,int x, QWidget *parent,int y)
{
    name = cardName;
    c = cost;
    h = health;
    d = damage;
    QString CString = QString::number(cost);
    this->setParent(parent);
    QImage image(name);
    QPainter p(&image);
    p.setPen(QPen(Qt::red));
    p.setFont(QFont("Times", 12, QFont::Bold));
    p.drawText(image.rect(), Qt::AlignCenter, CString);
    setPixmap(QPixmap::fromImage(image));
    setGeometry(x,y,140,170);
    show();
}
label::label(QWidget *parent){
    this->setParent(parent);
    this->show();
}

void label::moveLabel(int x, int y){
    this->move(x,y);
    show();
}





