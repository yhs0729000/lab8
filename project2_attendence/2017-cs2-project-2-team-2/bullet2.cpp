
#include "bullet2.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h> // qSin, qCos, qTan
#include "game.h"
#include "tower.h"
#include "ally.h"
#include "ally1.h"
#include "ally2.h"
#include "ally3.h"
#include <iostream>

using namespace std;

extern Game * game;

Bullet2::Bullet2(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    // set graphics
    setPixmap(QPixmap(":/new/images/arrow2.png"));


    // connect a timer to move()
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);
}




void Bullet2::move(){

    QList<QGraphicsItem*> colliding_items=collidingItems();
        for(int i=0,n=colliding_items.size();i<n;i++){
            if(typeid(*(colliding_items[i]))==typeid(Ally))
            {
             Ally * asAlly = dynamic_cast<Ally *>(colliding_items[i]);
             asAlly->adddamage(100); // CREATE addDamage function in Enemy
             if(asAlly->adddamage(100)==false)

             {
             scene()->removeItem(colliding_items[i]);

             scene()->removeItem(this);


             delete colliding_items[i];
             delete this;
             return;
             }
             else
             {
                 scene()->removeItem(this);
             delete this;
             return;
             }
           }
            if(typeid(*(colliding_items[i]))==typeid(Ally1))
            {
             Ally1 * asAlly1 = dynamic_cast<Ally1 *>(colliding_items[i]);
             asAlly1->adddamage(100); // CREATE addDamage function in Enemy
             if(asAlly1->adddamage(100)==false)

             {
             scene()->removeItem(colliding_items[i]);

             scene()->removeItem(this);


             delete colliding_items[i];
             delete this;
             return;
             }
             else
             {
                 scene()->removeItem(this);
             delete this;
             return;
             }
           }
            if(typeid(*(colliding_items[i]))==typeid(Ally2))
            {
             Ally2 * asAlly2 = dynamic_cast<Ally2 *>(colliding_items[i]);
             asAlly2->adddamage(100); // CREATE addDamage function in Enemy
             if(asAlly2->adddamage(100)==false)

             {
             scene()->removeItem(colliding_items[i]);

             scene()->removeItem(this);


             delete colliding_items[i];
             delete this;
             return;
             }
             else
             {
                 scene()->removeItem(this);
             delete this;
             return;
             }
           }
            if(typeid(*(colliding_items[i]))==typeid(Ally3))
            {
             Ally3 * asAlly3 = dynamic_cast<Ally3 *>(colliding_items[i]);
             asAlly3->adddamage(100); // CREATE addDamage function in Enemy
             if(asAlly3->adddamage(100)==false)

             {
             scene()->removeItem(colliding_items[i]);

             scene()->removeItem(this);


             delete colliding_items[i];
             delete this;
             return;
             }
             else
             {
                 scene()->removeItem(this);
             delete this;
             return;
             }
           }

 }
        for(int i=0,n=colliding_items.size();i<n;i++){
            if(typeid(*(colliding_items[i]))==typeid(Tower))
            {
             Tower * asTower = dynamic_cast<Tower *>(colliding_items[i]);
             asTower->adddamage(5); // CREATE addDamage function in Enemy
             if(asTower->adddamage(5)==false)

             {
             scene()->removeItem(colliding_items[i]);

             scene()->removeItem(this);
             cout<<"you lose"<<endl;

             scene()->clear();


             delete colliding_items[i];
             delete this;

             return;
             }
             else
             {
                 scene()->removeItem(this);
             delete this;
             return;
             }
           }
        }

    int STEP_SIZE = 70;
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);


}
