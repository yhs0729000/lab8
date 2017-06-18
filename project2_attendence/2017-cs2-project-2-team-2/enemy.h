#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QList<QPointF> pointsToFollow, QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);
    bool adddamage(int damage);
    int currentHp=2000;



public slots:
    void moveForward();
    void attack_target();
private:
    QList<QPointF> points;
    QPointF dest;
    QPointF attack_dest;
    int point_index;


};

#endif // ENEMY_H
