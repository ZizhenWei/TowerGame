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
    void set_tower1();
    void set_tower2();
    void set_tower3();
    void set_tower4();
    void set_tower5();
    void set_tower6();
    void set_tower7();
    void addMyObject();
    void addMyObject1();
    void updateScreen();
    void playMusic();
    int cost=0;
    int numMon=0;
private:
    Ui::myGame *uii;
    QList<Tower*> tower_list;
    QList<Monster*> object_list;
signals:

};

#endif // MYWINDOW_H
