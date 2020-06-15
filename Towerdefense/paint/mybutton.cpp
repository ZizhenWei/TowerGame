#include "mybutton.h"
#include <QPixmap>
#include <QBitmap>
MyButton::MyButton(QString pix) : QPushButton (0){
    QPixmap pixmap(pix);
//    pixmap.fill(QColor(0,0,0,0));
    pixmap.setMask(pixmap.mask());
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border.Opx;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}
