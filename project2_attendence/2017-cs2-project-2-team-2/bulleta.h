#ifndef BULLETA_H
#define BULLETA_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Bulleta: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bulleta(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // BULLET_H
