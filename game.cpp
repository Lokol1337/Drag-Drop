#include "game.h"



game::game(){}

//void game::play2(){
//    k++;
//    if(k == 1){
//        for(int i = 0; i < 5; i++){
//            delete bufMAG[i];
//            delete bufMAGBot[i]
//        }
//        bufGame[1]
//    }
//}

void game::play(DragWidget *hand,newClass *botHand)
{
//    for(int i = 0; i < 5;i++){
//        bufMAG[i] = hand->bufLabel[i];
//        bufMAGBot[i]=botHand->bufLabel2[i];
//        bufGame[i]=hand->bufHandLabel[i];
//        bufGameBot[i]=botHand->bufHandLabel2[i];
//    }
//   QTimer *time = new QTimer(this);
//   time->setInterval(10000);
//   connect(time,SIGNAL(timeout()),this,SLOT(play2()));
//   time->start();
    while(true)
        qDebug() << hand->money << "AAAAAA";
}
