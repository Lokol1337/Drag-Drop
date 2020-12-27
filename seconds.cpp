#include "seconds.h"

seconds::seconds(QWidget *parent,int AllMoney,QString text)
{
    this->setParent(parent);
    QImage image(":/images/clock.png");
    QPainter p(&image);
    p.setPen(QPen(Qt::white));
    p.setFont(QFont("Britannic", 12, QFont::Bold));
    setGeometry(975,487,50,50);
    if(text == nullptr)
    {
        QString MString = QString::number(AllMoney);
//        if(AllMoney>=10)
//         p.drawText(12,27,MString);
//        else
//         p.drawText(17,27,MString);
        p.drawText(20,35,MString);
    }
    else{
         p.drawText(2,30,text);
    }
    setPixmap(QPixmap::fromImage(image));

    show();
}

