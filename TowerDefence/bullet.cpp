#include "bullet.h"
#include <QVector2D>
#include <QPainter>

Bullet::Bullet(QWidget *parent, QPoint spos, QPoint tpos, QString fileName, qreal _d) : QWidget(parent), pixmap(fileName) {
    sourcePos = spos;
    curPos = spos;
    targetPos = tpos;
    _dmg = _d;
}

void Bullet::move() {
    QVector2D vec(targetPos-sourcePos);
    vec.normalize();
    curPos = curPos + vec.toPoint()*bulletSpeed;
//    curPos = curPos + vec.toPoint();
}

void Bullet::draw(QPainter *painter){
    painter->drawPixmap(curPos, pixmap);
}

void Bullet::setSpeed(qreal r) {
    bulletSpeed = r;
}

QPoint Bullet::currentPos() const {
    return curPos;
}

QPoint Bullet::TargetPos() const {
    return targetPos;
}

QPoint Bullet::SourcePos() const {
    return sourcePos;
}
