#include "widget.h"
#include "ui_widget.h"
#include <QWidget>
#include<QPainter>
#include<QPixmap>
#include<QPushButton>
#include<QPaintEvent>
#include<QDebug>
#include<QBitmap>
#include"mybutton.h"
#include "mygame.h"
#include<QMediaPlayer>
#include<QLabel>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    this->setFixedSize(995,576);
    ui->setupUi(this);
    MyButton *btn=new MyButton(":/buttom.png");
    btn->setMenu(nullptr);
    btn->setParent(this);
    btn->move(40,200);
    btn->setMask(QPixmap(":/buttom.png").mask());
    connect(btn,&MyButton::clicked,this,[=](){
        this->close();
        myGame *scene =new myGame;
        scene->show();
        connect(scene, &myGame::closeWindow, this, [=](){
            scene->close();
        });
    });
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setBackgroundMode(Qt::TransparentMode);
    QPixmap pixmap(":/pika.jpg");
//    QPixmap buttom(":/buttom.jpg");
//    buttom.fill(QColor(0, 0, 0, 0));
    painter.drawPixmap(0,0,995,576,pixmap);
}
