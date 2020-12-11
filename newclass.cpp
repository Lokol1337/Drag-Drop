#include "newclass.h"
#include <QtWidgets>
#include "label.h"
#include "QVector"
#include <QTime>
#include <random>

int bufKto2[5];
bool *kto2 = new bool(5);// проверка наличия карты в массиве
label *bufLabel2[5];// возможнные карты к покупке ботом
label *bufHandLabel2[5];// стол бота
int money2 = 10;
QString allCardsName2[3]; // ссылки на карты
int allCardCHD2[3][4]; // харакртеристики карт

int newClass::CastBotRand(){
    QTime t  = QTime::currentTime();
        return t.msec();
}

newClass::newClass(QWidget *parent)
{
    for(int i = 0;i < 5;i++){
        qDebug() << "bug" << kto2[i];
    }
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
    //получение данных о картах

    setMinimumSize(200, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);

    for(int i = 0;i < 5; i++){
        int k = 10+100*i;
        bufKto2[i] = (CastBotRand()*rand())%3;
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
        if(kto2[0] == true){
            if(money2 >=  bufBufLabel2[0]->c)
                            {
                qDebug() << money2 << bufBufLabel2[counter]->c;
                               can = false;
                           }
        }
        if(kto2[1] == true){
            if(money2 >=  bufBufLabel2[1]->c)
                            {
                qDebug() << money2 <<  bufBufLabel2[counter]->c;
                               can = false;
                           }
        }
        if(kto2[2] == true){
            if(money2 >=  bufBufLabel2[2]->c)
                            {
                qDebug() << money2 <<  bufBufLabel2[counter]->c;
                               can = false;
                           }
        }
        if(kto2[3] == true){
            if(money2 >= bufBufLabel2[3]->c)
                            {
                qDebug() << money2 <<  bufBufLabel2[counter]->c;
                               can = false;
                           }
        }
        if(kto2[4] == true){
            if(money2 >=  bufBufLabel2[4]->c)
                            {
                qDebug() << money2 <<  bufBufLabel2[counter]->c;
                               can = false;
                           }
        }

        qDebug() << "can:" << can;
        if(can == true){
            qDebug() << "puk";
            return;

        }
        //выход из стадии покупки, если ни одна из существующих карт не удолетворяет кол-ву денег бота
        int r = (CastBotRand()*rand())%5;
        while(kto2[r] == false)
            r = (CastBotRand()*rand())%5;

        if(bufLabel2[r]->c<=money2)
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
            kto2[r] = false;
        }
        //рандомная покупка карты и её постановка на стол
    }
}

