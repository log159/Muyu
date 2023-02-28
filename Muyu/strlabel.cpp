#include "strlabel.h"

StrLabel::StrLabel(QString str)
{

    this->m_Str=str;
    this->setFixedSize(150,50);
    this->setText(str);
    //this->setStyleSheet("border:2px solid red;");

    QFont font;
    font.setFamily("黑体");
    font.setPointSize(20);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
    this->setPalette(pa);
    this->setFont(font);
    this->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    this->m_Free=true;
    m_MoveTimer=new QTimer(this);
    connect(m_MoveTimer,QTimer::timeout,[=](){
        this->moving();
    });
}

void StrLabel::moving()
{
    if(m_Free)
    {
        return;
    }
    m_MoveNum++;
    if(m_MoveNum>=100)
    {
        m_MoveNum=0;
        this->hide();
        m_Free=true;
        this->m_MoveTimer->stop();
    }
    emit moveSignal();

}

void StrLabel::startMoving()
{
    m_MoveTimer->start(10);
}
