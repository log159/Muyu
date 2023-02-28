#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include "muyu.h"
#include <QPushButton>
#include "mylabel.h"
#include "strlabel.h"
#include <QSound>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    QPixmap m_Background_img;

    Muyu * m_Muyu;

    QPushButton * m_PressBut;

    MyLabel * m_NumLabel;

    StrLabel * m_StrLabelArr[500];


    void paintEvent(QPaintEvent *event);

    void sendLabel();


    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
