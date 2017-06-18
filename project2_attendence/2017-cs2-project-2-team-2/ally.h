#ifndef ALLY_H
#define ALLY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>
#include "bullet.h"


class Ally: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ally(QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);
    bool adddamage(int damage);
    int currentHp = 200;

public slots:
    void move_forward();
        void attack_target();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
        QPointF attack_dest;
};

#endif // ENEMY_H
