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
#include<QMediaPlayer>
myGame::myGame(QWidget *parent):QWidget(parent){
    this->setFixedSize(995,576);
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/bgm.mp3"));
    player->setVolume(20);
    player->play();
    MyButton *setTower1 =new MyButton(":/towerbotton1.jpg");
    setTower1->setParent(this);
    setTower1->move(230,250);//ok
    connect(setTower1,&MyButton::clicked,this,[=](){
        setTower1->close();
        myGame::set_tower1();
    });
    MyButton *setTower2 =new MyButton(":/towerbotton1.jpg");
    setTower2->setParent(this);
    setTower2->move(470,190);//ok
    connect(setTower2,&MyButton::clicked,this,[=](){
        setTower2->close();
        myGame::set_tower2();
    });
    MyButton *setTower3 =new MyButton(":/towerbotton1.jpg");
    setTower3->setParent(this);
    setTower3->move(720,255);
    connect(setTower3,&MyButton::clicked,this,[=](){
        setTower3->close();
        myGame::set_tower3();
    });
    MyButton *setTower4 =new MyButton(":/towerbotton1.jpg");
    setTower4->setParent(this);
    setTower4->move(405,75);//ok
    connect(setTower4,&MyButton::clicked,this,[=](){
        setTower4->close();
        myGame::set_tower4();
    });
    MyButton *setTower5 =new MyButton(":/towerbotton1.jpg");
    setTower5->setParent(this);
    setTower5->move(250,125);//ok
    connect(setTower5,&MyButton::clicked,this,[=](){
        setTower5->close();
        myGame::set_tower5();
    });
    MyButton *setTower6 =new MyButton(":/towerbotton1.jpg");
    setTower6->setParent(this);
    setTower6->move(650,330);//ok
    connect(setTower6,&MyButton::clicked,this,[=](){
        setTower6->close();
        myGame::set_tower6();
    });
    MyButton *setTower7 =new MyButton(":/towerbotton1.jpg");
    setTower7->setParent(this);
    setTower7->move(295,330);//ok
    connect(setTower7,&MyButton::clicked,this,[=](){
        setTower7->close();
        myGame::set_tower7();
    });

    QTimer *timeobj = new QTimer(this);
    connect(timeobj,&QTimer::timeout,this,[=](){
        myGame::addMyObject();
    });
    timeobj->start(5000);
 //   if(numMon>3){
 //       timeobj->stop();
 //       QPainter painter(this);
   //     QPixmap pixmap(":/pika.jpg");
  //      painter.drawPixmap(0,0,995,576,pixmap);
  //  }
    QTimer *timerupdate = new QTimer(this);
    connect(timerupdate,&QTimer::timeout,this,&myGame::updateScreen);
    timerupdate->start(50);
  //  QTimer *timecost =new QTimer(this);
//    connect(timecost,&QTimer::timeout,this,[=](){
  //      cost++;
    //});
    //timecost->start(1000);
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
}
void myGame::set_tower1(){
    Tower *a_new_tower = new Tower(QPoint(230,240),":/pkq1.jpg");
    tower_list.push_back(a_new_tower);cost-=20;
    playMusic();
    update();
}
void myGame::set_tower2(){
    Tower *a_new_tower = new Tower(QPoint(470,180),":/pkq1.jpg");
    tower_list.push_back(a_new_tower);cost-=20;
    playMusic();
    update();
}
void myGame::set_tower3(){
    Tower *a_new_tower = new Tower(QPoint(720,245),":/pkq1.jpg");
    tower_list.push_back(a_new_tower);cost-=20;
    playMusic();
    update();
}
void myGame::set_tower4(){
    Tower *a_new_tower = new Tower(QPoint(405,70),":/pkq1.jpg");
    tower_list.push_back(a_new_tower);cost-=20;
    playMusic();
    update();
}
void myGame::set_tower5(){
    Tower *a_new_tower = new Tower(QPoint(250,115),":/pkq1.jpg");
    tower_list.push_back(a_new_tower);cost-=20;
    playMusic();
    update();
}
void myGame::set_tower6(){
    Tower *a_new_tower = new Tower(QPoint(650,320),":/pkq1.jpg");
    tower_list.push_back(a_new_tower);
    cost-=20;
    playMusic();
    update();
}
void myGame::set_tower7(){
    Tower *a_new_tower = new Tower(QPoint(295,330),":/pkq1.jpg");
    tower_list.push_back(a_new_tower);
    cost-=20;
    playMusic();
    update();
}
void myGame::addMyObject(){
    Monster *object = new Monster(QPoint(70,400),QPoint(70,150),":/obj1.jpg");
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
