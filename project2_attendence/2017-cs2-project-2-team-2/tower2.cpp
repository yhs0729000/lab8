#include "tower2.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include "bullet2.h"
#include <QPointF>
#include <QLineF>
#include "game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include "ally.h"

extern Game * game;

Tower2::Tower2(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){
    // set the graphics
    setPixmap(QPixmap(":/new/images/tower2.png"));

    // create points vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
               << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    // scale points
    int SCALE_FACTOR = 75;
    for (size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE_FACTOR;
    }

    // create the QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);

    // move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);;
    QPointF tower_center(x()+47,y()+47);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    // connect a timer to attack_target
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(50);


    attack_dest = QPointF(0,0);
}

double Tower2::distanceTo(QGraphicsItem *item){
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void Tower2::fire(){
    Bullet2 * bullet2 = new Bullet2();
    bullet2->setPos(x()+20,y()+20);

    QLineF ln(QPointF(x(),y()),attack_dest);
    int angle = -1 * ln.angle();

    bullet2->setRotation(angle);
    game->scene->addItem(bullet2);
}

void Tower2::aquire_target(){
    // get a list of all items colliding with attack_area
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();

    if (colliding_items.size() == 1){
        has_target = false;
        return;
    }

    double closest_dist = 300;
    QPointF closest_pt = QPointF(0,0);
    for (size_t i = 0, n = colliding_items.size(); i < n; i++){
        Ally * ally = dynamic_cast<Ally *>(colliding_items[i]);
        if (ally){
            double this_dist = distanceTo(ally);
            if (this_dist < closest_dist){
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
    }

    attack_dest = closest_pt;
    fire();

}
bool Tower2::adddamage(int damage){



    currentHp -= damage;
    if(currentHp<=0)
    {return false;}
    else
    {return true;}
}
