#include "ally1.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "enemy.h"
#include "tower2.h"
#include "bulleta.h"
#include "game.h"


extern Game *game;

Ally1::Ally1(QGraphicsItem *parent){
    // set graphics
    setPixmap(QPixmap(":/new/images/ally1.png"));

    // set points
    points << QPointF(200,270) << QPoint(1500,270); // move down-right then right
    point_index = 0;
    dest = points[0];
    rotateToPoint(dest);

    // connect timer to move_forward
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150);
}

void Ally1::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
}

void Ally1::move_forward(){
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
        if(typeid(*(colliding_items[i]))==typeid(Enemy))
        {
         Enemy* asEnemy = dynamic_cast<Enemy*>(colliding_items[i]);
         STEP_SIZE=0;
         dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
         dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
         setPos(x()+dx, y()+dy);

         attack_dest = QPointF(10000,0);
         QTimer * timer1 = new QTimer();
             connect(timer1,SIGNAL(timeout()),this,SLOT(attack_target()));
             timer1->start(1000);



        }
    }

            for(int j=0,n=colliding_items.size();j<n;j++){
                if(typeid(*(colliding_items[j]))==typeid(Tower2))
                {
                Tower2* asAlly = dynamic_cast<Tower2*>(colliding_items[j]);
                 STEP_SIZE=0;
                 dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
                 dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
                 setPos(x()+dx, y()+dy);

                 attack_dest = QPointF(10000,0);
                 QTimer * timer1 = new QTimer();
                     connect(timer1,SIGNAL(timeout()),this,SLOT(attack_target()));
                     timer1->start(1000);

                }
            }

    setPos(x()+dx, y()+dy);

}
bool Ally1::adddamage(int damage){



    currentHp -= damage;
    if(currentHp<=0)
    {return false;}
    else
    {return true;}
}
void Ally1::attack_target(){


    Bulleta * bullet = new Bulleta();
    bullet->setPos(x(),y());

    QLineF ln(QPointF(x(),y()),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}
