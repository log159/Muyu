#include "muyu.h"
#include <QDebug>
Muyu::Muyu(QWidget *parent) : QWidget(parent)
{

    this->m_Pixmap.load(":/res/muyu.png");
    this->setFixedSize(m_Pixmap.width(),m_Pixmap.height());
    this->m_Timer=new QTimer(this);
    connect(m_Timer,&QTimer::timeout,[=](){
        if(this->select)
        {
            this->num-=10;
            if(num<=min)
            {
                this->select=false;
            }
        }
        else
        {
            this->num+=1;
            if(num>=max)
            {
                num=max;
                this->select=true;
                this->m_Timer->stop();
            }
        }
        emit sizeSignal();

    });
}

void Muyu::choiceAnimation()
{

    this->num=max;

    this->m_Timer->start(10);
}
