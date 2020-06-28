#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QAction>
#include <QPushButton>
class MyButton : public QPushButton
{
    Q_OBJECT
public:
    MyButton(QString pix);
    QAction *baseTower;
    QAction *upgradeAct;
    QAction *upgradeAct1;
    QAction *upgradeAct2;
    QAction *destroyAct;
    qreal range() const {return _range;}
    void setRange(qreal r);
    qreal dmg() const {return _dmg;}
    void setDmg(qreal d) {_dmg = d;}
    QString atkBullet() const {return _atkBullet;}
    void setAtkBullet(QString str) {_atkBullet = str;}
    int type() const {return _type;}
    void setType(int tp) {_type = tp;}

private:
    qreal _range;
    qreal _dmg;
    int _type;
    QString _atkBullet;

signals:
    void basic();
    void up1();
    void up2();
    void del();

public slots:
    void baseTowerSlot();
    void upgradeAct1Slot();
    void upgradeAct2Slot();
    void destroyActSlot();
};

#endif // MYBUTTON_H
