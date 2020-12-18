#include "label.h"


label::label(QString cardName, int cost, int health, int damage,int x, QWidget *parent,int y)
{
    name = cardName;
    c = cost;
    h = health;
    d = damage;
    QString CString = QString::number(cost);
    QString HString = QString::number(health);
    QString DString = QString::number(damage);
    this->setParent(parent);
    QImage image(name);
    QPainter p(&image);
    p.setPen(QPen(Qt::white));
    p.setFont(QFont("Britannic", 12, QFont::Bold));
    p.drawText(23,34,CString);
    p.drawText(100,152,HString);
    p.drawText(23,152,DString);
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





