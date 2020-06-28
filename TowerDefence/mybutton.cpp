#include "mybutton.h"
#include <QPixmap>
#include <QBitmap>
#include <QMenu>
#include <QDebug>
MyButton::MyButton(QString pix) : QPushButton (0){
    QPixmap pixmap(pix);
    pixmap.setMask(pixmap.mask());
    setFixedSize(pixmap.width(),pixmap.height());
    setStyleSheet("QPushButton{border.0px;}");
    setIcon(pixmap);
    setIconSize(pixmap.size());
//    qDebug() << QSize(pixmap.size());
    setContextMenuPolicy(Qt::ActionsContextMenu);


    baseTower = new QAction(this);
    upgradeAct = new QAction(this);
    upgradeAct1 = new QAction(this);
    upgradeAct2 = new QAction(this);
    destroyAct = new QAction(this);
    baseTower->setText("Basic Tower");
    upgradeAct->setText("Upgrade");
    upgradeAct1->setText("Upgrade Ice");
    upgradeAct2->setText("Upgrade Rock");
    destroyAct->setText("Destory");

    upgradeAct->setEnabled(0);
    destroyAct->setEnabled(0);
    QMenu *upgradeMenu = new QMenu();
    upgradeMenu->addAction(upgradeAct1);
    upgradeMenu->addAction(upgradeAct2);
    upgradeAct->setMenu(upgradeMenu);

    QMenu *towerMenu = new QMenu();
    towerMenu->addAction(baseTower);
    towerMenu->addAction(upgradeAct);
    towerMenu->addAction(destroyAct);

    connect(baseTower, SIGNAL(triggered()), this, SLOT(baseTowerSlot()));
    connect(upgradeAct1, SIGNAL(triggered()), this, SLOT(upgradeAct1Slot()));
    connect(upgradeAct2, SIGNAL(triggered()), this, SLOT(upgradeAct2Slot()));
    connect(destroyAct, SIGNAL(triggered()), this, SLOT(destroyActSlot()));

    setMenu(towerMenu);
}

void MyButton::baseTowerSlot() {
    emit basic();
}

void MyButton::upgradeAct1Slot() {
    emit up1();
}

void MyButton::upgradeAct2Slot() {
    emit up2();
}

void MyButton::destroyActSlot() {
    emit del();
}

void MyButton::setRange(qreal r) {
    _range = r;
}
