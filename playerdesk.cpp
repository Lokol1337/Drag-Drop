/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>

#include "playerdesk.h"
#include "label.h"
#include "QVector"
#include <QTime>
#include <random>
#include <QPixmap>
#include "gold.h"


//bool *kto = new bool(5);// проверка наличия места для постановки карты
int bufKto[5];// порядковый номер карты
label *dragBuf;
QString allCardsName[10];// ссылки на карты
int allCardCHD[10][4];// харакртеристики карт



int PlayerDesk::CastRand(){ // получение мсек в реал времени
    QTime t  = QTime::currentTime();
        return t.msec();
}

PlayerDesk::PlayerDesk(QWidget *parent)
    : QFrame(parent)
{
    this->setParent(parent);
    allCardsName[0] = ":/images/card1.png";
        allCardCHD[0][1] = 1;
        allCardCHD[0][2] = 1;
        allCardCHD[0][3] = 1;

        allCardsName[1] = ":/images/card2.png";
        allCardCHD[1][1] = 2;
        allCardCHD[1][2] = 2;
        allCardCHD[1][3] = 3;

        allCardsName[2] = ":/images/card3.png";
        allCardCHD[2][1] = 3;
        allCardCHD[2][2] = 2;
        allCardCHD[2][3] = 4;

        allCardsName[3] = ":/images/card4.png";
        allCardCHD[3][1] = 4;
        allCardCHD[3][2] = 3;
        allCardCHD[3][3] = 3;

        allCardsName[4] = ":/images/card5.png";
        allCardCHD[4][1] = 5;
        allCardCHD[4][2] = 5;
        allCardCHD[4][3] = 5;

        allCardsName[5] = ":/images/card6.png";
        allCardCHD[5][1] = 3;
        allCardCHD[5][2] = 2;
        allCardCHD[5][3] = 2;

        allCardsName[6] = ":/images/card7.png";
        allCardCHD[6][1] = 6;
        allCardCHD[6][2] = 4;
        allCardCHD[6][3] = 7;

        allCardsName[7] = ":/images/card8.png";
        allCardCHD[7][1] = 2;
        allCardCHD[7][2] = 3;
        allCardCHD[7][3] = 2;

        allCardsName[8] = ":/images/card9.png";
        allCardCHD[8][1] = 7;
        allCardCHD[8][2] = 8;
        allCardCHD[8][3] = 5;

        allCardsName[9] = ":/images/card10.png";
        allCardCHD[9][1] = 4;
        allCardCHD[9][2] = 5;
        allCardCHD[9][3] = 1;

    //получение данных о картах

    setMinimumSize(200,200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    for(int i = 0;i < 5; i++){
        int k = 10+150*i;
        //qDebug() << CastRand();
        bufKto[i] = (CastRand()*rand())%10;
        //qDebug() << bufKto[i] <<":who:" << allCardsName[bufKto[i]] << allCardCHD[bufKto[i]][1] << allCardCHD[bufKto[i]][2] << allCardCHD[bufKto[i]][3];
        bufLabel[i] = new label(allCardsName[bufKto[i]],allCardCHD[bufKto[i]][1],allCardCHD[bufKto[i]][2],allCardCHD[bufKto[i]][3],k,this,300);
    }
    // создание поля и рандом карт в магазин

}

void PlayerDesk::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->source() == this && event->pos().y()>this->height()/2){ // разрешение на взятие карты в допустимом поле
       event->acceptProposedAction();
    }
    else{
        event->ignore();
    }
}

void PlayerDesk::dragMoveEvent(QDragMoveEvent *event)
{
        if(event->source() == this && event->pos().y()<this->height()/2 && money-dragBuf->c>=0){ // проверка на наличия денег для покупки (+возможность взять карту)
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        if(event->source() == this && event->pos().y()>this->height()/2){
            event->ignore();
        }
}

void PlayerDesk::dropEvent(QDropEvent *event)
{
   if(event->source() == this && event->pos().y()<this->height()/2)
   {
        money = money - dragBuf->c;
        //qDebug() << money;
        event->setDropAction(Qt::MoveAction);
        event->accept();
        int k = 0;
        while(kto[k] == false) // проверка занятых позиций на столе
        {
            k++;
        }
        kto[k] = false;

        bufHandLabel[k] = new label(dragBuf->name,dragBuf->c,dragBuf->h,dragBuf->d,0,this,0);

        if(k==0)
           bufHandLabel[k]->moveLabel(10,100);
        if(k==1)
           bufHandLabel[k]->moveLabel(160,100);
        if(k==2)
           bufHandLabel[k]->moveLabel(310,100);
        if(k==3)
           bufHandLabel[k]->moveLabel(460,100);
        if(k==4)
           bufHandLabel[k]->moveLabel(610,100);
        //постановка карты на стол после покупки
    }
}

void PlayerDesk::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        //qDebug()<< "this: " << event->pos() << this->height()/2;
        if(event->pos().x()>=10 && event->pos().x()<=150 && event->pos().y()>=300 && event->pos().y()<=470){
           dragBuf = bufLabel[0];
        }
        if(event->pos().x()>=160 && event->pos().x()<=300 && event->pos().y()>=300 && event->pos().y()<=470){
           dragBuf = bufLabel[1];
        }
        if(event->pos().x()>=310 && event->pos().x()<=450 && event->pos().y()>=300 && event->pos().y()<=470){
            dragBuf = bufLabel[2];
        }
        if(event->pos().x()>=460 && event->pos().x()<=600 && event->pos().y()>=300 && event->pos().y()<=470){
           dragBuf = bufLabel[3];
        }
        if(event->pos().x()>=610 && event->pos().x()<=750 && event->pos().y()>=300 && event->pos().y()<=470){
           dragBuf = bufLabel[4];
        }
        // получение данных о выбранной карте
        QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
            if (!child)
                return;

        QPixmap pixmap = child->pixmap(Qt::ReturnByValue);

        QByteArray itemData;
        QDataStream dataStream(&itemData, QIODevice::WriteOnly);
        dataStream << pixmap << QPoint(event->pos() - child->pos());

        QMimeData *mimeData = new QMimeData;
        mimeData->setData("application/x-dnditemdata", itemData);

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(pixmap);
        drag->setHotSpot(event->pos() - child->pos());

        QPixmap tempPixmap = pixmap;
        QPainter painter;
        painter.begin(&tempPixmap);
        painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
        painter.end();
        child->setPixmap(tempPixmap);


        if (drag->exec(Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
            child->close();
        }
        else {
            child->show();
            child->setPixmap(pixmap);
        }
        // создание анимации переноса карты по полю
     }
    if(event->button() == Qt::RightButton){
        if((event->pos().x()>=10 && event->pos().x()<=150 && event->pos().y()>=100 && event->pos().y()<=270)&&bufHandLabel[0]!=nullptr){
          money = money + bufHandLabel[0]->c;
          kto[0] = true;
          delete bufHandLabel[0] ;
        }
        if((event->pos().x()>=160 && event->pos().x()<=300 && event->pos().y()>=100 && event->pos().y()<=270)&&bufHandLabel[1]!=nullptr){
          money = money + bufHandLabel[1]->c;
          kto[1] = true;
          delete bufHandLabel[1];
        }
        if((event->pos().x()>=310 && event->pos().x()<=450 && event->pos().y()>=100 && event->pos().y()<=270)&&bufHandLabel[2]!=nullptr){
          money = money + bufHandLabel[2]->c;
           kto[2] = true;
          delete bufHandLabel[2];
        }
        if((event->pos().x()>=460 && event->pos().x()<=600 && event->pos().y()>=100 && event->pos().y()<=270)&&bufHandLabel[3]!=nullptr){
          money = money + bufHandLabel[3]->c;
           kto[3] = true;
          delete bufHandLabel[3];
        }
        if((event->pos().x()>=610 && event->pos().x()<=750 && event->pos().y()>=100 && event->pos().y()<=270)&&bufHandLabel[4]!=nullptr){
          money = money + bufHandLabel[4]->c;
           kto[4] = true;
          delete bufHandLabel[4];
        }
    }
    //удаление купленной карты по нажатию правой кнопки мыши


}
