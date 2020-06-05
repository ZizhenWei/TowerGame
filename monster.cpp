#include "monster.h"
#include<math.h>
Monster::Monster(QPoint Start,QPoint Target,QString picway):QObject (0),pixmap(picway)
{
    this->starPos=Start;
    this->targetPos=Target;
    this->currentPos=Start;
    this->Pos1=QPoint(820,400);
    this->Pos2=QPoint(760,50);
    this->Pos3=QPoint(480,50);
    this->Pos4=QPoint(380,150);
}
void Monster::draw(QPainter *painter){
    painter->drawPixmap(currentPos,pixmap);

}
void Monster::move(){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"currentPos");
    animation->setDuration(20000);
    animation->setStartValue(starPos);
    animation->setKeyValueAt(0.35,Pos1);
    animation->setKeyValueAt(0.58, Pos2);
    animation->setKeyValueAt(0.75, Pos3);
    animation->setKeyValueAt(0.83, Pos4);
    animation->setEndValue(targetPos);
    animation->start();
}
QPoint Monster::getCurrentPos(){
    return this->currentPos;
}
void Monster::setCurrentPos(QPoint pos){
    this->currentPos=pos;
}
void Monster::changeway(QPoint pos1, QPoint pos2){
    this->starPos=pos1;
    this->targetPos=pos2;
    this->currentPos=pos1;
}
