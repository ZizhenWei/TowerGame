#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include<QPixmap>
#include<QPushButton>
#include<QPainter>
#include<QList>
#include"monster.h"
#include"mybutton.h"
#include"bullet.h"
namespace Ui {
class myGame;
}

class myGame : public QWidget
{
    Q_OBJECT
public:
    explicit myGame(QWidget *parent = nullptr);
    ~myGame();
    void paintEvent(QPaintEvent*);
    void setWave(int a, int b);
    void set_tower();
    void addMyObject(QString fileName, int type);
    void addMyObject1();
    void updateScreen();
    void playMusic();
    void attack();
    void mouseMoveEvent(QMouseEvent *event);
//    menuButton* winBt;
//    menuButton* loseBt;
    int cost=100;
private:
    Ui::myGame *uii;
    QList<MyButton*> tower_list;
    QList<Monster*> object_list;
    QList<QPoint*> pos_list;
    QList<Bullet*> bullet_list;
    QList<QRect*> atkRect_list;
    QRect* atkRect = nullptr;
    QRect* BtRect = nullptr;
    MyButton* curTower;
    MyButton* winBt;
    MyButton* loseBt;
    bool flag = 0;
    qreal atkConst[3][2]={{0.7, 0.7}, {2, 0.4}, {0.4, 2}};
//    menuButton* winBt;
//    menuButton* loseBt;
    int _HP = 20;
    int score = 0;
    int wave = 0;
    int moneySpeed = 4;
    int numMonA = 0;
    int numMonB = 0;
    int numMon;
    void win();
    void lose();
    enum Mode{earth, fire};
signals:
    void closeWindow();
};

#endif // MYWINDOW_H
