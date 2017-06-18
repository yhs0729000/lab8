
#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>

#include <QGraphicsScene>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    // member functions
    Game();


     void createEnemies(int numberOfEnemies);
     void end1();
    // member attributes
    QGraphicsScene * scene;
    QTimer * spawnTimer;
        int enemiesSpawned;
        int maxNumberOfEnemies;
        int button_w;
        int button_h;

       QList<QPointF> pointsToFollow;
public slots:
        void spawnEnemy();
        void start();
        void start1();
        void start2();
        void start3();

};

#endif // GAME_H
