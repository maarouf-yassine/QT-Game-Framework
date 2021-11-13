#include "disk.h"

Disk::Disk(QObject *parent) : QObject(parent)
{
    type = rand()%3;
    if(type ==0){
        this->setPixmap((QPixmap(":/images/red-disk.png")).scaled(30,30));
        setPos(140,200);
    }
    else if(type ==1){
        this->setPixmap((QPixmap(":/images/green-disk.jpg")).scaled(30,30));
        setPos(235,200);
    }
    else{
        this->setPixmap((QPixmap(":/images/blue-disk.png")).scaled(30,30));
        setPos(332,200);
    }


    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(500);
}

void Disk:: update(){
    this->setPos(this->x(),this->y()+20);
    /*QList<QGraphicsItem *> list = collidingItems();
    foreach (QGraphicsItem *i, list) {
        if(dynamic_cast<LowerPanelButton*>(i)){
            scene()->removeItem(this);
            delete this;
        }
    }*/
    if(this->y()>=800){
        scene()->removeItem(this);
        delete this;
        //add code to handle missed disk
    }
}