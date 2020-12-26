#include "game.h"



game::game(QWidget *parent){

    Bot = new newClass(parent);
    Bot->setGeometry(0,0,1280,512);

    Player =new DragWidget(parent);
    Player->setGeometry(0,512,1280,512);

    timer = 100;
    this->startTimer(100);
    _parent = parent;

    time = 20;
}

void game::timerEvent(QTimerEvent *event){
    play();
    if(timer!=-1)
        timer-=1;

    if(timer == -1)
        time+=1;
    //qDebug() << time;
}

void game::play()
{
    gold *GOLD = new gold(_parent,Player->money);
    if(timer!=-1)
        seconds *_S = new seconds(_parent,(timer - timer%10)/10);

    if(timer==0)
    {
        seconds *_S = new seconds(_parent,0,"timeout");
        timer = -1;


        for(int i = 0;i < 5;i++)
        {
            kto2[i] = Player->kto[i];
            ktoBot2[i] = Bot->ktoBot[i];
            if(kto2[i] == false)
                counter1++;
            if(ktoBot2[i] == false)
                counter2++;
        }
    }



    if(timer == -1)
    {

            qDebug() <<"counter1:" <<counter1;

            if(counter1 > 0 && counter2 > 0 && time%20==0)
            {
                qDebug() << time;
                for(int i = 0;i < 5;i++){
                    qDebug() << kto2[i] << " ";
                }
                int i = 0;
                while(kto2[i] == true)
                    i++;

                int j = 0;
                while(ktoBot2[j] == true)
                    j++;

                int k = 10 + 150*i;
                int kBot = 10 + 150*j;

                if(i==0)
                   Player->bufHandLabel[i]->moveLabel(10,80);
                if(i==1)
                  Player->bufHandLabel[i]->moveLabel(160,80);
                if(i==2)
                   Player->bufHandLabel[i]->moveLabel(310,80);
                if(i==3)
                   Player->bufHandLabel[i]->moveLabel(460,80);
                if(i==4)
                   Player->bufHandLabel[i]->moveLabel(610,80);

                if(j==0)
                   Bot->bufHandLabel2[j]->moveLabel(10,260);
                if(j==1)
                  Bot->bufHandLabel2[j]->moveLabel(160,260);
                if(j==2)
                  Bot->bufHandLabel2[j]->moveLabel(310,260);
                if(j==3)
                   Bot->bufHandLabel2[j]->moveLabel(460,260);
                if(j==4)
                   Bot->bufHandLabel2[j]->moveLabel(610,260);

                if(time%30 == 0)
                {
                    Player->bufHandLabel[i]->h = Player->bufHandLabel[i]->h - Bot->bufHandLabel2[j]->d;
                    Bot->bufHandLabel2[j]->h = Bot->bufHandLabel2[j]->h -  Player->bufHandLabel[i]->d;

                    if(Player->bufHandLabel[i]->h > 0)
                    {
                        kto2[i] =true;
                        Player->bufHandLabel[i]->change(Player->bufHandLabel[i]->c,Player->bufHandLabel[i]->h,Player->bufHandLabel[i]->d,k,100);
                    }

                    else
                    {
                        kto2[i] = true;
                        Player->kto[i] = true;
                        delete Player->bufHandLabel[i];
                    }

                    if(Bot->bufHandLabel2[j]->h>0)
                    {
                        ktoBot2[j] = true;
                        Bot->bufHandLabel2[j]->change(Bot->bufHandLabel2[j]->c,Bot->bufHandLabel2[j]->h,Bot->bufHandLabel2[j]->d,kBot,250);
                    }

                    else
                    {
                        ktoBot2[j] = true;
                        Bot->ktoBot[j] = true;
                        delete Bot->bufHandLabel2[j];
                    }
                    bufCounter1++;
                    bufCounter2++;
                    qDebug() << "bufCounter1: "<< bufCounter1;
                    if(bufCounter1 == counter1)
                    {
                        qDebug() << "AAAAAAAAaa";
                         counter1 = 0;
                        for(int a = 0; a < 5;a++)
                        {
                            if(Player->kto[a] == false)
                                counter1++;
                            kto2[a] = Player->kto[a];
                        }
                        bufCounter1 = 0;
                    }

                    if(bufCounter2 == counter2)
                    {
                        counter2 = 0;
                        for(int a = 0; a < 5;a++)
                        {
                            if(Bot->ktoBot[a] == false)
                                counter2++;
                            ktoBot2[a] = Bot->ktoBot[a];
                        }
                        bufCounter2 = 0;
                    }
                }
            }


            if(counter1 == 0 && counter2!=0)
            {
                QMessageBox::StandardButton reply = QMessageBox::warning(_parent, "Поражение(((", "Пока!!!",QMessageBox::Ok);
                if (reply == QMessageBox::Ok)
                                            {
                                               _parent->close();
                                            }

            }

            if(counter2 == 0 && counter1!=0)
            {
                QMessageBox::StandardButton reply = QMessageBox::warning(_parent, "Победа)))", "Ну ты крутой!!!", QMessageBox::Ok);
                if (reply == QMessageBox::Ok)
                                            {
                                                _parent->close();
                                            }
            }


            if(counter1 == 0 && counter2==0)
            {
                QMessageBox::StandardButton reply = QMessageBox::warning(_parent, "Ничья!!!", "Сходи пости, а потом попробуй еще раз", QMessageBox::Ok);
                if (reply == QMessageBox::Ok)
                                            {
                                               _parent->close();
                                            }

            }
          //


    }
}
