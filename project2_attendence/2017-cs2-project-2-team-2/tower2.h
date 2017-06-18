#ifndef TOWER2_H
#define TOWER2_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Tower2:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower2(QGraphicsItem * parent=0);
    double distanceTo(QGraphicsItem * item);
    void fire();
    int currentHp=30000;
    bool adddamage(int damage);
public slots:
    void aquire_target();
private:
    QGraphicsPolygonItem * attack_area;
    QPointF attack_dest;
    bool has_target;
};

#endif // TOWER2_H
