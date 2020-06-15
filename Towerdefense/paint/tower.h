#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include<QPoint>
#include<QPixmap>
#include<QMenu>
class Tower : public QObject
{
    Q_OBJECT
public:
    Tower(QPoint pos,QString pixFileName);
    void draw(QPainter *painter);
private:
    QPoint _pos;
    QPixmap pixmap;
    QMenu* menu1;
    QMenu* menu2;

signals:

public slots:
//    void toLightSlot();
//    void toIceSlot();
//    void upgradeSlot();
//    void deleteSlot();
};

#endif // TOWER_H
