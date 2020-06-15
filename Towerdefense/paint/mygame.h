#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include<QPixmap>
#include<QPushButton>
#include<QPainter>
#include"tower.h"
#include<QList>
#include"monster.h"
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
    void addMyObject();
    void addMyObject1();
    void updateScreen();
    void playMusic();
    int cost=100;
    int numMon=0;
private:
    Ui::myGame *uii;
    QList<Tower*> tower_list;
    QList<Monster*> object_list;
    QList<QPoint*> pos_list;
    int score = 0;
    int wave = 0;
signals:

};

#endif // MYWINDOW_H
