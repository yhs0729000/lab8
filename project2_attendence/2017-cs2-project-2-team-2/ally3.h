#ifndef ALLY3_H
#define ALLY3_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>

class Ally3: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ally3(QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);
    bool adddamage(int damage);
    int currentHp = 2000;

public slots:
    void move_forward();
     void attack_target();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
    QPointF attack_dest;
};


#endif // ALLY3_H
