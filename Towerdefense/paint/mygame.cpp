#include "mygame.h"
#include"mybutton.h"
#include "widget.h"
#include "ui_widget.h"
#include <QWidget>
#include<QPainter>
#include<QPixmap>
#include<QPushButton>
#include<QPaintEvent>
#include<QDebug>
#include"tower.h"
#include<QTimer>
#include<QLabel>
#include<QBitmap>
#include<QMediaPlayer>
myGame::myGame(QWidget *parent):QWidget(parent){
    this->setFixedSize(995,576);
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/bgm.mp3"));
    player->setVolume(20);
    player->play();

    int pp[30][2] = {{230,250},{470,190},{720,255},{405,75},{250,125},{650,330},{295,330}};
    QList<MyButton*> towerButtonList;
    for(int i = 0; i < 7; i++) {
        MyButton* tB = new MyButton(":/towerbotton1.png");
        tB->setMask(QPixmap(":/towerbotton1.png").mask());
        tB->setParent(this);
        tB->move(pp[i][0], pp[i][1]);
        connect(tB, &MyButton::clicked, this, [=](){
            if(cost >= 20) {
               tB->close();
               Tower *a_new_tower = new Tower(QPoint(pp[i][0],pp[i][1]),":/pkq1.png");
               tower_list.push_back(a_new_tower);
               cost-=20;
               playMusic();
               update();
            }
        });
        towerButtonList.push_back(tB);

    }
/*
    QTimer *timeobj = new QTimer(this);
    connect(timeobj,&QTimer::timeout,this,[=](){
        myGame::addMyObject();
        wave++;
        setWave(10, 0);
    });
    timeobj->start(5000);
*/
    setWave(10, 0);
 //   if(numMon>3){
 //       timeobj->stop();
 //       QPainter painter(this);
   //     QPixmap pixmap(":/pika.jpg");
  //      painter.drawPixmap(0,0,995,576,pixmap);
  //  }
    QTimer *timerupdate = new QTimer(this);
    connect(timerupdate,&QTimer::timeout,this,&myGame::updateScreen);
    timerupdate->start(50);
    QTimer *timecost =new QTimer(this);
    connect(timecost,&QTimer::timeout,this,[=](){
        cost++;
    });
    timecost->start(1000);
}

myGame::~myGame()
{
}
void myGame::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap gamepic(":/ditu.jpg");
    painter.drawPixmap(0,0,995,576,gamepic);
    foreach(Tower*tower,tower_list){
        tower->draw(&painter);
    }
    foreach(Monster *object,object_list){
        object->draw(&painter);
    }
    painter.setPen(Qt::white);
    QString str = QString("BALANCE: ");
    str += QString::number(cost, 10);
    str += "   SCORE: ";
    str += QString::number(score, 10);
    str += "   WAVE: ";
    str += QString::number(wave, 10);
    painter.drawText(QPoint(100, 50), str);
}

void myGame::addMyObject(){
    Monster *object = new Monster(QPoint(70,400),QPoint(70,150),":/obj1.png");
    object_list.push_back(object);
    object->move();
    numMon++;
    update();
}

void myGame::updateScreen(){
    update();
}
void myGame::playMusic(){
    QMediaPlayer * playerset = new QMediaPlayer;
    playerset->setMedia(QUrl("qrc:/sound/settower.mp3"));
    playerset->setVolume(30);
    playerset->play();
}

void myGame::setWave(int a, int b) {
    QTimer *timeobj = new QTimer(this);
    connect(timeobj,&QTimer::timeout,this,[=](){
        myGame::addMyObject();
        if(numMon >= a) timeobj->stop();
    });
    timeobj->start(5000);
}
