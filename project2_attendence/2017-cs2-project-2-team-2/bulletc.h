#ifndef BULLETC_H
#define BULLETC_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Bulletc: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bulletc(QGraphicsItem * parent=0);
public slots:
    void move();
};


#endif // BULLETC_H
