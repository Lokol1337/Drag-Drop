#include "newclass.h"
#include <QtWidgets>
#include "label.h"
#include "QVector"
#include <random>

int bufKto2[5];
label *bufLabel2[5];
label *bufHandLabel2[5];
int money2 = 10;
QString allCardsName2[3];
int allCardCHD2[3][4];

newClass::newClass(QWidget *parent)
{
    allCardsName2[0] = ":/images/boat.png";
    allCardCHD2[0][1] = 3;
    allCardCHD2[0][2] = 500;
    allCardCHD2[0][3] = 100;

    allCardsName2[1] = ":/images/car.png";
    allCardCHD2[1][1] = 4;
    allCardCHD2[1][2] = 500;
    allCardCHD2[1][3] = 100;

    allCardsName2[2] = ":/images/house.png";
    allCardCHD2[2][1] = 5;
    allCardCHD2[2][2] = 500;
    allCardCHD2[2][3] = 100;

    setMinimumSize(200, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);

    for(int i = 0;i < 5; i++){
        int k = 10+100*i;
        bufKto2[i] = rand()%3;
        qDebug() << bufKto2[i] <<":who:" << allCardsName2[bufKto2[i]] << allCardCHD2[bufKto2[i]][1] << allCardCHD2[bufKto2[i]][2] << allCardCHD2[bufKto2[i]][3];
        bufLabel2[i] = new label(allCardsName2[bufKto2[i]],allCardCHD2[bufKto2[i]][1],allCardCHD2[bufKto2[i]][2],allCardCHD2[bufKto2[i]][3],k,this,100);
    }
    DropBot(this);
}

void newClass::DropBot(QWidget *parent){
    int k2 = 0;
    while(money2>0)
    {
        if(money2<allCardCHD2[0][1] && money2<allCardCHD2[1][1] &&money2<allCardCHD2[2][1] && money2<allCardCHD2[3][1] && money2<allCardCHD2[4][1])
        {
            return;
        }
        int r = rand()%5;

        if(bufLabel2[r]->c<money2)
        {
            bufHandLabel2[k2] = new label(bufLabel2[r]->name,bufLabel2[r]->c,bufLabel2[r]->h,bufLabel2[r]->d,0,parent,0);

            if(k2==0)
               bufHandLabel2[k2]->moveLabel(10,250);
            if(k2==1)
               bufHandLabel2[k2]->moveLabel(110,250);
            if(k2==2)
               bufHandLabel2[k2]->moveLabel(210,250);
            if(k2==3)
               bufHandLabel2[k2]->moveLabel(310,250);
            if(k2==4)
               bufHandLabel2[k2]->moveLabel(410,250);
            k2++;
            money2 = money2-bufLabel2[r]->c;
            delete bufLabel2[r];
        }
    }
}

