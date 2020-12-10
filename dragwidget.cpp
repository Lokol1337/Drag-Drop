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

#include "dragwidget.h"
#include "label.h"
#include "QVector"
#include <QTime>
#include <random>


bool *kto = new bool(5);
int bufKto[5];
label *bufLabel[5];
label *bufHandLabel[5];
label *dragBuf;
int money = 10;
QString allCardsName[3];
int allCardCHD[3][4];


int DragWidget::CastRand(){
    QTime t  = QTime::currentTime();
        return t.msec();
}

DragWidget::DragWidget(QWidget *parent)
    : QFrame(parent)
{
    allCardsName[0] = ":/images/boat.png";
    allCardCHD[0][1] = 3;
    allCardCHD[0][2] = 500;
    allCardCHD[0][3] = 100;

    allCardsName[1] = ":/images/car.png";
    allCardCHD[1][1] = 4;
    allCardCHD[1][2] = 500;
    allCardCHD[1][3] = 100;

    allCardsName[2] = ":/images/house.png";
    allCardCHD[2][1] = 5;
    allCardCHD[2][2] = 500;
    allCardCHD[2][3] = 100;

    setMinimumSize(200,200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    for(int i = 0;i < 5; i++){
        int k = 10+100*i;
        qDebug() << CastRand();
        bufKto[i] = (CastRand()*rand())%3;
        qDebug() << bufKto[i] <<":who:" << allCardsName[bufKto[i]] << allCardCHD[bufKto[i]][1] << allCardCHD[bufKto[i]][2] << allCardCHD[bufKto[i]][3];
        bufLabel[i] = new label(allCardsName[bufKto[i]],allCardCHD[bufKto[i]][1],allCardCHD[bufKto[i]][2],allCardCHD[bufKto[i]][3],k,this,250);
    }
}

void DragWidget::dragEnterEvent(QDragEnterEvent *event)
{
    QPoint Bag2 = event->pos();
    qDebug() << "Move" << Bag2;

    if(event->source() == this && event->pos().y()>this->height()/2){
       event->acceptProposedAction();
    }
    else{
        event->ignore();
    }
}

void DragWidget::dragMoveEvent(QDragMoveEvent *event)
{

        QPoint Bag2 = event->pos();
        qDebug() << "Move" << Bag2;
        qDebug() << "money" << dragBuf->c;
        if(event->source() == this && event->pos().y()<this->height()/2 && money-dragBuf->c>=0){
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        if(event->source() == this && event->pos().y()>this->height()/2){
            event->ignore();
        }

}

void DragWidget::dropEvent(QDropEvent *event)
{
   if(event->source() == this && event->pos().y()<this->height()/2)
   {
        money = money - dragBuf->c;
        qDebug() << money;
        event->setDropAction(Qt::MoveAction);
        event->accept();
        int k = 0;
        while(kto[k] == false)
        {
            k++;
        }
        kto[k] = false;
        bufHandLabel[k] = new label(dragBuf->name,dragBuf->c,dragBuf->h,dragBuf->d,0,this,0);

        if(k==0)
           bufHandLabel[k]->moveLabel(10,100);
        if(k==1)
           bufHandLabel[k]->moveLabel(110,100);
        if(k==2)
           bufHandLabel[k]->moveLabel(210,100);
        if(k==3)
           bufHandLabel[k]->moveLabel(310,100);
        if(k==4)
           bufHandLabel[k]->moveLabel(410,100);
    }
}

void DragWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        qDebug()<< "this: " << event->pos() << this->height()/2;
        if(event->pos().x()>=10 && event->pos().x()<=110 && event->pos().y()>=250 && event->pos().y()<=350){
           dragBuf = bufLabel[0];
        }
        if(event->pos().x()>=110 && event->pos().x()<=210 && event->pos().y()>=250 && event->pos().y()<=350){
           dragBuf = bufLabel[1];
        }
        if(event->pos().x()>=210 && event->pos().x()<=310 && event->pos().y()>=250 && event->pos().y()<=350){
            dragBuf = bufLabel[2];
        }
        if(event->pos().x()>=310 && event->pos().x()<=410 && event->pos().y()>=250 && event->pos().y()<=350){
           dragBuf = bufLabel[3];
        }
        if(event->pos().x()>=410 && event->pos().x()<=510 && event->pos().y()>=250 && event->pos().y()<=350){
           dragBuf = bufLabel[4];
        }
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
            } else {
                child->show();
                child->setPixmap(pixmap);
            }
     }
    if(event->button() == Qt::RightButton){
        if(event->pos().x()>=10 && event->pos().x()<=110 && event->pos().y()>=100 && event->pos().y()<=200){
          money = money + bufHandLabel[0]->c;
          kto[0] = true;
          delete bufHandLabel[0] ;
        }
        if(event->pos().x()>=110 && event->pos().x()<=210 && event->pos().y()>=100 && event->pos().y()<=200){
          money = money + bufHandLabel[1]->c;
          kto[1] = true;
          delete bufHandLabel[1];
        }
        if(event->pos().x()>=210 && event->pos().x()<=310 && event->pos().y()>=100 && event->pos().y()<=200){
          money = money + bufHandLabel[2]->c;
           kto[2] = true;
          delete bufHandLabel[2];
        }
        if(event->pos().x()>=310 && event->pos().x()<=410 && event->pos().y()>=100 && event->pos().y()<=200){
          money = money + bufHandLabel[3]->c;
           kto[3] = true;
          delete bufHandLabel[3];
        }
        if(event->pos().x()>=410 && event->pos().x()<=510 && event->pos().y()>=100 && event->pos().y()<=200){
          money = money + bufHandLabel[4]->c;
           kto[4] = true;
          delete bufHandLabel[4];
        }
    }
}
