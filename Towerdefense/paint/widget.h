#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPainter>
#include<QPixmap>
#include<QPushButton>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent*);
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
