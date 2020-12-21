#include "newclass.h"
#include <QtWidgets>
#include "label.h"
#include "QVector"
#include <QTime>
#include <random>

int bufKto2[5];
bool kto2[5];// проверка наличия карты в массиве
QString allCardsName2[10]; // ссылки на карты
int allCardCHD2[10][4]; // харакртеристики карт

int newClass::CastBotRand(){
    QTime t  = QTime::currentTime();
        return t.msec();
}

newClass::newClass(QWidget *parent)
{
    this->setParent(parent);
    for(int i = 0;i < 5;i++){
        qDebug() << "bug" << kto2[i];
    }

    allCardsName2[0] = ":/images/card1.png";
    allCardCHD2[0][1] = 1;
    allCardCHD2[0][2] = 1;
    allCardCHD2[0][3] = 1;

    allCardsName2[1] = ":/images/card2.png";
    allCardCHD2[1][1] = 2;
    allCardCHD2[1][2] = 2;
    allCardCHD2[1][3] = 2;

    allCardsName2[2] = ":/images/card3.png";
    allCardCHD2[2][1] = 3;
    allCardCHD2[2][2] = 3;
    allCardCHD2[2][3] = 3;

    allCardsName2[3] = ":/images/card4.png";
    allCardCHD2[3][1] = 4;
    allCardCHD2[3][2] = 4;
    allCardCHD2[3][3] = 4;

    allCardsName2[4] = ":/images/card5.png";
    allCardCHD2[4][1] = 5;
    allCardCHD2[4][2] = 5;
    allCardCHD2[4][3] = 5;

    allCardsName2[5] = ":/images/card6.png";
    allCardCHD2[5][1] = 6;
    allCardCHD2[5][2] = 6;
    allCardCHD2[5][3] = 6;

    allCardsName2[6] = ":/images/card7.png";
    allCardCHD2[6][1] = 7;
    allCardCHD2[6][2] = 7;
    allCardCHD2[6][3] = 7;

    allCardsName2[7] = ":/images/card8.png";
    allCardCHD2[7][1] = 8;
    allCardCHD2[7][2] = 8;
    allCardCHD2[7][3] = 8;

    allCardsName2[8] = ":/images/card9.png";
    allCardCHD2[8][1] = 9;
    allCardCHD2[8][2] = 9;
    allCardCHD2[8][3] = 9;

    allCardsName2[9] = ":/images/card10.png";
    allCardCHD2[9][1] = 10;
    allCardCHD2[9][2] = 10;
    allCardCHD2[9][3] = 10;
    //получение данных о картах

    setMinimumSize(200, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);

    for(int i = 0;i < 5; i++){
        int k = 10+150*i;
        bufKto2[i] = (CastBotRand()*rand())%10;
        qDebug() << bufKto2[i] <<":who:" << allCardsName2[bufKto2[i]] << allCardCHD2[bufKto2[i]][1] << allCardCHD2[bufKto2[i]][2] << allCardCHD2[bufKto2[i]][3];
        bufLabel2[i] = new label(allCardsName2[bufKto2[i]],allCardCHD2[bufKto2[i]][1],allCardCHD2[bufKto2[i]][2],allCardCHD2[bufKto2[i]][3],k,this,100);
    }
    //создание карт в магазине бота
    DropBot(this);
    qDebug() << "12345";
}

void newClass::DropBot(QWidget *parent){

    int k2 = 0;
label *bufBufLabel2[5];

for(int i = 0;i < 5;i++){
    bufBufLabel2[i] = bufLabel2[i];
}


    while(money2>=0)
    {
        int counter = 0;
        bool can = true;
        qDebug() << counter << can;
//        while(counter < 5)
//        {
//            qDebug() << kto2[counter];
//            if(kto2[counter] == true)
//            {
//                qDebug() << money2 << bufLabel2[counter]->c;
//                if(money2 >= bufLabel2[counter]->c)
//                {
//                    can = false;
//                }
//            }
//            counter++;
//        }
        if(kto2[0] == false){
            if(money2 >=  bufBufLabel2[0]->c){
                qDebug() << money2 << bufBufLabel2[counter]->c;
                               can = false;
             }
        }
        if(kto2[1] == false){
            if(money2 >=  bufBufLabel2[1]->c){
                qDebug() << money2 <<  bufBufLabel2[counter]->c;
                               can = false;
            }
        }
        if(kto2[2] == false){
            if(money2 >=  bufBufLabel2[2]->c){
                qDebug() << money2 <<  bufBufLabel2[counter]->c;
                               can = false;
             }
        }
        if(kto2[3] == false){
            if(money2 >= bufBufLabel2[3]->c){
                qDebug() << money2 <<  bufBufLabel2[counter]->c;
                               can = false;
             }
        }
        if(kto2[4] == false){
            if(money2 >=  bufBufLabel2[4]->c){
                qDebug() << money2 <<  bufBufLabel2[counter]->c;
                               can = false;
              }
        }
        qDebug() << can;
        if(can == true){
            return;
        }
        //выход из стадии покупки, если ни одна из существующих карт не удолетворяет кол-ву денег бота
        int r = (CastBotRand()*rand())%5;
        while(kto2[r] == true)
            r = (CastBotRand()*rand())%5;

        if(bufLabel2[r]->c<=money2)
        {
            bufHandLabel2[k2] = new label(bufLabel2[r]->name,bufLabel2[r]->c,bufLabel2[r]->h,bufLabel2[r]->d,0,parent,0);

            if(k2==0)
               bufHandLabel2[k2]->moveLabel(10,250);
            if(k2==1)
               bufHandLabel2[k2]->moveLabel(160,250);
            if(k2==2)
               bufHandLabel2[k2]->moveLabel(310,250);
            if(k2==3)
               bufHandLabel2[k2]->moveLabel(460,250);
            if(k2==4)
               bufHandLabel2[k2]->moveLabel(610,250);
            k2++;
            money2 = money2-bufLabel2[r]->c;
            delete bufLabel2[r];
            kto2[r] = true;
        }
        //рандомная покупка карты и её постановка на стол
    }
}

