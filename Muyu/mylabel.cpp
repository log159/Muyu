#include "mylabel.h"


MyLabel::MyLabel(QWidget *parent)
{
    this->setFixedSize(parent->width(),200);
    this->setText(QString::number(this->num));
    //this->setStyleSheet("border:2px solid red;");
    QFont font;
    font.setFamily("黑体");
    font.setPointSize(70);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
    this->setPalette(pa);
    this->setFont(font);
    this->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
}

void MyLabel::changeText()
{
    this->num++;
    this->setText(QString::number(this->num));
}
