#include "tower.h"
#include<QPainter>
Tower::Tower(QPoint pos,QString pixFileName): QObject(0),pixmap(pixFileName)
{
    _pos=pos;
}
void Tower::draw(QPainter *painter){
    painter->drawPixmap(_pos,pixmap);
}
