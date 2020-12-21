#include "gold.h"

gold::gold(QWidget *parent,int AllMoney)
{
    this->setParent(parent);
    QImage image(":/images/money.png");
    QPainter p(&image);
    p.setPen(QPen(Qt::white));
    p.setFont(QFont("Britannic", 12, QFont::Bold));
    QString MString = QString::number(AllMoney);
    if(AllMoney>=10)
     p.drawText(12,27,MString);
    else
     p.drawText(17,27,MString);
    setPixmap(QPixmap::fromImage(image));
    setGeometry(1100,100,45,45);
    show();
}
