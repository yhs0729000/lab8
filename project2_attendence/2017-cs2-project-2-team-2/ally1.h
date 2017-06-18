#ifndef ALLY1_H
#define ALLY1_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>

class Ally1: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ally1(QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);
    bool adddamage(int damage);
    int currentHp = 900;

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
