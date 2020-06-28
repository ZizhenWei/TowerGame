#include "mygame.h"
#include"mybutton.h"
#include "widget.h"
#include "ui_widget.h"
#include <QWidget>
#include<QPainter>
#include<QPixmap>
#include<QPushButton>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QDebug>
#include<QTimer>
#include<QLabel>
#include<QBitmap>
#include<QAction>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include"bullet.h"
myGame::myGame(QWidget *parent):QWidget(parent){
    this->setFixedSize(995,576);
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/bgm.mp3"));
    player->setVolume(0);
    player->play();
//    QMediaPlaylist* playlist = new QMediaPlaylist(this);
//    playlist->addMedia(QUrl("qrc:/sound/bgm.mp3"));
//    playlist->setCurrentIndex(1);
//    playlist->setPlaybackMode(QMediaPlaylist::Loop);
//    QMediaPlayer* player = new QMediaPlayer;
//    player->setPlaylist(playlist);
//    player->setVolume(10);
//    player->play();

    int pp[30][2] = {{230,250},{470,190},{720,255},{405,75},{250,125},{650,330},{295,330}};
//    QList<MyButton*> towerButtonList;

    for(int i = 0; i < 7; i++) {
        MyButton* tB = new MyButton(":/towerbotton1.png");
        tB->setMask(QPixmap(":/towerbotton1.png").mask());
        tB->setParent(this);
        tB->move(pp[i][0], pp[i][1]);
        connect(tB, &MyButton::basic, this, [=](){
            if(cost >= 20) {
                cost -= 20;
                tB->setRange(150);
                tower_list.push_back(tB);
                tB->setDmg(1);
                tB->setType(0);
                tB->setAtkBullet(":/atk3");
                tB->baseTower->setEnabled(0);
                tB->upgradeAct->setEnabled(1);
                tB->destroyAct->setEnabled(1);
                QPixmap pixmap(":/pkq1.png");
                tB->setMask(pixmap.mask());
                tB->setFixedSize(pixmap.width(), pixmap.height());
                tB->setStyleSheet("QPushButton{border.0px;}");
                tB->setIcon(pixmap);
                tB->setIconSize(pixmap.size());
            }
        });
        connect(tB, &MyButton::up1, this, [=](){
            if(cost >= 40) {
                cost -= 40;
                tB->setAtkBullet(":/atk1");
                tB->setType(1);
                tB->upgradeAct->setEnabled(0);
                QPixmap pixmap(":/pika1.png");
                tB->setMask(pixmap.mask());
                tB->setFixedSize(pixmap.width(), pixmap.height());
                tB->setStyleSheet("QPushButton{border.0px;}");
                tB->setIcon(pixmap);
                tB->setIconSize(pixmap.size());
            }
        });
        connect(tB, &MyButton::up2, this, [=](){
            if(cost >= 40) {
                cost -= 40;
                tB->upgradeAct->setEnabled(0);
                tB->setType(2);
                QPixmap pixmap(":/pika4.png");
                tB->setAtkBullet(":/atk2");
                tB->setMask(pixmap.mask());
                tB->setFixedSize(pixmap.width(), pixmap.height());
                tB->setStyleSheet("QPushButton{border.0px;}");
                tB->setIcon(pixmap);
                tB->setIconSize(pixmap.size());
            }
        });
        connect(tB, &MyButton::del, this, [=](){
//            if(cost >= 20) {
                cost += 15;
                tB->baseTower->setEnabled(1);
                tB->upgradeAct->setEnabled(0);
                tB->destroyAct->setEnabled(0);
                QPixmap pixmap(":/towerbotton1.png");
                tB->setMask(pixmap.mask());
                tB->setFixedSize(pixmap.width(), pixmap.height());
                tB->setStyleSheet("QPushButton{border.0px;}");
                tB->setIcon(pixmap);
                tB->setIconSize(pixmap.size());
                tower_list.removeAt(tower_list.indexOf(tB));
//            }
        });
//        towerButtonList.push_back(tB);
    }

    QTimer *tWave = new QTimer(this);
    connect(tWave, &QTimer::timeout, this, [=](){
        int MonA, MonB, Mon;
        int towerNum[3] = {0};
        Mon = (wave+1) * 2;
        foreach(MyButton *tower, tower_list) {
            towerNum[tower->type()]++;
//            qDebug() << tower->type();
        }
//        qDebug() << towerNum[0] << towerNum[1] << towerNum[2];
        if(towerNum[1] == towerNum[2]) {
            if(wave&1){
                MonA = Mon * 2/3;
                MonB = Mon - MonA;
            }
            else {
                MonB = Mon * 2/3;
                MonA = Mon - MonB;
            }
        }
        else if(towerNum[1] == 0) {
            MonA = Mon;
            MonB = 0;
        }
        else if(towerNum[2] == 0) {
            MonA = 0;
            MonB = Mon;
        }
        else {
            MonA = towerNum[2]*Mon/(towerNum[1]+towerNum[2]);
            MonB = Mon - MonA;
        }
//        tWave->setInterval(5300 * (numMon));
        if(wave < 10){
            setWave(MonA, MonB);
            wave++;
            if(wave == 10)
                flag = 1;
        }
        else {

            tWave->stop();
        }
        tWave->setInterval(2223*(wave+1)*2);
//        qDebug() << wave << numMon << MonA << MonB;
    });

    tWave->start(20000);

    QTimer *timerupdate = new QTimer(this);
    connect(timerupdate,&QTimer::timeout,this,&myGame::updateScreen);
    timerupdate->start(50);
    QTimer *timecost = new QTimer(this);
    connect(timecost,&QTimer::timeout,this,[=](){
        cost+=moneySpeed;
    });
    timecost->start(1000);
    QTimer *atkDuration = new QTimer(this);
    connect(atkDuration, &QTimer::timeout, this, &myGame::attack);
    atkDuration->start(500);
    setMouseTracking(1);

//    menuButton* winBt = new menuButton(":/win.png");
//    menuButton* loseBt = new menuButton(":/lose.png");
    winBt = new MyButton(":/win.png");
    loseBt = new MyButton(":/lose.png");
    winBt->setParent(this);
    winBt->move(200, 60);
    winBt->setMask(QPixmap(":/win.png").mask());
    winBt->setMenu(nullptr);
    winBt->setVisible(0);
    loseBt->setParent(this);
    loseBt->move(250, 140);
    loseBt->setMask(QPixmap(":/lose.png").mask());
    loseBt->setMenu(nullptr);
    loseBt->setVisible(0);
    connect(loseBt, &QPushButton::clicked, this, [=](){
        emit closeWindow();
    });
    connect(winBt, &QPushButton::clicked, this, [=](){
        emit closeWindow();
    });
}

myGame::~myGame()
{
}
void myGame::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap gamepic(":/ditu.jpg");
    painter.drawPixmap(0,0,995,576,gamepic);

    foreach(Monster *object,object_list){
        if(object->getCurrentPos() != QPoint(object->getPosoftarx(), object->getPosoftary()))
            object->draw(&painter);
        else {
            _HP--;
            object_list.removeAt(object_list.indexOf(object));
        }
    }
    foreach(Bullet *bullet, bullet_list) {
//        qDebug() << bullet->currentPos() << bullet->TargetPos();
        QVector2D vec(bullet->currentPos()-bullet->SourcePos());
        QVector2D rg(bullet->TargetPos()-bullet->SourcePos());
        if(vec.length() < rg.length())
            bullet->draw(&painter);
        else {
            int index = 0;
            if(bullet->atkTarget() != nullptr)
                index = object_list.indexOf(bullet->atkTarget());
//            qDebug() << index << object_list.size();
            if(index != -1) {
                object_list.at(index)->atkHP(bullet->dmg());
                if(object_list.at(index) != nullptr && object_list.at(index)->HP() == 0) {
                    object_list.removeAt(index);
                    score+=10;
                    cost+=10;
                }
            }
            bullet_list.removeAt(bullet_list.indexOf(bullet));
        }
    }
    QPen _pen = painter.pen();
    _pen.setColor(Qt::white);
    _pen.setWidth(4);
    painter.setPen(_pen);
    QString str = QString("BALANCE: ");
    str += QString::number(cost, 10);
    str += "   SCORE: ";
    str += QString::number(score, 10);
    str += "   WAVE: ";
    str += QString::number(wave, 10);
    str += "/10   HP: ";
    str += QString::number(_HP, 10);
    painter.drawText(QPoint(100, 50), str);
//    if(atkRect != nullptr) {
//        painter.drawRect(*atkRect);
//        qDebug() << cursor().pos() << atkRect->contains(cursor().pos());
//    }
    if(atkRect != nullptr /*&& atkRect->contains(cursor().pos())*/) {
//        qDebug() << *atkRect;
        _pen.setWidth(6);
        painter.setPen(_pen);
        painter.drawEllipse(*atkRect);
    }
//    painter.drawEllipse(atkRect->center(), 150, 150);
}

void myGame::addMyObject(QString fileName, int type){
    Monster *object = new Monster(QPoint(70,400),QPoint(70,170),fileName,type);
    object_list.push_back(object);
    object->move();
    update();
}

void myGame::updateScreen(){
    foreach(Bullet *bullet, bullet_list) {
        bullet->move();
    }
    if(_HP > 0 && flag == 1 && loseBt->isVisible() == 0 && object_list.empty()) {
        winBt->setVisible(1);
        update();
    }
    if(_HP <= 0 && winBt->isVisible() == 0) {
        loseBt->setVisible(1);
        update();
    }
    update();
}

void myGame::playMusic(){
    QMediaPlayer * playerset = new QMediaPlayer;
    playerset->setMedia(QUrl("qrc:/sound/settower.mp3"));
    playerset->setVolume(20);
    playerset->play();
}

void myGame::attack() {
    foreach(MyButton *tower, tower_list) {
        foreach(Monster *monster, object_list) {
            QVector2D dist(monster->getCurrentPos() - tower->pos());
            if(dist.length() <= (tower->range())){
                Bullet *bullet = new Bullet(this, tower->pos(), monster->getCurrentPos(), tower->atkBullet(), tower->dmg()*atkConst[tower->type()][monster->type()]);
                bullet->setSpeed(22);
                bullet->setAtkTarget(monster);
                bullet_list.push_back(bullet);
                break;
            }
        }
    }
}

void myGame::mouseMoveEvent(QMouseEvent *event) {
//    qDebug() << cursor().pos();
    foreach(MyButton *tower, tower_list) {
        BtRect = new QRect((int)tower->pos().x()-2, (int)tower->pos().y()-2, 50, 50);
        //        qDebug() << *atkRect;
        //        atkRect_list.push_back(atkRect);
        if(BtRect->contains(event->pos())){
            atkRect = new QRect((int)tower->pos().x()-130, (int)tower->pos().y()-130, 300, 300);
            update();
            break;
        }
        else
            atkRect = nullptr;
    }
}

void myGame::setWave(int a, int b) {
    QTimer *timeobj1 = new QTimer(this);
    QTimer *timeobj2 = new QTimer(this);
    numMonA = 0;
    numMonB = 0;
    connect(timeobj1,&QTimer::timeout,this,[=](){
        if(numMonA < a) {
            addMyObject(":/1.png", 0);
            numMonA++;
        }
        else
            timeobj1->stop();
    });
    connect(timeobj2,&QTimer::timeout,this,[=](){
        if(numMonB < b) {
            addMyObject(":/2.png", 1);
            numMonB++;
        }
        else
            timeobj2->stop();
    });

    timeobj1->start(1999);
    timeobj2->start(2223);
}
