#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include<QPropertyAnimation>
#include<QPoint>
#include<QPixmap>
#include<QPainter>
class Monster : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint currentPos READ getCurrentPos WRITE setCurrentPos)
public:
    Monster(QPoint Start,QPoint Target,QString picway);
    void draw(QPainter *painter);
    void move();
    QPoint getCurrentPos();
    void setCurrentPos(QPoint pos);
    void changeway(QPoint pos1,QPoint pos2);
    double getPosofstartx(){return starPos.x();}
    double getPosofstarty(){return starPos.y();}
    double getPosoftarx(){return targetPos.x();}
    double getPosoftary(){return targetPos.y();}
private:
    QPoint starPos;
    QPoint targetPos;
    QPoint Pos1;
    QPoint Pos2;
    QPoint Pos3;
    QPoint Pos4;
    QPoint currentPos;
    QPixmap pixmap;
signals:

public slots:
};

#endif // MYOBJECT_H
