#include "widget.h"
#include "ui_widget.h"
#include <QWidget>
#include<QPainter>
#include<QPixmap>
#include<QPushButton>
#include<QPaintEvent>
#include<QDebug>
#include"mybutton.h"
#include "mygame.h"
#include<QMediaPlayer>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    this->setFixedSize(995,576);
    ui->setupUi(this);
    MyButton * btn=new MyButton(":/buttom.png");
    btn->setParent(this);
    btn->move(40,200);
    connect(btn,&MyButton::clicked,this,[=](){
        this->close();
        myGame *scene =new myGame;
        scene->show();
    });
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/pika.jpg");
    QPixmap buttom(":/buttom.jpg");
    painter.drawPixmap(0,0,995,576,pixmap);
}
