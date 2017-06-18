#include "enemy.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "game.h"
#include "ally.h"
#include "tower.h"
#include "bullet2.h"
#include "ally1.h"
#include "ally2.h"
#include "ally3.h"
extern Game *game;
extern Ally *ally;
extern Tower *tower;
extern Bullet2 *bullet2;

Enemy::Enemy(QList<QPointF> pointsToFollow, QGraphicsItem *parent){
    // set graphics
    setPixmap(QPixmap(":/new/images/enemy.png"));

    // set points
    points = pointsToFollow; // move down-right then right
    point_index = 0;
    dest = points[0];
    rotateToPoint(dest);

    // connect timer to move_forward
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveForward()));
    timer->start(150);



}

void Enemy::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
}

void Enemy::moveForward(){
    // if close to dest, rotate to next dest
    QLineF ln(pos(),dest);
    if (ln.length() < 5){
        point_index++;
        dest = points[point_index];
        rotateToPoint(dest);
    }

    // move enemy forward at current angle
    int STEP_SIZE = 5;
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));



    QList<QGraphicsItem*> colliding_items=collidingItems();
        for(int i=0,n=colliding_items.size();i<n;i++){
            if(typeid(*(colliding_items[i]))==typeid(Ally))
            {
             Ally* asAlly = dynamic_cast<Ally*>(colliding_items[i]);
             STEP_SIZE=0;
             dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
             dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
             setPos(x()+dx, y()+dy);


             attack_dest = QPointF(-5000,0);
             QTimer * timer1 = new QTimer();
                 connect(timer1,SIGNAL(timeout()),this,SLOT(attack_target()));
                 timer1->start(1000);


            }
            if(typeid(*(colliding_items[i]))==typeid(Ally1))
            {
             Ally1* asAlly1 = dynamic_cast<Ally1*>(colliding_items[i]);
             STEP_SIZE=0;
             dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
             dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
             setPos(x()+dx, y()+dy);


             attack_dest = QPointF(-5000,0);
             QTimer * timer1 = new QTimer();
                 connect(timer1,SIGNAL(timeout()),this,SLOT(attack_target()));
                 timer1->start(1000);


            }
            if(typeid(*(colliding_items[i]))==typeid(Ally2))
            {
             Ally2* asAlly2 = dynamic_cast<Ally2*>(colliding_items[i]);
             STEP_SIZE=0;
             dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
             dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
             setPos(x()+dx, y()+dy);


             attack_dest = QPointF(-5000,0);
             QTimer * timer1 = new QTimer();
                 connect(timer1,SIGNAL(timeout()),this,SLOT(attack_target()));
                 timer1->start(1000);


            }
            if(typeid(*(colliding_items[i]))==typeid(Ally3))
            {
             Ally3* asAlly1 = dynamic_cast<Ally3*>(colliding_items[i]);
             STEP_SIZE=0;
             dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
             dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
             setPos(x()+dx, y()+dy);


             attack_dest = QPointF(-5000,0);
             QTimer * timer1 = new QTimer();
                 connect(timer1,SIGNAL(timeout()),this,SLOT(attack_target()));
                 timer1->start(1000);


            }
        }


            for(int j=0,n=colliding_items.size();j<n;j++){
                if(typeid(*(colliding_items[j]))==typeid(Tower))
                {
                Tower* asAlly = dynamic_cast<Tower*>(colliding_items[j]);
                 STEP_SIZE=0;
                 dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
                 dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
                 setPos(x()+dx, y()+dy);

                 attack_dest = QPointF(-5000,0);
                 QTimer * timer1 = new QTimer();
                     connect(timer1,SIGNAL(timeout()),this,SLOT(attack_target()));
                     timer1->start(1000);


                }
            }

     setPos(x()+dx, y()+dy);
}
bool Enemy::adddamage(int damage){



    currentHp -= damage;
    if(currentHp<=0)
    {return false;}
    else
    {return true;}
}

void Enemy::attack_target(){


    Bullet2 * bullet2 = new Bullet2();
    bullet2->setPos(x(),y());

    QLineF ln(QPointF(x(),y()),attack_dest);
    int angle = -1 * ln.angle();

    bullet2->setRotation(angle);
    game->scene->addItem(bullet2);
}






