#include "widget.h"
#include "ui_widget.h"



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("电子木鱼");
    this->setWindowIcon(QIcon(":/res/yuicon.ico"));
    m_Background_img.load(":/res/background.png");
    this->setFixedSize(m_Background_img.width(),m_Background_img.height());
    //木鱼
    this->m_Muyu=new Muyu;
    m_Muyu->setParent(this);
    connect(this->m_Muyu,&Muyu::sizeSignal,[=](){
       update();
    });
    //显示数字的标签
    this->m_NumLabel=new MyLabel(this);
    m_NumLabel->setParent(this);
    m_NumLabel->move(0,0);
    m_NumLabel->show();
    //音效
    QSound * sound=new QSound(":/res/sound.wav",this);

    //木鱼按钮
    this->m_PressBut=new QPushButton(this);
    this->m_PressBut->setFixedSize(m_Muyu->width()-100,m_Muyu->height());
    this->m_PressBut->setStyleSheet("QPushButton{border:0px;}");
    this->m_PressBut->move(50,this->height()*0.58);
    connect(m_PressBut,&QPushButton::clicked,[=](){
       m_Muyu->choiceAnimation();
       m_NumLabel->changeText();
       sound->play();
       this->sendLabel();
    });

    for(int i=0;i<500;i++)
    {
        m_StrLabelArr[i]=new StrLabel("功 德 + 1");
        m_StrLabelArr[i]->setParent(this);
        m_StrLabelArr[i]->move(0.5*(this->width()-m_StrLabelArr[i]->width()),height()*0.45);
        m_StrLabelArr[i]->hide();
        connect(m_StrLabelArr[i],&StrLabel::moveSignal,[=](){
            m_StrLabelArr[i]->move(m_StrLabelArr[i]->x(),m_StrLabelArr[i]->y()-1);
        });
    }


}

void Widget::sendLabel()
{
    for(int i=0;i<500;i++)
    {
        if(m_StrLabelArr[i]->m_Free)
        {
            m_StrLabelArr[i]->m_Free=false;
            m_StrLabelArr[i]->move(0.5*(this->width()-m_StrLabelArr[i]->width()),height()*0.45);
            m_StrLabelArr[i]->startMoving();
            m_StrLabelArr[i]->show();
            break;
        }
    }
}
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,this->m_Background_img);
    int sizeWidth=m_Muyu->width()*((double)(m_Muyu->num)/100.f);
    int sizeHeight=m_Muyu->height()*((double)(m_Muyu->num)/100.f);
    int locationX=(m_Muyu->width()-sizeWidth)*0.5;
    int locationY=this->height()*0.58+(m_Muyu->height()-sizeHeight)*0.5;
    painter.drawPixmap(locationX,locationY,sizeWidth,sizeHeight,m_Muyu->m_Pixmap);
}


Widget::~Widget()
{
    delete ui;
}
