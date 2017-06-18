#ifndef BULLETB_H
#define BULLETB_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Bulletb: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bulletb(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // BULLET_H
