#include "game.h"
#include <QGraphicsScene>
#include "tower.h"
#include "bullet.h"
#include "enemy.h"
#include "ally.h"
#include <QTimer>
#include <QGraphicsLineItem>
#include <QPen>
#include "tower2.h"
#include "bullet2.h"
#include "button.h"
#include <QGraphicsTextItem>
#include "ally1.h"
#include "ally2.h"
#include "ally3.h"
#include <iostream>


Game::Game(): QGraphicsView(){
    // create a scene




    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);

    // set the scene
    setScene(scene);









    // create a tower
    Tower * t = new Tower();
    t->setPos(10,250);


    Tower2 * m = new Tower2();
    m->setPos(700,230);


    // create the play button
    Button* playButton = new Button(QString("A1"));
    int bxPos = 50;
    int byPos = 475;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    Button* playButton1 = new Button(QString("A2"));
    int bxPos1 = 150;
    int byPos1 = 475;
    playButton1->setPos(bxPos1,byPos1);
    connect(playButton1,SIGNAL(clicked()),this,SLOT(start1()));
    scene->addItem(playButton1);

    Button* playButton2 = new Button(QString("A3"));
    int bxPos2 = 250;
    int byPos2 = 475;
    playButton2->setPos(bxPos2,byPos2);
    connect(playButton2,SIGNAL(clicked()),this,SLOT(start2()));
    scene->addItem(playButton2);

    Button* playButton3 = new Button(QString("A4"));
    int bxPos3 = 350;
    int byPos3 = 475;
    playButton3->setPos(bxPos3,byPos3);
    connect(playButton3,SIGNAL(clicked()),this,SLOT(start3()));
    scene->addItem(playButton3);


    // add the tower to scene
    scene->addItem(t);
    scene->addItem(m);
    // alter window
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    spawnTimer = new QTimer(this);
    enemiesSpawned = 0;
    maxNumberOfEnemies = 0;
  pointsToFollow << QPointF(550,300) << QPointF(-5000,300) ;

    createEnemies(100);


}


void Game::createEnemies(int numberOfEnemies){
    enemiesSpawned = 0;
    maxNumberOfEnemies = numberOfEnemies;
    connect(spawnTimer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    spawnTimer->start(2000);
}

void Game::spawnEnemy(){
    // spawn an enemy
    Enemy * enemy = new Enemy(pointsToFollow);
    enemy->setPos(pointsToFollow[0]);
    scene->addItem(enemy);
    enemiesSpawned += 1;

    if (enemiesSpawned >= maxNumberOfEnemies){
        spawnTimer->disconnect();
    }
}
void Game::start(){

    Ally * ally1 = new Ally();
    ally1->setPos(200,270);
    scene->addItem(ally1);

}
void Game::start1(){

    Ally1 * ally1 = new Ally1();
    ally1->setPos(200,270);
    scene->addItem(ally1);

}
void Game::start2(){

    Ally2 * ally1 = new Ally2();
    ally1->setPos(200,270);
    scene->addItem(ally1);

}
void Game::start3(){

    Ally3 * ally1 = new Ally3();
    ally1->setPos(200,270);
    scene->addItem(ally1);

}





