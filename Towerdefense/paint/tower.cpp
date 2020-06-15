#include "tower.h"
#include<QPainter>
#include<QBitmap>
Tower::Tower(QPoint pos,QString pixFileName): QObject(0),pixmap(pixFileName)
{
    pixmap.setMask(pixmap.mask());
    _pos=pos;
}
void Tower::draw(QPainter *painter){
    painter->setBackgroundMode(Qt::TransparentMode);
    painter->drawPixmap(_pos,pixmap);
}
