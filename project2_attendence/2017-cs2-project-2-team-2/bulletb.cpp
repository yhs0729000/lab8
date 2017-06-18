
#include "bulletb.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h> // qSin, qCos, qTan
#include "game.h"
#include "enemy.h"
#include "tower2.h"
#include <iostream>
using namespace std;
extern Game * game;

Bulletb::Bulletb(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    // set graphics
    setPixmap(QPixmap(":/new/images/arrow.png"));


    // connect a timer to move()
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);
}




void Bulletb::move(){

    QList<QGraphicsItem*> colliding_items=collidingItems();
        for(int i=0,n=colliding_items.size();i<n;i++){
            if(typeid(*(colliding_items[i]))==typeid(Enemy))
            {
             Enemy* asEnemy = dynamic_cast<Enemy*>(colliding_items[i]);
             asEnemy->adddamage(200); // CREATE addDamage function in Enemy
             if(asEnemy->adddamage(200)==false)

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
            if(typeid(*(colliding_items[i]))==typeid(Tower2))
            {
             Tower2 * asTower = dynamic_cast<Tower2 *>(colliding_items[i]);
             asTower->adddamage(5); // CREATE addDamage function in Enemy
             if(asTower->adddamage(5)==false)

             {
             scene()->removeItem(colliding_items[i]);

             scene()->removeItem(this);
             cout<<"you win"<<endl;

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
