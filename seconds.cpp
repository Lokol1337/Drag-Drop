#include "seconds.h"

seconds::seconds(QWidget *parent,int AllMoney,QString text)
{
    this->setParent(parent);
    QImage image(":/images/timer.jpg");
    QPainter p(&image);
    p.setPen(QPen(Qt::black));
    p.setFont(QFont("Britannic", 12, QFont::Bold));
    if(text == nullptr)
    {
        QString MString = QString::number(AllMoney);
        if(AllMoney>=10)
         p.drawText(12,27,MString);
        else
         p.drawText(17,27,MString);
    }
    else{
         p.drawText(2,20,text);
    }
    setPixmap(QPixmap::fromImage(image));
    setGeometry(640,512,100,50);
    show();
}

