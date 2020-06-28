#ifndef BULLET_H
#define BULLET_H

#include <QWidget>
#include "monster.h"

class Bullet : public QWidget
{
    Q_OBJECT
public:
    explicit Bullet(QWidget *parent = nullptr, QPoint spos = QPoint(0, 0),QPoint tpos = QPoint(0, 0), QString fileName = "", qreal _d = 1);
    void move();
    void draw(QPainter *painter);
    void setSpeed(qreal r);
    QPoint currentPos() const;
    QPoint TargetPos() const;
    QPoint SourcePos() const;
    qreal dmg() const{return _dmg;}
    void setAtkTarget(Monster *m) {_atkTarget = m;}
    Monster* atkTarget() const {return _atkTarget;}

private:
    QPoint sourcePos;
    QPoint targetPos;
    QPoint curPos;
    QPixmap pixmap;
    qreal bulletSpeed;
    qreal _dmg;
    Monster *_atkTarget;

signals:

};

#endif // BULLET_H
