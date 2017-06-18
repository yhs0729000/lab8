#ifndef ALLY2_H
#define ALLY2_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>

class Ally2: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ally2(QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);
    bool adddamage(int damage);
    int currentHp = 600;

public slots:
    void move_forward();
     void attack_target();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
    QPointF attack_dest;
};


#endif // ALLY2_H
